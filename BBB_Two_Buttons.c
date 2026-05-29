#include "../inc/bbb_regs.h"
#include "../inc/funcs.h"
#include "../inc/button_funcs.h"

/*Expected outcome of the system: Using gpio module 1 as ouptup purpose pins for leds and the gpio module 2 as input purpose pins.
As the buttons are pressed in different ways, the 4 internal leds + one external led should blink at a specific pattern*/

int _main(){

    disable_watchdog(); //Disable the watchdog at inicialization to support continuos running of the system

    set_clock( /*peripherical clock base*/ CM_PER_BASE, /*clock module 1 offset*/ CM_PER_GPIO1_CLKCTRL);
    set_clock( /*peripherical clock base*/ CM_PER_BASE, /*clock module 2 offset*/ CM_PER_GPIO2_CLKCTRL);

    set_pin_out( /*gpio 1 module registers base*/ GPIO1_BASE, /*gpio module pad for the gpio1_16 external led*/ GPMC_A0, /*pin number*/ 16);
    set_pin_out( /*gpio 1 module registers base*/ GPIO1_BASE, /*gpio module pad for the usr0 internal led*/     GPMC_A5, /*pin number*/ 21);
    set_pin_out( /*gpio 1 module registers base*/ GPIO1_BASE, /*gpio module pad for the usr1 internal led*/     GPMC_A6, /*pin number*/ 22);
    set_pin_out( /*gpio 1 module registers base*/ GPIO1_BASE, /*gpio module pad for the usr2 internal led*/     GPMC_A7, /*pin number*/ 23);
    set_pin_out( /*gpio 1 module registers base*/ GPIO1_BASE, /*gpio module pad for the usr3 internal led*/     GPMC_A8, /*pin number*/ 24);

    set_pin_in( /*gpio 2 module registers base*/  GPIO2_BASE, /*gpio module pad for the gpio2_9 as input*/ LCD_DATA3, /*pin number*/  9);
    set_pin_in( /*gpio 2 module registers base*/  GPIO2_BASE, /*gpio module pad for the gpio2_9 as input*/ LCD_DATA4, /*pin number*/ 10);

    while(1){
        run_button_system(/*gpio 2 module base*/ GPIO2_BASE, /*first button pin (gpio2_9)*/ 9, /*second button pin (gpio2_10)*/ 10);
    }

    return 0;
}
