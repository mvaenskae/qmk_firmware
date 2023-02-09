#pragma once

// https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/

#ifdef VENDOR_ID
	#undef VENDOR_ID
	#define VENDOR_ID 0xc0fe
#endif
#ifdef PRODUCT_ID
	#undef PRODUCT_ID
	#define PRODUCT_ID 0xd00d
#endif
#ifdef DEVICE_VER
	#undef DEVICE_VER
	#define DEVICE_VER 0x1337
#endif
#ifdef MANUFACTURER
	#undef MANUFACTURER
	#define MANUFACTURER "mvaenskae"
#endif
#ifdef PRODUCT
	#undef PRODUCT
	#define PRODUCT "Sofle RGB"
#endif
#ifdef IS_COMMAND
	#undef IS_COMMAND
	#define IS_COMMAND() (get_mods() == MOD_MASK_SHIFT)
#endif

//#define ENCODER_DIRECTION_FLIP
#ifdef ENCODER_RESOLUTION
	#undef ENCODER_RESOLUTION
	#define ENCODER_RESOLUTION 4
#endif

// https://docs.qmk.fm/#/config_options?id=split-keyboard-options
//#define MASTER_LEFT
//#define MASTER_RIGHT
#define EE_HANDS

#define CUSTOM_FONT
#define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding

#define ENCODER_DIRECTION_FLIP
#define TAPPING_FORCE_HOLD
#ifdef TAPPING_TERM
	#undef TAPPING_TERM
	#define TAPPING_TERM 200
#endif

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
//#define SPLIT_WPM_ENABLE
#define SPLIT_OLED_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN D3
#define RGBLIGHT_LAYERS

#ifdef RGBLIGHT_ENABLE
	#undef RGBLED_NUM
	#define RGBLED_NUM 70
	#define RGBLED_SPLIT { 35, 35 }
	#define RGBLIGHT_SLEEP

	#define RGBLIGHT_LIMIT_VAL 120
	#define RGBLIGHT_HUE_STEP 10
	#define RGBLIGHT_SAT_STEP 17
	#define RGBLIGHT_VAL_STEP 17

	//#define RGBLIGHT_EFFECT_BREATHING
	#define RGBLIGHT_EFFECT_RAINBOW_MOOD
	//#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
	//#define RGBLIGHT_EFFECT_SNAKE
	//#define RGBLIGHT_EFFECT_KNIGHT
	//#define RGBLIGHT_EFFECT_CHRISTMAS
	//#define RGBLIGHT_EFFECT_STATIC_GRADIENT
	//#define RGBLIGHT_EFFECT_RGB_TEST
	//#define RGBLIGHT_EFFECT_ALTERNATING
	//#define RGBLIGHT_EFFECT_TWINKLE

	#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
	#define RGBLIGHT_DEFAULT_HUE 21
	#define RGBLIGHT_DEFAULT_SAT 255
	#define RGBLIGHT_DEFAULT_VAL 255
	#define RGBLIGHT_DEFAULT_SPD 0
#endif

#ifdef RGB_MATRIX_ENABLE
	#define RGB_MATRIX_LED_COUNT 35
	#define RGB_MATRIX_KEYPRESSES // reacts to keypresses
	#define RGB_MATRIX_FRAMEBUFFER_EFFECTS // enable framebuffer effects
	#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
	#define RGB_MATRIX_TIMEOUT 0 // number of milliseconds to wait until rgb automatically turns off
	#define RGB_MATRIX_SPLIT
	#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.

	#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
	#define RGB_MATRIX_DEFAULT_HUE 0
	#define RGB_MATRIX_DEFAULT_SAT 0
	#define RGB_MATRIX_DEFAULT_VAL 0
	#define RGB_MATRIX_DEFAULT_SPD 0

	#define RGB_MATRIX_HUE_STEP 8
	#define RGB_MATRIX_SAT_STEP 8
	#define RGB_MATRIX_VAL_STEP 8
	#define RGB_MATRIX_SPD_STEP 10

	#undef ENABLE_RGB_MATRIX_ALPHAS_MODS            // Static dual hue, speed is hue for secondary hue
	#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN       // Static gradient top to bottom, speed controls how much gradient changes
	#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT    // Static gradient left to right, speed controls how much gradient changes
	#undef ENABLE_RGB_MATRIX_BREATHING              // Single hue brightness cycling animation
	#undef ENABLE_RGB_MATRIX_BAND_SAT               // Single hue band fading saturation scrolling left to right
	#undef ENABLE_RGB_MATRIX_BAND_VAL               // Single hue band fading brightness scrolling left to right
	#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT      // Single hue 3 blade spinning pinwheel fades saturation
	#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL      // Single hue 3 blade spinning pinwheel fades brightness
	#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT        // Single hue spinning spiral fades saturation
	#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL        // Single hue spinning spiral fades brightness
	#undef ENABLE_RGB_MATRIX_CYCLE_ALL              // Full keyboard solid hue cycling through full gradient
	#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT       // Full gradient scrolling left to right
	#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN          // Full gradient scrolling top to bottom
	#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN           // Full gradient scrolling out to in
	#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL      // Full dual gradients scrolling out to in
	#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON // Full gradient Chevron shapped scrolling left to right
	#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL         // Full gradient spinning pinwheel around center of keyboard
	#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL           // Full gradient spinning spiral around center of keyboard
	#undef ENABLE_RGB_MATRIX_DUAL_BEACON            // Full gradient spinning around center of keyboard
	#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON         // Full tighter gradient spinning around center of keyboard
	#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS      // Full dual gradients spinning two halfs of keyboard
	#undef ENABLE_RGB_MATRIX_RAINDROPS              // Randomly changes a single key's hue
	#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS    // Randomly changes a single key's hue and saturation
	#undef ENABLE_RGB_MATRIX_HUE_BREATHING          // Hue shifts up a slight ammount at the same time, then shifts back
	#undef ENABLE_RGB_MATRIX_HUE_PENDULUM           // Hue shifts up a slight ammount in a wave to the right, then back to the left
	#undef ENABLE_RGB_MATRIX_HUE_WAVE               // Hue shifts up a slight ammount and then back down in a wave to the right
	#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL          // Single hue fractal filled keys pulsing horizontally out to edges
	#undef ENABLE_RGB_MATRIX_PIXEL_FLOW             // Pulsing RGB flow along LED wiring with random hues
	#undef ENABLE_RGB_MATRIX_PIXEL_RAIN             // Randomly light keys with random hues

	#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP // How hot is your WPM!
	#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN   // That famous computer simulation

	#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE     // Pulses keys hit to hue & value then fades value out
	#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE            // Static single hue, pulses keys hit to shifted hue then fades to current hue
	#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE       // Hue & value pulse near a single key hit then fades value out
	#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE  // Hue & value pulse near multiple key hits then fades value out
	#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS      // Hue & value pulse the same column and row of a single key hit then fades value out
	#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // Hue & value pulse the same column and row of multiple key hits then fades value out
	#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      // Hue & value pulse away on the same column and row of a single key hit then fades value out
	#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // Hue & value pulse away on the same column and row of multiple key hits then fades value out
	#undef ENABLE_RGB_MATRIX_SPLASH                    // Full gradient & value pulse away from a single key hit then fades value out
	#undef ENABLE_RGB_MATRIX_MULTISPLASH               // Full gradient & value pulse away from multiple key hits then fades value out
	#undef ENABLE_RGB_MATRIX_SOLID_SPLASH              // Hue & value pulse away from a single key hit then fades value out
	#undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH         // Hue & value pulse away from multiple key hits then fades value out
#endif
