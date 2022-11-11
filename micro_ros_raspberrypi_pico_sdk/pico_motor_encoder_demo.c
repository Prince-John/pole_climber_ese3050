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
const uint ENCODER_B_PIN = 19;
const uint ENCODER_A_PIN = 18;
const uint MOTOR_PWM_PIN = 16; 


long motor_a_count = 0;
long last_a_count = 0;

void gpio_callback(){

    motor_a_count++;
    

}

void print_speed(){

    //uint a = motor_a_count - last_a_count;
    last_a_count =  motor_a_count;
    double a = motor_a_count;

    double rotations = motor_a_count/2800.0; 
    
    printf("DEMO file for motor encoder, current count: %d, current rotations: %f rotations \r",   motor_a_count, rotations);

    
}



int main()
{
    motor_a_count =0 ;
    stdio_init_all();
    
    gpio_set_irq_enabled_with_callback(ENCODER_A_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &gpio_callback);
    gpio_set_irq_enabled(ENCODER_B_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true);



    gpio_set_function(MOTOR_PWM_PIN, GPIO_FUNC_PWM);
    gpio_set_function(MOTOR_PWM_PIN, GPIO_FUNC_PWM);

    // slice num is the pwm line connected internally to our gpio pin
    uint slice_num = pwm_gpio_to_slice_num(MOTOR_PWM_PIN);

    //setting wrap value
    pwm_set_wrap(slice_num, 1500);

    // this line will set the duty cycle. PICO has two PWM channels, here I'm using chan A. duty cycle = (1/wrap value){ 1 cycle high set in this line};
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 0);


    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    pwm_set_enabled(slice_num, true);
    motor_a_count = 0;
    double temp = 0.0;
    int speed = 200;
    while(true){

        gpio_put(LED_PIN, 1);
        sleep_ms(5);


        // rotation 10 times
        temp = motor_a_count/2800.0;
        printf("rotations = %f \r", temp);
        if(temp<10){
            pwm_set_chan_level(slice_num, PWM_CHAN_A, speed);
        }
        else{
            pwm_set_chan_level(slice_num, PWM_CHAN_A, 0);
            sleep_ms(2000);
            speed = speed + 500;
            motor_a_count = 0;
        }

    }

}

