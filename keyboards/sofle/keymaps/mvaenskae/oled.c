#ifdef OLED_ENABLE

#include "keymap.h"

bool get_state_leds(char* state_leds, char default_value) {
	led_t led_state = host_keyboard_led_state();
	state_leds[0] = led_state.num_lock    ? 'N' : default_value;
	state_leds[1] = led_state.caps_lock   ? 'C' : default_value;
	state_leds[2] = led_state.scroll_lock ? 'S' : default_value;
	return true;
}

bool print_line(void) {
    oled_write_P(PSTR("-----"), false);
    return true;
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("SOFLE"), false);
    oled_write_ln_P(PSTR("MiVa"), false);
    print_line();
    //snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Q:"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("C:"), false);
            break;
        case _COLEMAKDH:
            oled_write_P(PSTR("D:"), false);
            break;
        default:
            oled_write_P(PSTR("?:"), false);
    }

    char BLANK = ' ';
    char state_leds[4] = { BLANK, BLANK, BLANK, '\0' };
    get_state_leds(state_leds, BLANK);
    oled_write(state_leds, false);

    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        case _COLEMAK:
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Systm"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Numpd"), false);
            break;
        case _SWITCH:
            oled_write_P(PSTR("Swtch"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    print_line();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_270;
}

bool oled_task_user(void) {
	print_status_narrow();
    	return false;
}

#endif
