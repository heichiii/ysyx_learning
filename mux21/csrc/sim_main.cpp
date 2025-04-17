#include "nvboard.h"
#include "Vmux41.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
void nvboard_bind_all_pins(TOP_NAME *top);
int main(int argc, char **argv)
{
    Vmux41 *mux = new Vmux41;
    nvboard_bind_all_pins(mux);
    nvboard_init();

    while (1)
    {

        // 仿真一个时间步

        nvboard_update();
        mux->eval();
    }

    nvboard_quit();
}
