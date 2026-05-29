#ifndef BUTTON_FUNCS_H
#define BUTTON_FUNCS_H
#include <stdint.h>


/* Overview:   This function contains all the 3 modes for led pattern blinking.              */
/* Parameters: Mode is the current active mode in the function, 0 being all the leds turned  */
/*             off and 1-3 containing all the pattern modes.                                 */
void switch_modes(int mode);


/* Overview:   This function alters the mode accordingly to the two buttons being clicked    */
/*             clicked or not logic.                                                         */
/* Parameters: buttons_gpio_base is the gpio module base that is being used for the buttons  */
/*             pin_input1 is being used to specify the pin of the first button.              */
/*             pin_input2 is being used to specify the pin of the second button              */
void alter_mode(uint32_t buttons_gpio_base, int pin_input1, int pin_input2);


/* Overview:   This function is being used to run the button system in main, using the 2     */
/*             previous declared functions in it                                             */
/* Parameters: buttons_gpio_base is the gpio module base that is being used for the buttons  */
/*             pin_input1 is being used to specify the pin of the first button               */
/*             pin_input2 is being used to specify the pin of the second button              */
void run_button_system(uint32_t buttons_gpio_base, int gpio_button1_pin, int gpio_button2_pin);


#endif
