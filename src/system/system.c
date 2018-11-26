#include <stdint.h>
#include <stdbool.h>
#include "driverlib/sysctl.h"
#include "driverlib/debug.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "system/system.h"

void InitSystem()
{
    uint32_t output_clock_rate_hz;
    uint32_t clock_config = SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480;
    output_clock_rate_hz = ROM_SysCtlClockFreqSet(clock_config, SYSTEM_CLOCK);
    ASSERT(output_clock_rate_hz == SYSTEM_CLOCK);
}
