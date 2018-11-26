#ifndef SRC_TASKS_INIT_H_
#define SRC_TASKS_INIT_H_
#include "FreeRTOS.h"
#include "semphr.h"

extern SemaphoreHandle_t gpio_port_n_write;

void InitTasks(void);

void RunTasks(void);

#endif /* SRC_TASKS_INIT_H_ */
