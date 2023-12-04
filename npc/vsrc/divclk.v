module divclk(
  input clk_50MHz,
  output reg clk_1Hz
);

reg [25:0] count;

always @(posedge clk_50MHz) begin
  if (count == 5000000 - 1) begin
    count <= 0;
    clk_1Hz <= ~clk_1Hz;
  end else begin
    count <= count + 1;
  end
end

endmodule
