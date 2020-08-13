/* Copyright 2017 Cole Markham
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        /* Qwerty
         * ,-----------------------------------------------------------------------------------.
         * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
         * |------+------+------+------+------+-------------+------+------+------+------+------|
         * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
         * |------+------+------+------+------+------|------+------+------+------+------+------|
         * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
         * |------+------+------+------+------+------+------+------+------+------+------+------|
         * |Adjust| Ctrl | Ctrl  | Alt  |Lower | Cmd  |Space |Raise | Left | Down |  Up  |Right |
         * `-----------------------------------------------------------------------------------'
         */
        [_QWERTY] = KEYMAP( \
                KC_ESC,  RGB_TOG,    RGB_M_R,    KC_E,    KC_R,    KC_T, \
                KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G, \
                KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, \
                ADJUST,  KC_LCTL, KC_LALT, KC_LALT, LOWER,   KC_LGUI \
        ),
};


void matrix_init_user(void) {
}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Testing"), false);
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    print("encoder update")
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif