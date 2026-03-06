#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"


#define LED_PIN  2
void app_main(void)
{
    gpio_reset_pin(LED_PIN); //First reset the pin
    gpio_set_direction(LED_PIN,GPIO_MODE_OUTPUT); //setting o/p direction
    while(1)
    {
        gpio_set_level(LED_PIN,1); //Turn on LED

        vTaskDelay(1000/portTICK_PERIOD_MS); //delay of 1 sec
        gpio_set_level(LED_PIN,0); //Turn OFF LED
        vTaskDelay(1000/portTICK_PERIOD_MS); 
    }

}
