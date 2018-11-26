#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/adc.h"

#include "tasks/sensor.h"

#define ADC0_SS 3;

#define ADC1_SS 2;

void InitADCPins(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);

    while(
        !SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE) ||
        !SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0)
    );

    GPIOPinTypeADC(GPIO_PORTE_AHB_BASE, GPIO_PIN_3 | GPIO_PIN_2);

    ADCSequenceConfigure(ADC0_BASE, 2, ADC_TRIGGER_PROCESSOR, 0);
    ADCSequenceStepConfigure(ADC0_BASE, 2, 0, ADC_CTL_CH0);
    ADCSequenceStepConfigure(ADC0_BASE, 2, 1, ADC_CTL_CH1 | ADC_CTL_IE | ADC_CTL_END);
    ADCSequenceEnable(ADC0_BASE, 2);
    ADCIntClear(ADC0_BASE, 2);
}

void GetADCSamples (uint32_t* adcReads)
{
    ADCProcessorTrigger(ADC0_BASE, 2);
    while(!ADCIntStatus(ADC0_BASE, 2, false)) {}

    ADCIntClear(ADC0_BASE, 2);

    ADCSequenceDataGet(ADC0_BASE, 2, adcReads);
}

void ReadSensorsTask(void *pvParameters)
{
    InitADCPins();
    uint32_t adcReads[2];
    while(1)
    {
        GetADCSamples(adcReads);
    };
}
