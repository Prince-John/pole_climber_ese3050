#include <stdio.h>

#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/int32.h>
#include <rmw_microros/rmw_microros.h>

#include "pico/stdlib.h"
#include "pico_uart_transports.h"
#include "hardware/pwm.h"



const uint LED_PIN = 1;
const uint MOTOR_PWM_PIN = 16; 
int main()
{
        
    gpio_set_function(MOTOR_PWM_PIN, GPIO_FUNC_PWM);

    // slice num is the pwm line connected internally to our gpio pin
    uint slice_num = pwm_gpio_to_slice_num(MOTOR_PWM_PIN);

    //setting wrap value
    pwm_set_wrap(slice_num, 1500);

    // this line will set the duty cycle. PICO has two PWM channels, here I'm using chan A. duty cycle = (1/wrap value){ 1 cycle high set in this line};
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 20);


    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    pwm_set_enabled(slice_num, true);

    while(true){

    gpio_put(LED_PIN, 1);
    sleep_ms(1000);


    for(int i = 20; i<=1400; i++){

        pwm_set_chan_level(slice_num, PWM_CHAN_A, i);
        sleep_ms(5);
    }     

    for(int i = 1400; i>=20; i--){

        pwm_set_chan_level(slice_num, PWM_CHAN_A, i);
        sleep_ms(5);
    }     


    gpio_put(LED_PIN, 0);
    sleep_ms(1000);

    }

}
