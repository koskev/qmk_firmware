/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE
extern void rgb_matrix_update_pwm_buffers(void);
#endif // RGB_MATRIX_ENABLE

#ifndef PROGMEM
#    define PROGMEM
#endif

enum unicode_names { DE_LOWER_SS, DE_LOWER_AE, DE_UPPER_AE, DE_LOWER_OE, DE_UPPER_OE, DE_LOWER_UE, DE_UPPER_UE };

enum layers { LAYER_BASE, LAYER_1, LAYER_2, LAYER_3 };

const uint32_t PROGMEM unicode_map[] = {
    [DE_LOWER_SS] = 0x00DF, // ß
    [DE_UPPER_AE] = 0x00C4, // Ä
    [DE_LOWER_AE] = 0x00E4, // ä
    [DE_UPPER_OE] = 0x00D6, // Ö
    [DE_LOWER_OE] = 0x00F6, // ö
    [DE_UPPER_UE] = 0x00DC, // Ü
    [DE_LOWER_UE] = 0x00FC, // ü
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬───┬───┬───┬──────┬───────┐               ┌───────┬────────────┬───┬───┬───┬──────┐
//    │ tab  │ q │ w │ e │  r   │   t   │               │   y   │     u      │ i │ o │ p │ bspc │
//    ├──────┼───┼───┼───┼──────┼───────┤               ├───────┼────────────┼───┼───┼───┼──────┤
//    │ lctl │ a │ s │ d │  f   │   g   │               │   h   │     j      │ k │ l │ ; │  '   │
//    ├──────┼───┼───┼───┼──────┼───────┤               ├───────┼────────────┼───┼───┼───┼──────┤
//    │ ralt │ z │ x │ c │  v   │   b   │               │   n   │     m      │ , │ . │ / │ esc  │
//    └──────┴───┴───┴───┼──────┼───────┼─────┐   ┌─────┼───────┼────────────┼───┴───┴───┴──────┘
//                       │ lgui │ MO(1) │ spc │   │ ent │ MO(2) │ left_SHIFT │
//                       └──────┴───────┴─────┘   └─────┴───────┴────────────┘
[LAYER_BASE] = LAYOUT_split_3x6_3(
  KC_TAB  , KC_Q , KC_W , KC_E , KC_R    , KC_T  ,                       KC_Y  , KC_U          , KC_I    , KC_O   , KC_P    , KC_BSPC,
  KC_LCTL , KC_A , KC_S , KC_D , KC_F    , KC_G  ,                       KC_H  , KC_J          , KC_K    , KC_L   , KC_SCLN , KC_QUOT,
  KC_RALT , KC_Z , KC_X , KC_C , KC_V    , KC_B  ,                       KC_N  , KC_M          , KC_COMM , KC_DOT , KC_SLSH , KC_ESC ,
                                 KC_LGUI , MO(1) , KC_SPC ,     KC_ENT , MO(2) , KC_LEFT_SHIFT
),

//    ┌──────┬──────────────────────────────┬────┬────┬──────┬─────┐               ┌───────┬──────┬───┬──────┬────┬──────┐
//    │ tab  │              no              │ no │ no │  no  │ no  │               │   7   │  8   │ 9 │  no  │ no │ bspc │
//    ├──────┼──────────────────────────────┼────┼────┼──────┼─────┤               ├───────┼──────┼───┼──────┼────┼──────┤
//    │ lctl │ UP(DE_LOWER_AE, DE_UPPER_AE) │ no │ no │  no  │ no  │               │   4   │  5   │ 6 │ rght │ no │  no  │
//    ├──────┼──────────────────────────────┼────┼────┼──────┼─────┤               ├───────┼──────┼───┼──────┼────┼──────┤
//    │ lsft │              no              │ no │ no │  no  │ no  │               │   1   │  2   │ 3 │  0   │ no │  no  │
//    └──────┴──────────────────────────────┴────┴────┼──────┼─────┼─────┐   ┌─────┼───────┼──────┼───┴──────┴────┴──────┘
//                                                    │ lgui │     │ spc │   │ ent │ MO(3) │ ralt │
//                                                    └──────┴─────┴─────┘   └─────┴───────┴──────┘
[LAYER_1] = LAYOUT_split_3x6_3(
  KC_TAB  , KC_NO                        , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                       KC_7  , KC_8    , KC_9 , KC_NO    , KC_NO   , KC_BSPC,
  KC_LCTL , UP(DE_LOWER_AE, DE_UPPER_AE) , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                       KC_4  , KC_5    , KC_6 , KC_RIGHT , XXXXXXX , XXXXXXX,
  KC_LSFT , XXXXXXX                      , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                       KC_1  , KC_2    , KC_3 , KC_0     , XXXXXXX , XXXXXXX,
                                                               KC_LGUI , KC_TRNS , KC_SPC ,     KC_ENT , MO(3) , KC_RALT
),

//    ┌──────┬────┬────┬────┬──────┬───────┐               ┌─────┬──────┬───┬───┬───┬──────┐
//    │ tab  │ !  │ @  │ #  │  $   │   %   │               │  ^  │  &   │ * │ ( │ ) │ bspc │
//    ├──────┼────┼────┼────┼──────┼───────┤               ├─────┼──────┼───┼───┼───┼──────┤
//    │ lctl │ no │ no │ no │  no  │  no   │               │  -  │  =   │ [ │ ] │ \ │  `   │
//    ├──────┼────┼────┼────┼──────┼───────┤               ├─────┼──────┼───┼───┼───┼──────┤
//    │ lsft │ no │ no │ no │  no  │  no   │               │  _  │  +   │ { │ } │ | │  ~   │
//    └──────┴────┴────┴────┼──────┼───────┼─────┐   ┌─────┼─────┼──────┼───┴───┴───┴──────┘
//                          │ lgui │ MO(3) │ spc │   │ ent │     │ ralt │
//                          └──────┴───────┴─────┘   └─────┴─────┴──────┘
[LAYER_2] = LAYOUT_split_3x6_3(
  KC_TAB  , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,                       KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_BSPC,
  KC_LCTL , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                       KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS , KC_GRV ,
  KC_LSFT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                       KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , KC_PIPE , KC_TILD,
                                          KC_LGUI , MO(3)   , KC_SPC ,     KC_ENT , _______ , KC_RALT
),

//    ┌─────────┬─────────┬─────────┬─────────┬──────┬─────┐               ┌─────┬──────┬────┬────┬────┬────┐
//    │ QK_BOOT │   no    │   no    │   no    │  no  │ no  │               │ no  │  no  │ no │ no │ no │ no │
//    ├─────────┼─────────┼─────────┼─────────┼──────┼─────┤               ├─────┼──────┼────┼────┼────┼────┤
//    │ RGB_TOG │ RGB_HUI │ RGB_SAI │ RGB_VAI │  no  │ no  │               │ no  │  no  │ no │ no │ no │ no │
//    ├─────────┼─────────┼─────────┼─────────┼──────┼─────┤               ├─────┼──────┼────┼────┼────┼────┤
//    │ RGB_MOD │ RGB_HUD │ RGB_SAD │ RGB_VAD │  no  │ no  │               │ no  │  no  │ no │ no │ no │ no │
//    └─────────┴─────────┴─────────┴─────────┼──────┼─────┼─────┐   ┌─────┼─────┼──────┼────┴────┴────┴────┘
//                                            │ lgui │     │ spc │   │ ent │     │ ralt │
//                                            └──────┴─────┴─────┘   └─────┴─────┴──────┘
[LAYER_3] = LAYOUT_split_3x6_3(
  QK_BOOT , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                       XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  RGB_TOG , RGB_HUI , RGB_SAI , RGB_VAI , XXXXXXX , XXXXXXX ,                       XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  RGB_MOD , RGB_HUD , RGB_SAD , RGB_VAD , XXXXXXX , XXXXXXX ,                       XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                                          KC_LGUI , _______ , KC_SPC ,     KC_ENT , _______ , KC_RALT
)
};
// clang-format on

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_left()) {
        return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    }

    return rotation;
}

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case LAYER_BASE:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case LAYER_1:
            oled_write_P(PSTR("Layer 1\n"), false);
            break;
        case LAYER_2:
            oled_write_P(PSTR("Layer 2\n"), false);
            break;
        case LAYER_3:
            oled_write_P(PSTR("Layer 3\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
void oled_render_boot(bool bootloader) {
    oled_clear();
    for (int i = 0; i < 16; i++) {
        oled_set_cursor(0, i);
        if (bootloader) {
            oled_write_P(PSTR("Awaiting New Firmware "), false);
        } else {
            oled_write_P(PSTR("Rebooting "), false);
        }
    }
    oled_render_dirty(true);
}
#endif

#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_boot(bool bootloader) {
    if (bootloader) {
        // red for bootloader
        rgb_matrix_set_color_all(RGB_RED);
    } else {
        // off for soft reset
        rgb_matrix_set_color_all(RGB_OFF);
    }
    // force flushing -- otherwise will never happen
    rgb_matrix_update_pwm_buffers();
}
#endif

bool shutdown_user(bool jump_to_bootloader) {
#ifdef OLED_ENABLE
    oled_render_boot(jump_to_bootloader);
#endif
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_boot(jump_to_bootloader);
#endif
    // false to not process kb level
    return false;
}
