#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "queue.h"

#include "tasks/init.h"
#include "tasks/sensor.h"

SemaphoreHandle_t gpio_port_n_write;

void InitTasks(void)
{
    gpio_port_n_write = xSemaphoreCreateMutex();

    xTaskCreate(ReadSensorsTask, (const portCHAR *)"Read Sensors", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
}

void RunTasks(void)
{
    vTaskStartScheduler();
}
