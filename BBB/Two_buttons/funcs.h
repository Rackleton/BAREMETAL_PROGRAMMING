#ifndef FUNCS_H
#define FUNCS_H
#include <stdint.h>


/* Overview:   This delay function sets a delay while checking for possible alterations in    */
/*             the led pattern mode                                                           */
/* Parameters: buttons_gpio_base is the gpio module base that is being used for the buttons   */
/*             pin_input1 is being used to specify the pin of the first button.               */
/*             pin_input2 is being used to specify the pin of the second button               */
void delay(int x, uint32_t buttons_gpio_base,  int button1_pin, int button2_pin);


/* Overview:   This function sets the clock of a specific peripherical component such as a    */
/*             a gpio module.                                                                 */
/* Parameters: cm_per is the base of the clock module for periphericals                       */
/*             cm_offset is the offset of the clock module                                    */
void set_clock(uint32_t cm_per, uint32_t cm_offset);


/* Overview:   This function sets the designed pin as a pin used for output. It automatically */
/*             multiplexes for gpio and the direction for output                              */
/* Parameters: gpio_base is the base of the used gpio module                                  */
/*             pad is the specific gpio pad id                                                */
/*             pin is used to specify the used pin of the gpio                                */
void set_pin_out(uint32_t gpio_base, uint32_t pad, int pin);


/* Overview:   This function sets the designed pin as a pin used for intput. It automatically */
/*             multiplexes for gpio, receiver enabled and the direction for output            */
/* Parameters: gpio_base is the base of the used gpio module                                  */
/*             pad is the specific gpio pad id                                                */
/*             pin is used to specify the used pin of the gpio                                */
void set_pin_in(uint32_t gpio_base, uint32_t pad, int pin);


/* Overview:   This function serves the purpose of a boolean type. When the input gpio is     */
/*             with high tension at the gpio_pin, it returns 1, otherwise it returns 0        */
/* Parameters: gpio_base is the base of the used gpio module                                  */
/*             pin is used to specify the used pin of the gpio                                */
int gpio_in_true(uint32_t gpio_base, int pin);


/* Overview:   This functions sets the specific gpio with high tension value                  */
/* Parameters: gpio_base is the base of the used gpio module                                  */
/*             pin is used to specify the used pin of the gpio                                */
void gpio_high(uint32_t gpio_base, int pin);


/* Overview:   This functions sets the specific gpio with low tension value                   */
/* Parameters: gpio_base is the base of the used gpio module                                  */
/*             pin is used to specify the used pin of the gpio                                */
void gpio_low(uint32_t gpio_base, int pin);


// Disable the watchdog. Responsible for stopping the system after it has not been fed for a while.
void disable_watchdog();


#endif
