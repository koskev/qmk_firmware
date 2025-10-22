// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _LEFT_1,
    _RIGHT_1,
    _ADJUST,
};

enum custom_keycodes { KC_PRVWD = QK_USER, KC_NXTWD, KC_LSTRT, KC_LEND };

#define KC_QWERTY PDF(_QWERTY)
#define KC_COLEMAK PDF(_COLEMAK)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────────┬───┬──────┬──────┬─────┬─────┐                                          ┌───────────┬─────┬──────┬──────┬───┬──────┐
//    │ ^ (dead) │ 1 │  2   │  3   │  4  │  5  │                                          │     6     │  7  │  8   │  9   │ 0 │  ß   │
//    ├──────────┼───┼──────┼──────┼─────┼─────┤                                          ├───────────┼─────┼──────┼──────┼───┼──────┤
//    │   tab    │ q │  w   │  e   │  r  │  t  │                                          │     z     │  u  │  i   │  o   │ p │  ü   │
//    ├──────────┼───┼──────┼──────┼─────┼─────┤                                          ├───────────┼─────┼──────┼──────┼───┼──────┤
//    │   lsft   │ a │  s   │  d   │  f  │  g  │                                          │     h     │  j  │  k   │  l   │ ö │  ä   │
//    ├──────────┼───┼──────┼──────┼─────┼─────┼──────────────────┐   ┌───────────────────┼───────────┼─────┼──────┼──────┼───┼──────┤
//    │   lctl   │ y │  x   │  c   │  v  │  b  │       mute       │   │        no         │     n     │  m  │  ,   │  .   │ / │ rsft │
//    └──────────┴───┼──────┼──────┼─────┼─────┼──────────────────┤   ├───────────────────┼───────────┼─────┼──────┼──────┼───┴──────┘
//                   │ lalt │ lgui │ tab │ spc │ LT(_LEFT_1, esc) │   │ LT(_RIGHT_1, ent) │ bACKSPACE │ esc │ ralt │ rgui │
//                   └──────┴──────┴─────┴─────┴──────────────────┘   └───────────────────┴───────────┴─────┴──────┴──────┘
[_QWERTY] = LAYOUT(
  DE_CIRC , KC_1 , KC_2    , KC_3    , KC_4   , KC_5   ,                                                  KC_6         , KC_7   , KC_8    , KC_9    , KC_0    , DE_SS  ,
  KC_TAB  , KC_Q , KC_W    , KC_E    , KC_R   , KC_T   ,                                                  DE_Z         , KC_U   , KC_I    , KC_O    , KC_P    , DE_UDIA,
  KC_LSFT , KC_A , KC_S    , KC_D    , KC_F   , KC_G   ,                                                  KC_H         , KC_J   , KC_K    , KC_L    , DE_ODIA , DE_ADIA,
  KC_LCTL , DE_Y , KC_X    , KC_C    , KC_V   , KC_B   , KC_MUTE             ,     XXXXXXX              , KC_N         , KC_M   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT,
                   KC_LALT , KC_LGUI , KC_TAB , KC_SPC , LT(_LEFT_1, KC_ESC) ,     LT(_RIGHT_1, KC_ENT) , KC_BACKSPACE , KC_ESC , KC_RALT , KC_RGUI
),

//    ┌──────────┬───┬──────┬──────┬─────┬─────┐                                          ┌───────────┬─────┬──────┬──────┬───┬──────┐
//    │ ^ (dead) │ 1 │  2   │  3   │  4  │  5  │                                          │     6     │  7  │  8   │  9   │ 0 │  ß   │
//    ├──────────┼───┼──────┼──────┼─────┼─────┤                                          ├───────────┼─────┼──────┼──────┼───┼──────┤
//    │   esc    │ q │  w   │  f   │  p  │  b  │                                          │     j     │  l  │  u   │  y   │ ; │ bspc │
//    ├──────────┼───┼──────┼──────┼─────┼─────┤                                          ├───────────┼─────┼──────┼──────┼───┼──────┤
//    │   tab    │ a │  r   │  s   │  t  │  g  │                                          │     m     │  n  │  e   │  i   │ o │  '   │
//    ├──────────┼───┼──────┼──────┼─────┼─────┼──────────────────┐   ┌───────────────────┼───────────┼─────┼──────┼──────┼───┼──────┤
//    │   lsft   │ z │  x   │  c   │  d  │  v  │       mute       │   │        no         │     k     │  h  │  ,   │  .   │ / │ rsft │
//    └──────────┴───┼──────┼──────┼─────┼─────┼──────────────────┤   ├───────────────────┼───────────┼─────┼──────┼──────┼───┴──────┘
//                   │ lalt │ lgui │ tab │ spc │ LT(_LEFT_1, esc) │   │ LT(_RIGHT_1, ent) │ bACKSPACE │ esc │ ralt │ rgui │
//                   └──────┴──────┴─────┴─────┴──────────────────┘   └───────────────────┴───────────┴─────┴──────┴──────┘
[_COLEMAK] = LAYOUT(
  DE_CIRC , KC_1 , KC_2    , KC_3    , KC_4   , KC_5   ,                                                  KC_6         , KC_7   , KC_8    , KC_9    , KC_0    , DE_SS  ,
  KC_ESC  , KC_Q , KC_W    , KC_F    , KC_P   , KC_B   ,                                                  KC_J         , KC_L   , KC_U    , KC_Y    , DE_ODIA , DE_UDIA,
  KC_TAB  , KC_A , KC_R    , KC_S    , KC_T   , KC_G   ,                                                  KC_M         , KC_N   , KC_E    , KC_I    , KC_O    , DE_ADIA,
  KC_LSFT , KC_Z , KC_X    , KC_C    , KC_D   , KC_V   , KC_MUTE             ,     XXXXXXX              , KC_K         , KC_H   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT,
                   KC_LALT , KC_LGUI , KC_TAB , KC_SPC , LT(_LEFT_1, KC_ESC) ,     LT(_RIGHT_1, KC_ENT) , KC_BACKSPACE , KC_ESC , KC_RALT , KC_RGUI
),

//    ┌─────┬────┬─────┬─────┬─────┬─────┐                        ┌─────┬─────┬─────┬─────┬─────────────┬─────┐
//    │     │ f1 │ f2  │ f3  │ f4  │ f5  │                        │ f6  │ f7  │ f8  │ f9  │     f10     │ f11 │
//    ├─────┼────┼─────┼─────┼─────┼─────┤                        ├─────┼─────┼─────┼─────┼─────────────┼─────┤
//    │  `  │ 1  │  2  │  3  │  4  │  5  │                        │  6  │  7  │  8  │  9  │      0      │ f12 │
//    ├─────┼────┼─────┼─────┼─────┼─────┤                        ├─────┼─────┼─────┼─────┼─────────────┼─────┤
//    │     │ !  │  @  │  #  │  $  │  %  │                        │  ^  │  &  │  *  │  (  │      )      │  |  │
//    ├─────┼────┼─────┼─────┼─────┼─────┼──────┐   ┌─────────────┼─────┼─────┼─────┼─────┼─────────────┼─────┤
//    │     │ =  │  -  │  +  │  {  │  }  │ mply │   │             │  [  │  ]  │  ;  │  :  │ (backslash) │     │
//    └─────┴────┼─────┼─────┼─────┼─────┼──────┤   ├─────────────┼─────┼─────┼─────┼─────┼─────────────┴─────┘
//               │     │     │     │     │      │   │ MO(_ADJUST) │     │     │     │     │
//               └─────┴─────┴─────┴─────┴──────┘   └─────────────┴─────┴─────┴─────┴─────┘
[_LEFT_1] = LAYOUT(
  _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                             KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11 ,
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                             KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_F12 ,
  _______ , DE_EXLM , DE_AT   , DE_HASH , DE_DLR  , DE_PERC ,                             DE_CIRC , DE_AMPR , DE_ASTR , DE_LPRN , DE_RPRN , DE_PIPE,
  _______ , DE_EQL  , DE_MINS , DE_PLUS , DE_LCBR , DE_RCBR , KC_MPLY ,     _______     , DE_LBRC , DE_RBRC , DE_LABK , DE_RABK , DE_BSLS , _______,
                      _______ , _______ , _______ , _______ , _______ ,     MO(_ADJUST) , _______ , _______ , _______ , _______
),

//    ┌─────┬──────┬──────┬──────┬──────┬──────┐                       ┌──────┬───────┬─────┬───────┬─────────┬──────┐
//    │     │      │      │      │      │      │                       │      │       │     │       │         │      │
//    ├─────┼──────┼──────┼──────┼──────┼──────┤                       ├──────┼───────┼─────┼───────┼─────────┼──────┤
//    │     │ ins  │ pscr │ app  │  no  │  no  │                       │ pgup │ pRVWD │ up  │ nXTWD │ C(bspc) │ bspc │
//    ├─────┼──────┼──────┼──────┼──────┼──────┤                       ├──────┼───────┼─────┼───────┼─────────┼──────┤
//    │     │ lalt │ lctl │ lsft │  no  │ caps │                       │ left │ down  │ up  │ rght  │   del   │ bspc │
//    ├─────┼──────┼──────┼──────┼──────┼──────┼─────────────┐   ┌─────┼──────┼───────┼─────┼───────┼─────────┼──────┤
//    │     │ C(z) │ C(x) │ C(c) │ C(v) │  no  │             │   │     │  no  │ lSTRT │ no  │ lEND  │   no    │      │
//    └─────┴──────┼──────┼──────┼──────┼──────┼─────────────┤   ├─────┼──────┼───────┼─────┼───────┼─────────┴──────┘
//                 │      │      │      │      │ MO(_ADJUST) │   │     │      │       │     │       │
//                 └──────┴──────┴──────┴──────┴─────────────┘   └─────┴──────┴───────┴─────┴───────┘
[_RIGHT_1] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______ ,                             _______ , _______  , _______ , _______  , _______    , _______,
  _______ , KC_INS  , KC_PSCR , KC_APP  , XXXXXXX , XXXXXXX ,                             KC_PGUP , KC_PRVWD , KC_UP   , KC_NXTWD , C(KC_BSPC) , KC_BSPC,
  _______ , KC_LALT , KC_LCTL , KC_LSFT , XXXXXXX , KC_CAPS ,                             KC_LEFT , KC_DOWN  , KC_UP   , KC_RGHT  , KC_DEL     , KC_BSPC,
  _______ , C(KC_Z) , C(KC_X) , C(KC_C) , C(KC_V) , XXXXXXX , MS_BTN1     ,     MS_BTN2 , XXXXXXX , KC_LSTRT , XXXXXXX , KC_LEND  , XXXXXXX    , _______,
                      _______ , _______ , _______ , _______ , MO(_ADJUST) ,     _______ , _______ , _______  , _______ , _______
),

//    ┌─────────┬────┬─────────┬─────────┬─────────┬─────┐               ┌─────┬──────┬──────┬──────┬────┬────┐
//    │   no    │ no │   no    │   no    │   no    │ no  │               │ no  │  no  │  no  │  no  │ no │ no │
//    ├─────────┼────┼─────────┼─────────┼─────────┼─────┤               ├─────┼──────┼──────┼──────┼────┼────┤
//    │ QK_BOOT │ no │ qWERTY  │ cOLEMAK │ CG_TOGG │ no  │               │ no  │  no  │  no  │  no  │ no │ no │
//    ├─────────┼────┼─────────┼─────────┼─────────┼─────┤               ├─────┼──────┼──────┼──────┼────┼────┤
//    │   no    │ no │ CG_TOGG │   no    │   no    │ no  │               │ no  │ vold │ mute │ volu │ no │ no │
//    ├─────────┼────┼─────────┼─────────┼─────────┼─────┼─────┐   ┌─────┼─────┼──────┼──────┼──────┼────┼────┤
//    │   no    │ no │   no    │   no    │   no    │ no  │ no  │   │ no  │ no  │ mprv │ mply │ mnxt │ no │ no │
//    └─────────┴────┼─────────┼─────────┼─────────┼─────┼─────┤   ├─────┼─────┼──────┼──────┼──────┼────┴────┘
//                   │         │         │         │     │     │   │     │     │      │      │      │
//                   └─────────┴─────────┴─────────┴─────┴─────┘   └─────┴─────┴──────┴──────┴──────┘
[_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX , XXXXXXX   , XXXXXXX    , XXXXXXX , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  QK_BOOT , XXXXXXX , KC_QWERTY , KC_COLEMAK , CG_TOGG , XXXXXXX ,                         XXXXXXX , KC_VOLD , KC_MUTE , KC_VOLU , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , CG_TOGG   , XXXXXXX    , XXXXXXX , XXXXXXX ,                         MS_LEFT , MS_DOWN , MS_UP, MS_RGHT , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX   , XXXXXXX    , XXXXXXX , XXXXXXX , MS_BTN1 ,     MS_BTN2 , XXXXXXX , KC_MPRV , KC_MPLY , KC_MNXT , XXXXXXX , XXXXXXX,
                      _______   , _______    , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
)
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
    }
    return true;
}

#if defined(ENCODER_MAP_ENABLE)
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD),  ENCODER_CCW_CW(QK_MOUSE_WHEEL_DOWN, QK_MOUSE_WHEEL_UP)  },
    [_COLEMAK] = { ENCODER_CCW_CW(UG_HUED, UG_HUEU),  ENCODER_CCW_CW(UG_SATD, UG_SATU)  },
    [_LEFT_1] = { ENCODER_CCW_CW(KC_MNXT, KC_MPRV),  ENCODER_CCW_CW(UG_SPDD, UG_SPDU)  },
    [_RIGHT_1] = { ENCODER_CCW_CW(MS_RGHT, MS_LEFT),  ENCODER_CCW_CW(MS_DOWN, MS_UP) },
    [_ADJUST] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
// clang-format on
#endif
