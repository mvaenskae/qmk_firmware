#ifdef RGBLIGHT_ENABLE

#include "keymap_mine.h"

#define LEFT 0
#define RIGHT 35

#define COLOUR_NUMBER_ROW(...) \
	{ LEFT + 11, 1, __VA_ARGS__ }, \
	{ LEFT + 20, 2, __VA_ARGS__ }, \
	{ LEFT + 30, 2, __VA_ARGS__ }, \
	{ RIGHT + 11, 1, __VA_ARGS__ }, \
	{ RIGHT + 20, 2, __VA_ARGS__ }, \
	{ RIGHT + 30, 2, __VA_ARGS__ }
#define COLOUR_NUMPAD_NUMBERS(...) \
	{ RIGHT + 17, 3, __VA_ARGS__ }, \
	{ RIGHT + 22, 3, __VA_ARGS__ }, \
	{ RIGHT + 27, 3, __VA_ARGS__ }
#define COLOUR_NUMPAD_SIGNS(...) \
	{ RIGHT + 11, 4, __VA_ARGS__ }, \
	{ RIGHT + 20, 2, __VA_ARGS__ }, \
	{ RIGHT + 30, 1, __VA_ARGS__ }
#define COLOUR_NUMPAD_EMULATION(...) \
	COLOUR_NUMPAD_NUMBERS(__VA_ARGS__), \
	COLOUR_NUMPAD_SIGNS(__VA_ARGS__)

#define COLOUR_TOP_UP(...) \
	{ LEFT + 10, 2, __VA_ARGS__ }, \
	{ LEFT + 20, 2, __VA_ARGS__ }, \
	{ LEFT + 30, 2, __VA_ARGS__ }, \
	{ RIGHT + 10, 2, __VA_ARGS__ }, \
	{ RIGHT + 20, 2, __VA_ARGS__ }, \
	{ RIGHT + 30, 2, __VA_ARGS__ }
#define COLOUR_TOP_OUTER(...) \
	{ LEFT + 7, 4, __VA_ARGS__ }, \
	{ RIGHT + 7, 4, __VA_ARGS__ }
#define COLOUR_TOP_DOWN(...) \
	{ LEFT + 6, 1, __VA_ARGS__ }, \
	{ LEFT + 15, 2, __VA_ARGS__ }, \
	{ LEFT + 25, 2, __VA_ARGS__ }, \
	{ RIGHT + 6, 1, __VA_ARGS__ }, \
	{ RIGHT + 15, 2, __VA_ARGS__ }, \
	{ RIGHT + 25, 2, __VA_ARGS__ }
#define COLOUR_TOP_KEYS(...) \
	{ LEFT + 11, 4, __VA_ARGS__ }, \
	{ LEFT + 17, 8, __VA_ARGS__ }, \
	{ LEFT + 27, 8, __VA_ARGS__ }, \
	{ RIGHT + 11, 4, __VA_ARGS__ }, \
	{ RIGHT + 17, 8, __VA_ARGS__ }, \
	{ RIGHT + 27, 8, __VA_ARGS__ }
#define COLOUR_TOP_ALL(...) \
	{ LEFT + 6, 29, __VA_ARGS__ }, \
	{ RIGHT + 6, 29, __VA_ARGS__ }

#define COLOUR_BOTTOM_UP(...) \
	{ LEFT + 0, 3, __VA_ARGS__ }, \
	{ RIGHT + 0, 3, __VA_ARGS__ }
#define COLOUR_BOTTOM_OUTER(...) \
	{ LEFT + 0, 1, __VA_ARGS__ }, \
	{ LEFT + 5, 1, __VA_ARGS__ }, \
	{ RIGHT + 0, 1, __VA_ARGS__ }, \
	{ RIGHT + 5, 1, __VA_ARGS__ }
#define COLOUR_BOTTOM_DOWN(...) \
	{ LEFT + 3, 3, __VA_ARGS__ }, \
	{ RIGHT + 3, 3, __VA_ARGS__ }
#define COLOUR_BOTTOM_ALL(...)  \
	{ LEFT + 0, 6, __VA_ARGS__ }, \
	{ RIGHT + 0, 6, __VA_ARGS__ }

#define COLOUR_LAYER(...) \
	COLOUR_BOTTOM_ALL(__VA_ARGS__), \
	COLOUR_TOP_ALL(__VA_ARGS__)
#define COLOUR_HIGHLIGHT(...) \
	COLOUR_BOTTOM_OUTER(__VA_ARGS__), \
	COLOUR_BOTTOM_DOWN(__VA_ARGS__), \
	COLOUR_TOP_OUTER(__VA_ARGS__), \
	COLOUR_TOP_DOWN(__VA_ARGS__)


char layer_state_str[70];

// _LOWER - Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_lights_lower[] = RGBLIGHT_LAYER_SEGMENTS(
	COLOUR_HIGHLIGHT(HSV_TEAL)
);

// _RAISE - Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_lights_raise[] = RGBLIGHT_LAYER_SEGMENTS(
	COLOUR_HIGHLIGHT(HSV_BLUE)
);

// _ADJUST - Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_lights_adjust[] = RGBLIGHT_LAYER_SEGMENTS(
	COLOUR_HIGHLIGHT(HSV_PURPLE)
);

//_NUMPAD - light up numpad on right half
const rgblight_segment_t PROGMEM layer_lights_numpad[] = RGBLIGHT_LAYER_SEGMENTS(
	COLOUR_BOTTOM_ALL(HSV_GREEN),
	COLOUR_NUMPAD_NUMBERS(HSV_CHARTREUSE),
	COLOUR_NUMPAD_SIGNS(HSV_GREEN)
);

// _SWITCHER - light up top row
const rgblight_segment_t PROGMEM layer_lights_switch[] = RGBLIGHT_LAYER_SEGMENTS(
	COLOUR_BOTTOM_UP(HSV_GREEN),
	COLOUR_TOP_UP(HSV_GREEN)
);

const rgblight_segment_t* const PROGMEM _rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	layer_lights_lower,
	layer_lights_raise,
	layer_lights_adjust,
	layer_lights_numpad,
	layer_lights_switch
);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(1, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(2, layer_state_cmp(state, _ADJUST));
	rgblight_set_layer_state(3, layer_state_cmp(state, _NUMPAD));
	rgblight_set_layer_state(4, layer_state_cmp(state, _SWITCH));
	return state;
}

void keyboard_post_init_user(void) {
	rgblight_layers = _rgb_layers;
	rgblight_mode_noeeprom(1); // haven't found a way to set this in a more useful way
	set_single_persistent_default_layer(_COLEMAKDH);
}

#endif
