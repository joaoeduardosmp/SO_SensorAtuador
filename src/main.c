#include <stdint.h>
#include <stdbool.h>

#include "system/system.h"
#include "tasks/init.h"

int main(void)
{
    InitSystem();
    InitTasks();
    RunTasks();
    return 0;
}

void __error__(char *pcFilename, uint32_t ui32Line)
{
    while (1) {}
}
