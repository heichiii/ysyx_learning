#include "nvboard.h"
#include "Vlight.h"

void nvboard_bind_all_pins(TOP_NAME *top);
Vlight *waterfull;
void single_cycle()
{
    waterfull->clk = 0;
    waterfull->eval();
    waterfull->clk = 1;
    waterfull->eval();
}

void reset(int n)
{
    waterfull->rst = 1;
    while (n-- > 0)
        single_cycle();
    waterfull->rst = 0;
}
int main(int argc, char **argv)
{
    waterfull = new Vlight;
    nvboard_bind_all_pins(waterfull);
    nvboard_init();

    reset(10);
    while (1)
    {
        single_cycle();
        nvboard_update();
    }
    nvboard_quit();

    return 0;
}