#include "nvboard.h"
#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
void nvboard_bind_all_pins(TOP_NAME* top);
int main(int argc ,char** argv)
{
	Vtop* swi=new Vtop;
	nvboard_bind_all_pins(swi);
	nvboard_init();
	
	while (1)
	{


		// 仿真一个时间步
		
		nvboard_update();
		swi->eval();
	}
	
	nvboard_quit();






}
