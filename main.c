/******************************************
Name: Jonathan (John) Luna
UCFID: 5458486
Course: EEE 5862
Assignment: Application 1
*******************************************/

#include <stdio.h>
#include <time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_15

void DataTask(void *pvParameters){
    int AtmosphericTemperature = 0;
    int Humidity = 0;
    int SeaSurfaceTemperature = 0;
    int Co2Emissions = 0;
    unsigned long PastTimeDataTask = 0;
    unsigned long CurrentTimeDataTask = 0;
    unsigned long PeriodDataTask = 0;
    srand(time(NULL));
    while (1){
        AtmosphericTemperature = 42 + rand() % 12;
        Humidity = 80 +rand() % 16;
        SeaSurfaceTemperature = -5 + rand() % 6;
        Co2Emissions = 30 + rand() % 8;
        CurrentTimeDataTask =(xTaskGetTickCount()*portTICK_PERIOD_MS);

        printf("Average Telemetry Data obtained \n Atmospheric Temperature: %d Celsius \t Humidity: %d%% \t Sea Surface Temperature: %d Celsius \t CO2 Emissions: %d Tg C, Elapsed time is: %lu ms\n",
        AtmosphericTemperature, Humidity, SeaSurfaceTemperature, Co2Emissions,CurrentTimeDataTask);

        PeriodDataTask = CurrentTimeDataTask-PastTimeDataTask;
        PastTimeDataTask = CurrentTimeDataTask;

        printf("The period for Data Task is : %lu ms\n",PeriodDataTask);

        vTaskDelay(pdMS_TO_TICKS(10000));
    }
}

void TelemetryTask(void *pvParameters){
    unsigned long PastTimeTelemetryTask = 0;
    unsigned long CurrentTimeTelemetryTask = 0;
    unsigned long PeriodTelemetryTask = 0;
        while(1){
            CurrentTimeTelemetryTask = (xTaskGetTickCount()*portTICK_PERIOD_MS);
            gpio_set_level(LED_PIN,0);
            printf("Telemetry Calculating, Elapsed Time is: %lu ms\n",CurrentTimeTelemetryTask);
            vTaskDelay(pdMS_TO_TICKS(250));

            CurrentTimeTelemetryTask = (xTaskGetTickCount()*portTICK_PERIOD_MS);
            gpio_set_level(LED_PIN,1);
            printf("Telemetry Data sent, Elasped Time is: %lu ms\n",CurrentTimeTelemetryTask);
            PeriodTelemetryTask = CurrentTimeTelemetryTask-PastTimeTelemetryTask;
            PastTimeTelemetryTask = CurrentTimeTelemetryTask;
             printf("The period for a full blink operation is: %lu ms\n",PeriodTelemetryTask);
            vTaskDelay(pdMS_TO_TICKS(250));          
        }
}

void app_main() {
 gpio_reset_pin(LED_PIN);
 gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

 xTaskCreate(TelemetryTask, "TelemetryTask", 2048, NULL, 1, NULL);
 xTaskCreate(DataTask, "DataTask", 2048, NULL, 1, NULL);
}