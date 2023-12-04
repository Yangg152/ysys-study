#include <nvboard.h>
#include <Vtop.h>


static TOP_NAME dut;

void nvboard_bind_all_pins(Vtop* top);

static void reset(int n) {
  dut.rst = 1;
  while (n -- > 0);
  dut.rst = 0;
}

int main() {
  nvboard_bind_all_pins(&dut);
  nvboard_init();

  reset(10);

  while(1) {
    nvboard_update();
    dut.eval();
  }
}
