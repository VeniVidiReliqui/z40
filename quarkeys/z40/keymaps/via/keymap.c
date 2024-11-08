/*
/ Copyright 2022 quarkeys
/ This program is free software: you can redistribute it and/or modify
/ it under the terms of the GNU General Public License as published by
/ the Free Software Foundation, either version 2 of the License, or
/ (at your option) any later version.
/ This program is distributed in the hope that it will be useful,
/ but WITHOUT ANY WARRANTY; without even the implied warranty of
/ MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
/ GNU General Public License for more details.
/ You should have received a copy of the GNU General Public License
/ along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Standard QWERTY layer
    [0] = LAYOUT_planck_mit(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        MO(2),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, MO(3),   MO(1),   KC_LALT, KC_LGUI,     KC_SPC,       MO(3),   KC_LBRC, KC_RBRC, KC_GRV,  TG(3)
    ),

    // Function keys layer
    [1] = LAYOUT_planck_mit(
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_TRNS,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12,  KC_TRNS,
        KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // Pok3r inspired function layer with RGB controls
    [2] = LAYOUT_planck_mit(
        KC_ESC,  KC_MPRV, KC_MPLY, KC_MNXT, RGB_HUD, RGB_HUI, S(KC_3), KC_PGUP, KC_UP,     KC_PGDN,    KC_MINS,   KC_DEL,
        MO(2),   KC_VOLD, KC_VOLU, KC_MUTE, RGB_SAD, RGB_SAI, KC_HOME, KC_LEFT, KC_DOWN,   KC_RGHT,    KC_EQL,    KC_BSLS,
        KC_TRNS, RGB_VAD, RGB_VAI, RGB_TOG, RGB_SPD, RGB_SPI, KC_END,  KC_QUOT, S(KC_9),   S(KC_0),    KC_BSLS,   KC_TRNS,
        KC_TRNS, RGB_RMOD,RGB_MOD, KC_TRNS, KC_TRNS,     KC_TRNS,      KC_NO,   S(KC_LBRC),S(KC_RBRC), S(KC_GRV), KC_NO
    ),

    // Mouse function and numpad layer
    [3] = LAYOUT_planck_mit(
        KC_ESC,  KC_MS_ACCEL2, KC_MS_BTN4, KC_MS_BTN3, KC_MS_BTN5, KC_NO,        KC_NO, KC_7, KC_8, KC_9,   KC_PSLS, KC_BSPC,
        KC_NO,   KC_MS_ACCEL1, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2, KC_MS_WH_DOWN,KC_NO, KC_4, KC_5, KC_6,   KC_PAST, KC_ENT,
        KC_TRNS, KC_MS_ACCEL0, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,KC_MS_WH_UP,  KC_NO, KC_1, KC_2, KC_3,   KC_PMNS, KC_TRNS,
        KC_TRNS, MO(3),        TG(4),      KC_TRNS,    KC_TRNS,          KC_MS_BTN1,    MO(3),KC_0, KC_PDOT,KC_PPLS, TG(3)
    ),

    // Gaming layer
    [4] = LAYOUT_planck_mit(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_O,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_M,    KC_I,    KC_F1,   KC_SPC,     KC_LALT,       KC_UP,   KC_DOWN, KC_LEFT, KC_RGHT, TG(4)
    ),
};

#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({9, 1, HSV_RED});
const rgblight_segment_t PROGMEM my_ar_numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS({40, 2, HSV_WHITE});
const rgblight_segment_t PROGMEM my_symbol_layer[] = RGBLIGHT_LAYER_SEGMENTS({28, 2, HSV_WHITE});
const rgblight_segment_t PROGMEM my_other_layer[] = RGBLIGHT_LAYER_SEGMENTS({16, 2, HSV_WHITE});

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,        // Caplock indicator
    my_ar_numpad_layer,        // Arrow keys & Numpad, Operator keys, reset key, RGB control and media control
    my_symbol_layer,        // F1-F12 keys & Symbols
    my_other_layer            // Self-Defined
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    return state;
}
#endif
