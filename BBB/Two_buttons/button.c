#include "../inc/bbb_regs.h"
#include "../inc/funcs.h"
#include <stdint.h>

//local static variable to determine the current active mode, altered by the function "alter_mode"
static int current_mode = 0;

//local static variable to determine the recent status of the button, altered by the function "alter_mode"
static int button1_pressed_before = 0;
static int button2_pressed_before = 0;

// Alternate between different ways to blink the internal leds
void switch_modes(int mode){
    switch (mode){

        //Case 0: Led's stay inactive.
        case 0:

        for(int i = 21; i<=24; i++){
            gpio_low(GPIO1_BASE, i);
        }
        gpio_low(GPIO1_BASE, 16);

        break;

        //Case 1: Leds activate in a sequence.
        case 1:

        // Activates all leds consecutively
        for(int i = 21; i<=24; i++){
            gpio_high(GPIO1_BASE, i);
            delay(1000000, GPIO2_BASE, 9, 10); if(mode != current_mode) return;
        }
        gpio_high(GPIO1_BASE, 16);
        delay(1000000, GPIO2_BASE, 9, 10); if(mode != current_mode) return;
        

        // Deactivates all leds consecutively
        for(int i = 21; i<=24; i++){
            gpio_low(GPIO1_BASE, i);
            delay(1000000, GPIO2_BASE, 9, 10); if(mode != current_mode) return;
        }
        gpio_low(GPIO1_BASE, 16);
        delay(1000000, GPIO2_BASE, 9, 10); if(mode != current_mode) return;
       
        break;

        //Case 2: Alternates between blinking even leds (0,2) and odd leds (1,3)
        case 2:

        // Activate/Deactivate even leds
        for(int i = 21; i<=23; i+=2){
            gpio_high(GPIO1_BASE, i);
            delay(1000000, GPIO2_BASE, 9, 10); if(mode != current_mode) return;
        }
        gpio_high(GPIO1_BASE, 16);
        delay(1000000, GPIO2_BASE, 9, 10); if(mode != current_mode) return;

        for(int i = 21; i<=23; i+=2){
            gpio_low(GPIO1_BASE, i);
            delay(1000000, GPIO2_BASE, 9, 10); if(mode != current_mode) return;
        }
        gpio_low(GPIO1_BASE, 16);
        delay(1000000, GPIO2_BASE, 9, 10); if(mode != current_mode) return;

        // Activate/Deactivate odd leds
        for(int i = 22; i<=24; i+=2){
            gpio_high(GPIO1_BASE, i);
            delay(1000000, GPIO2_BASE, 9, 10); if(mode != current_mode) return;
        }
        for(int i = 22; i<=24; i+=2){
            gpio_low(GPIO1_BASE, i);
            delay(1000000, GPIO2_BASE, 9, 10); if(mode != current_mode) return;
        }
        
        break;

        //Case 3: Activates/Deactivates all leds instantly
        case 3:

        //Activates all leds at the "same" time
        for(int i = 21; i<=24; i++){
            gpio_high(GPIO1_BASE, i);
        }
        gpio_high(GPIO1_BASE, 16);
        delay(1000000, GPIO2_BASE, 9, 10); if(mode != current_mode) return;

        //Deactivate all leds at the "same" time
        for(int i = 21; i<=24; i++){
            gpio_low(GPIO1_BASE, i);
        }
        gpio_low(GPIO1_BASE, 16);
        delay(1000000, GPIO2_BASE, 9, 10); if(mode != current_mode) return;

        break;
    }
}

// Function to detectate alterations in the button status and with that, alternate the current mode
void alter_mode(uint32_t buttons_gpio_base, int button1_pin, int button2_pin){

    int button1_pressed = gpio_in_true(buttons_gpio_base, button1_pin); // gpio 2_9
    int button2_pressed = gpio_in_true(buttons_gpio_base, button2_pin); // gpio 2_10

    int clicked_now_button1 = (button1_pressed && !button1_pressed_before);
    int clicked_now_button2 = (button2_pressed && !button2_pressed_before);

    if(clicked_now_button1 || clicked_now_button2){
        if(button1_pressed && button2_pressed) current_mode = 3;
        else if(button1_pressed) current_mode = 1;
        else if(button2_pressed) current_mode = 2;
        else current_mode = 0;
    }

    button1_pressed_before = button1_pressed;
    button2_pressed_before = button2_pressed;
}

//Function to run on _main
void run_button_system(uint32_t buttons_gpio_base, int gpio_button1_pin, int gpio_button2_pin){

    alter_mode(buttons_gpio_base, gpio_button1_pin, gpio_button2_pin);

    switch_modes(current_mode);
}
