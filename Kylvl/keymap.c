#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_74_255_255,
  HSV_169_255_255,
  ST_MACRO_0,
  ST_MACRO_1,
};


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
tap_dance_action_t *action;

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           DE_SS,          
    KC_LEFT_GUI,    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           MT(MOD_LGUI, DE_UE),
    KC_LEFT_CTRL,   KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           DE_OE,          MT(MOD_RCTL, DE_AE),
    KC_LEFT_ALT,    DE_Y,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         DE_MINS,        KC_LEFT_ALT,    
                                                    MT(MOD_LSFT, KC_BSPC),TD(DANCE_0),                                    TD(DANCE_1),    LT(6,KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    DE_QUOT,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           DE_SS,          
    MT(MOD_LGUI, DE_CIRC),KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           DE_Z,           KC_U,           KC_I,           KC_O,           KC_P,           MT(MOD_LGUI, DE_UE),
    MT(MOD_LCTL, DE_HASH),KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           DE_OE,          MT(MOD_RCTL, DE_AE),
    MT(MOD_LALT, DE_LESS),DE_Y,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         DE_MINS,        MT(MOD_RALT, DE_PLUS),
                                                    MT(MOD_LSFT, KC_BSPC),LT(2,KC_TAB),                                   TD(DANCE_2),    LT(6,KC_SPACE)
  ),
  [2] = LAYOUT_voyager(
    KC_ESCAPE,      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_LEFT_GUI,    KC_PAGE_UP,     KC_BSPC,        KC_UP,          KC_DELETE,      KC_PGDN,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_LEFT_GUI,    
    KC_LEFT_CTRL,   KC_HOME,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,                                         KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_RIGHT_CTRL,  
    KC_LEFT_ALT,    KC_ESCAPE,      KC_TAB,         KC_INSERT,      KC_ENTER,       KC_PC_UNDO,                                     KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_RIGHT_ALT,   
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_LEFT_SHIFT,  KC_NO
  ),
  [3] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           DE_MINS,        
    KC_LEFT_GUI,    KC_J,           KC_D,           KC_U,           KC_A,           KC_X,                                           KC_P,           KC_H,           KC_L,           KC_M,           KC_W,           MT(MOD_LGUI, DE_SS),
    KC_LEFT_CTRL,   KC_C,           KC_T,           KC_I,           KC_E,           KC_O,                                           KC_B,           KC_N,           KC_R,           KC_S,           KC_G,           MT(MOD_RCTL, KC_Q),
    KC_LEFT_ALT,    KC_F,           KC_V,           DE_UE,          DE_AE,          DE_OE,                                          DE_Y,           DE_Z,           KC_COMMA,       KC_DOT,         KC_K,           KC_LEFT_ALT,    
                                                    MT(MOD_LSFT, KC_BSPC),LT(5,KC_TAB),                                   LT(4,KC_ENTER), LT(6,KC_SPACE)
  ),
  [4] = LAYOUT_voyager(
    KC_NO,          KC_NO,          DE_SQ2,         DE_SQ3,         KC_NO,          KC_NO,                                          ST_MACRO_0,     ST_MACRO_1,     KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          DE_UNDS,        DE_LBRC,        DE_RBRC,        DE_CIRC,                                        DE_EXLM,        DE_LESS,        DE_MORE,        DE_EQL,         DE_AMPR,        KC_NO,          
    KC_TRANSPARENT, DE_BSLS,        DE_SLSH,        DE_LCBR,        DE_RCBR,        DE_ASTR,                                        DE_QST,         DE_LPRN,        DE_RPRN,        DE_MINS,        DE_COLN,        TD(DANCE_3),    
    KC_TRANSPARENT, DE_HASH,        DE_DLR,         DE_PIPE,        DE_TILD,        DE_GRV,                                         DE_PLUS,        DE_PERC,        DE_DQOT,        DE_QUOT,        DE_SCLN,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NUM,         KC_TAB,         KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    
    KC_TRANSPARENT, KC_PAGE_UP,     KC_BSPC,        KC_UP,          KC_DELETE,      KC_PGDN,                                        KC_NO,          KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     KC_KP_EQUAL,    
    KC_TRANSPARENT, KC_HOME,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,                                         KC_NO,          KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_COMMA,    MT(MOD_RCTL, KC_KP_DOT),
    KC_TRANSPARENT, KC_ESCAPE,      KC_TAB,         KC_INSERT,      KC_ENTER,       KC_PC_UNDO,                                     DE_COLN,        KC_KP_1,        KC_KP_2,        KC_KP_3,        DE_SCLN,        KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_0
  ),
  [6] = LAYOUT_voyager(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          TO(8),          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
                                                    LSFT(KC_RSFT),  RALT(DE_LESS),                                  KC_NO,          KC_TRANSPARENT
  ),
  [7] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        RGB_VAD,        RGB_VAI,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  KC_TRANSPARENT,                                 KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,                                 KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    TO(8),          KC_TRANSPARENT, KC_TRANSPARENT, HSV_0_255_255,  HSV_74_255_255, HSV_169_255_255,                                KC_TRANSPARENT, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_voyager(
    TO(7),          TO(0),          TO(1),          TO(3),          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_NO,          KC_NO,                                          KC_NO,          KC_NO
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {167,239,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {30,235,226}, {0,0,0}, {44,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {167,239,255}, {0,0,0}, {30,235,226}, {0,0,0}, {0,0,0}, {0,0,0}, {91,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {44,255,255}, {0,0,0}, {0,0,0} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {167,239,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {30,235,226}, {0,0,0}, {44,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {167,239,255}, {0,0,0}, {30,235,226}, {0,0,0}, {0,0,0}, {0,0,0}, {91,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {44,255,255}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {167,239,255}, {178,218,204}, {254,218,204}, {178,218,204}, {254,218,204}, {178,218,204}, {91,218,204}, {178,218,204}, {178,218,204}, {178,218,204}, {178,218,204}, {178,218,204}, {44,255,255}, {0,0,0}, {0,0,0}, {79,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {167,239,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {44,255,255}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {167,239,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {91,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {30,235,226}, {0,0,0}, {44,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {167,239,255}, {0,0,0}, {30,235,226}, {0,0,0}, {0,0,0}, {0,0,0}, {91,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {44,255,255}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {178,218,204}, {254,218,204}, {178,218,204}, {254,218,204}, {178,218,204}, {0,0,0}, {178,218,204}, {178,218,204}, {178,218,204}, {178,218,204}, {178,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {79,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {167,239,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [7] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {167,239,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {254,218,204}, {131,218,204}, {131,218,204}, {178,218,204}, {131,218,204}, {0,0,0}, {0,0,0}, {131,218,204}, {178,218,204}, {178,218,204}, {178,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {30,235,226}, {30,235,226}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [8] = { {167,239,255}, {167,239,255}, {167,239,255}, {167,239,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_1) SS_TAP(X_6) SS_TAP(X_2) ));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_1) SS_TAP(X_6) SS_TAP(X_5) ));
    }
    break;

    case TD(DANCE_0):
    case TD(DANCE_1):
    case TD(DANCE_2):
    case TD(DANCE_3):
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
        break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_74_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(74,255,255);
      }
      return false;
    case HSV_169_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(169,255,255);
      }
      return false;
  }
  return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
    }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_TAP_HOLD(KC_TAB, DE_LESS),
        [DANCE_1] = ACTION_TAP_DANCE_TAP_HOLD(KC_ENTER, KC_CAPS),
        [DANCE_2] = ACTION_TAP_DANCE_TAP_HOLD(KC_ENTER, KC_CAPS),
        [DANCE_3] = ACTION_TAP_DANCE_TAP_HOLD(DE_AT, KC_RIGHT_CTRL),
};













// Custom QMK here

#define DE_DEG S(DE_CIRC)
#define DE_SECT S(KC_3)
#define DE_EURO ALGR(KC_E)
#define DE_DLR S(KC_4)

const key_override_t bone_n1_override = 
    ko_make_with_layers(MOD_MASK_SHIFT, KC_1, DE_DEG, 1<<3);
const key_override_t bone_n2_override = 
    ko_make_with_layers(MOD_MASK_SHIFT, KC_2, DE_SECT, 1<<3);
const key_override_t bone_n6_override = 
    ko_make_with_layers(MOD_MASK_SHIFT, KC_6, DE_DLR, 1<<3);
const key_override_t bone_n7_override = 
    ko_make_with_layers(MOD_MASK_SHIFT, KC_7, DE_EURO, 1<<3);

const key_override_t **key_overrides = (const key_override_t *[]){
	&bone_n1_override,
	&bone_n2_override,
	&bone_n6_override,
	&bone_n7_override,
	NULL
};
