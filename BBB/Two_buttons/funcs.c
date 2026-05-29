#include "../inc/bbb_regs.h"
#include "../inc/button_funcs.h"
#include <stdint.h>


// Sets a waiting time between operations while checking for a specific input gpio for possible alterations
void delay(int x, uint32_t buttons_gpio_base, int button1_pin, int button2_pin){
    for(volatile int i=0;i<x;i++){
        if(i % 10000 == 0){
            alter_mode(buttons_gpio_base, button1_pin, button2_pin);
        }
    }
}

// Set the clock of the corresponding gpio module
void set_clock(uint32_t cm_per, uint32_t cm_offset){
    HWREG(cm_per + cm_offset) |= 0x2;
}

// Set a specific pin as output. Automatically multiplexes designed pin for gpio purpose and set it as output
void set_pin_out(uint32_t gpio_base, uint32_t pad, int pin){
    HWREG(gpio_base + GPIO_OE) &= ~(1 << pin);
    HWREG(CONTROL_MODULE_BASE + pad) |= 0x7;
}

// Set a specific pin as input. Automatically multiplexes designed pin for gpio purpose, rx_active and set it as input
void set_pin_in(uint32_t gpio_base, uint32_t pad, int pin){
    HWREG(gpio_base + GPIO_OE) |= (1 << pin);
    HWREG(CONTROL_MODULE_BASE + pad) |= (0x7 | (1 << 5));
}

// Reads the requested bit on the gpio and returns true if the bit is set to 1
int gpio_in_true(uint32_t gpio_base, int pin){
    if (HWREG(gpio_base + GPIO_DATAIN) & (1 << pin)) return 1;
    else return 0;
}

// Sets the gpio with high value (for output)
void gpio_high(uint32_t gpio_base, int pin){
    HWREG(gpio_base + GPIO_SETDATAOUT) |= (1 << pin);
}
// Set the gpio with low value (for output)
void gpio_low(uint32_t gpio_base, int pin){
    HWREG(gpio_base + GPIO_CLEARDATAOUT) |= (1 << pin);
}

// Disable the watchdog. Not recomended for first iterations of testing. The sequence for reactivation is 0xBBBB -> 0x4444
void disable_watchdog(){

    HWREG(WDT1 + WDT_CLOCK) |= 0x2;

    HWREG(WDT1 + WDT_WSPR) = 0xAAAA;
    while((HWREG(WDT1 + WDT_WWPS) & (1 << 4)) != 0);
    HWREG(WDT1 + WDT_WSPR) = 0X5555;
    while((HWREG(WDT1 + WDT_WWPS) & (1 << 4)) != 0);
}
