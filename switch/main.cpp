#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
int main()
{
	Vtop* swi=new Vtop;
	
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	swi->trace(tfp, 99);
	tfp->open("waveform.vcd");

	 // 打印欢迎信息
	 std::cout << "Starting simulation..." << std::endl;
	 std::cout << "a b | f" << std::endl;
	 std::cout << "--------" << std::endl;
 
	 // 测试用例
	 for (int i = 0; i < 8; i++) {
		 // 生成所有可能的 a/b 组合 (00, 01, 10, 11)
		 swi->a = (i >> 1) & 1;
		 swi->b = i & 1;
 
		 // 仿真一个时间步
		 swi->eval();
		 tfp->dump(i * 10);  // 记录波形
 
		 // 打印当前输入输出
		 std::cout << (int)swi->a << " " 
				   << (int)swi->b << " | " 
				   << (int)swi->f << std::endl;
	 }
 
	 // 清理
	 tfp->close();
	 delete swi;
	 delete tfp;
 
	 std::cout << "Simulation completed! View waveform with: gtkwave waveform.vcd" << std::endl;
	 return 0;
}

