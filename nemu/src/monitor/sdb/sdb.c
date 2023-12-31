/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <memory/paddr.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_help(char *args);

static int cmd_si(char *args);

static int cmd_info(char *args);

static int cmd_x(char *args);

static int cmd_p(char *args);

static int cmd_w(char *args);

static int cmd_d(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "si", "Pause the program after executing N instructions in one step,When N is not given, it defaults to 1", cmd_si },
  { "info", "Print program status", cmd_info },
  { "x", "Find the value of the expression EXPR and use the result as the starting memory address, output N consecutive 4 bytes in hexadecimal format", cmd_x },
  { "p", "Calculate the value of the expression", cmd_p },
  { "w", "Set up monitoring points", cmd_w },
  { "d", "Delete monitoring point with serial number N", cmd_d },


  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

static int cmd_si(char *args) {
  char *arg = strtok(NULL, " ");
  int step = 0;
  if(arg == NULL) {
    step = 1 ;
  } else {
    step = atoi(arg);
  }

  if(step < -1) {
    printf("Error, N is an integer greater than or equal to -1\n");  
    return 0; 
  }
  cpu_exec(step);

  return 0;
}

static int cmd_info(char *args) {
  char *arg = strtok(NULL, " ");
  if(arg == NULL)
    printf("No args.\n");
  else if(strcmp(arg, "r") == 0)
    isa_reg_display();
  else if(strcmp(arg, "w") == 0)
    sdb_watchpoint_display();

  return 0;
}

static int cmd_x(char *args) {
  char *N = strtok(NULL," ");  
  char *EXPR = strtok(NULL," ");  
  int len;  
  paddr_t address;  
    
  sscanf(N, "%d", &len);  
  sscanf(EXPR, "%x", &address);  
    
  int i;
  for(i = 0; i < len; i ++){  
      printf("0x%08x:",address);  
      //if(address >= 0x80000000) 
      printf("%08x ",paddr_read(address,4));  
      address += 4;  
      printf("\n");  
  }  

  return 0;
}

static int cmd_p(char *args) {
  if(args == NULL)
    printf("No args.\n");
  else {
    bool success = false;
    extern bool outputflag;
    word_t result = expr(args, &success);
        //检查结果
    if (success) {
      if(outputflag == false){
        printf("Expression result: %u\n", result);
      } else {
        printf("Expression result: 0x%08x\n", result);
      }
    } else {
        printf("Expression parsing failed: %s\n", args);
    }
  }
  return 0;
}

static int cmd_w(char *args) {
  if(args == NULL)
    printf("No args.\n");
  else {
    create_watchpoint(args);
  }

  return 0;
}

static int cmd_d(char *args) {
  if(args == NULL)
    printf("No args.\n");
  else {
    int num = atoi(args);
    delete_watchpoint(num);
  }

  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return ; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
