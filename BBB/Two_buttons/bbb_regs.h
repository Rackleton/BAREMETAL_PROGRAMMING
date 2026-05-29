#ifndef BBB_REGS_H
#define BBB_REGS_H

/*All of the register adresses bellow are specified at the Texas Instrument's Sitara AM335X processors technical reference manual.*/

//Peripherical and modules base
#define CM_PER_BASE                 0x44E00000 // Defines the clock module peripherical base. Used to set the clock in peripherical components.
#define GPIO1_BASE                  0x4804C000 // Defines the base for the gpio 1 module. Used to reference to any specific gpio in that module using a pin.
#define GPIO2_BASE                  0X481AC000 // Defines the base for the gpio 2 module. Used to reference to any specific gpio in that module using a pin.
#define CONTROL_MODULE_BASE         0x44E10000 // Defines the base for the control module. Used mainly to set a specific function to the desired pin.

//Watchdog
#define WDT1                        0x44E35000 // Defines the base for the watchdog. Responsible for stopping the system after it has not been fed for a while.
#define WDT_WSPR                    0x48       // Defines the offset for the watchdog activation/deactivation sequence register.
#define WDT_WWPS                    0x34       // Defines the offset for the watchdog occupied wait register in the activation/deactivation sequence.
#define WDT_CLOCK                   0xD4       // Defines the offset for the watchdog clock.

//Peripherical and modules offset
#define CM_PER_GPIO1_CLKCTRL        0xAC       // Defines the offset for the gpio 1 module clock register.
#define CM_PER_GPIO2_CLKCTRL        0xB0       // Defines the offset for the gpio 2 module clock register.
#define GPIO_OE                     0x134      // Defines the offset for the gpio direction register.
#define GPIO_SETDATAOUT             0x194      // Defines the offset for the gpio tension set function register.
#define GPIO_CLEARDATAOUT           0x190      // Defines the offset for the gpio tension kill function regsiter.
#define GPIO_DATAIN                 0x138      // Defines the offset for the read function register in input set gpio's.

//Used gpio's
#define GPMC_A0                     0x840      // Defines the gpio1_16 pad register adress.
#define GPMC_A5                     0x854      // Defines the gpio1_21 pad register adress (internal led usr0).
#define GPMC_A6                     0x858      // Defines the gpio1_22 pad register adress (internal led usr1).
#define GPMC_A7                     0x85C      // Defines the gpio1_23 pad register adress (internal led usr2).
#define GPMC_A8                     0x860      // Defines the gpio1_24 pad register adress (internal led usr3).
#define LCD_DATA3                   0X8AC      // Defines the gpio2_9  pad register adress.
#define LCD_DATA4                   0x8B0      // Defines the gpio2_10 pad register adress.

#define HWREG(x) (*(unsigned volatile int *)(x)) // This function is used to acess register data.

#endif
