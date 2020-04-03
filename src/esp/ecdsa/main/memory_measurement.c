#include "memory_measurement.h"
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_heap_caps.h>

#ifndef MEM_MEASUREMENT
    #define MEM_MEASUREMENT 0
#endif

static uint8_t ucParameterToPass = 0;
static TaskHandle_t xHandle = NULL;
static size_t internalMemSize = 0;
static size_t externalMemSize = 0;

void vTaskCode( void * pvParameters )
{
    for( ;; )
    {
        printf("In: %d Ex: %d\n",   internalMemSize - heap_caps_get_free_size(MALLOC_CAP_INTERNAL),
                                    externalMemSize - heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
    }
}

void startMemoryMeasurement()
{
    if (!MEM_MEASUREMENT)
    {
        return;
    }

    externalMemSize = heap_caps_get_total_size(MALLOC_CAP_SPIRAM);
    internalMemSize = heap_caps_get_total_size(MALLOC_CAP_INTERNAL);

    printf("Total - Internal: %d, External: %d\n", internalMemSize, externalMemSize); 

    xTaskCreate( vTaskCode, "MemoryMeasur", 5*1024, &ucParameterToPass, tskIDLE_PRIORITY, &xHandle );
    configASSERT( xHandle );
}

void endMemoryMeasurement()
{
    if( xHandle != NULL )
    {
        vTaskDelete( xHandle );
    }
}