
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"




#define LED_PIN  2
#define BTN_PIN  0 //Button Pin

void app_main(void)
{
    gpio_reset_pin(LED_PIN); //First reset the pin
    gpio_reset_pin(BTN_PIN);

    gpio_set_direction(LED_PIN,GPIO_MODE_OUTPUT); //setting o/p direction
    gpio_set_direction(BTN_PIN,GPIO_MODE_INPUT);
	
    gpio_set_pull_mode(BTN_PIN, GPIO_PULLUP_ONLY);

    while(1)
    {
       int button_state = gpio_get_level(BTN_PIN);
	
	if (button_state==0) //Button Pressed
	{
	 gpio_set_level(LED_PIN,1); //Turn ON LED
	
	}
	else
	{
	gpio_set_level(LED_PIN,0); //Turn OFF LED
	}
    }
	
}