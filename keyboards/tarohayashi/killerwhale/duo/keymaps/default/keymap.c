// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "lib/add_keycodes.h"
#include "lib/add_shingeta.h"

combo_t key_combos[] = {
};

// レイヤー名
enum layer_number {
    BASE = 0,
    SHINGETA,
    ONOFF, OFFON,                       // トグルスイッチで変更するレイヤー
    LOWER, UPPER, QWERTY,                       // 長押しで変更するレイヤー
    MOUSE, BALL_SETTINGS, LIGHT_SETTINGS // 自動マウスレイヤー切り替えや設定用のレイヤー
};

// キーマップの設定
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // MTGAP Thumbshift
  [BASE] = LAYOUT(
        // 左手
        // 天面スイッチ
        KC_ESC,  KC_1,  KC_2, KC_3, LT(BALL_SETTINGS, KC_4), LT(LIGHT_SETTINGS, KC_5),
        KC_TAB,  KC_Y,  KC_P, KC_O,  KC_U,  KC_J,
        CMD_CTL, KC_I,  KC_N, KC_E,  KC_A,  KC_SCLN,
                 KC_Q,  KC_Z, KC_COMM, KC_DOT, KC_SLSH,
                               MOD_SCRL,
        // 側面スイッチ
        KC_LNG2, KC_SPC,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,         L_CHMOD,
        // 追加スイッチ                             // トグルスイッチ
        KC_MS_BTN2, KC_MS_BTN1,                    MO(ONOFF),
        // 右手
        LT(LIGHT_SETTINGS, KC_6), LT(BALL_SETTINGS, KC_7), KC_8, KC_9, KC_0, KC_BSPC,
        KC_K, KC_D, KC_L, KC_C,  KC_W, KC_ENT,
        KC_M, KC_H, KC_T, KC_S,  KC_R, KC_RSFT,
        KC_B, KC_F, KC_G, KC_V,  KC_X,
                             MOD_SCRL,
        KC_SPACE, KC_LNG1,
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,         R_CHMOD,
        KC_MS_BTN1, KC_MS_BTN2,                    MO(OFFON)
    ),
  [SHINGETA] = LAYOUT(
        // 左手
        // 天面スイッチ
        _______,  _______, _______, _______, _______, _______,
        _______,  KC_MINUS, SG_に, SG_は, KC_COMM, SG_ち,
        _______,  SG_の,    SG_と, SG_か, SG_ん, SG_っ,
                  SG_す,    SG_ま, SG_き, SG_る, SG_つ,
                               _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,         _______,
        // 追加スイッチ                             // トグルスイッチ
        _______, _______,                    _______,
        // 右手
        _______, _______, _______, _______, _______, _______,
        SG_ぐ, SG_ば, SG_こ, SG_が,  SG_ひ,    _______,
        SG_く, SG_う, SG_い, SG_し,  SG_な, _______,
        SG_て, SG_た, SG_で, KC_DOT, SG_ぶ,
                             _______,
        _______, _______,
        _______, _______, _______, _______,         _______,
        _______, _______,                    _______
    ),
  [QWERTY] = LAYOUT(
        // 左手
        // 天面スイッチ
        _______,  _______, _______, _______, _______, _______,
        _______,  KC_Q, KC_W, KC_E, KC_R, KC_T,
        _______,  KC_A, KC_S, KC_D, KC_F, KC_G,
                  KC_Z, KC_X, KC_C, KC_V, KC_B,
                               _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,         _______,
        // 追加スイッチ                             // トグルスイッチ
        _______, _______,                    _______,
        // 右手
        LT(LIGHT_SETTINGS, KC_6), LT(BALL_SETTINGS, KC_7), KC_8, KC_9, KC_0, _______,
        KC_Y, KC_U, KC_I,    KC_O,   KC_P,    _______,
        KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, _______,
        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                             _______,
        _______, _______,
        _______, _______, _______, _______,         _______,
        _______, _______,                    _______
    ),
    [ONOFF] = LAYOUT(
        // 左手
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,
                          _______,
        _______, _______,
        _______, _______, _______, _______,          _______,
        _______, _______,                            _______,
        // 右手
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                   _______,
        _______, _______,
        _______, _______, _______, _______,          _______,
        _______, _______,                            _______
    ),
    [OFFON] = LAYOUT(
        // 左手
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,
                          _______,
        _______, _______,
        _______, _______, _______, _______,          _______,
        _______, _______,                            _______,
        // 右手
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                   _______,
        _______, _______,
        _______, _______, _______, _______,          _______,
        _______, _______,                            _______
    ),
    [MOUSE] = LAYOUT(
        // 左手
        _______, _______, _______, _______, _______,    _______,
        _______, _______, _______, _______, _______,    _______,
        _______, _______, _______, KC_MS_BTN2, KC_MS_BTN1, MOD_SCRL,
                 QK_USER_4, _______, _______, _______, _______,
                          MOD_SCRL,
        _______, _______,
        _______, _______, _______, _______,          _______,
        _______, _______,                            _______,
        // 右手
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        MOD_SCRL, KC_MS_BTN1, KC_MS_BTN2, _______, _______, _______,
        _______, _______, _______, _______, QK_USER_4,
                                   MOD_SCRL,
        _______, _______,
        _______, _______, _______, _______,          _______,
        _______, _______,                            _______
    ),
    [BALL_SETTINGS] = LAYOUT(
        // 左手
        XXXXXXX,    XXXXXXX, XXXXXXX, QK_USER_14, _______, L_CHMOD,
        XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, L_SPD_I, XXXXXXX,
        AUTO_MOUSE, XXXXXXX, XXXXXXX, L_ANG_D, L_INV,   L_ANG_I,
                    XXXXXXX, XXXXXXX,XXXXXXX, L_SPD_D, XXXXXXX,
                             INV_SCRL,
        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, INV_SCRL,                           XXXXXXX,
        // 右手
        R_CHMOD, _______, QK_USER_14, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, R_SPD_I,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        R_ANG_D, R_INV,   R_ANG_I, XXXXXXX, XXXXXXX, AUTO_MOUSE,
        XXXXXXX, R_SPD_D,   XXXXXXX, XXXXXXX, XXXXXXX,
                                     INV_SCRL,
        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX,                            XXXXXXX
    ),
    [LIGHT_SETTINGS] = LAYOUT(
        // 左手
        XXXXXXX, XXXXXXX, XXXXXXX, UG_NEXT, UG_PREV, _______,
        XXXXXXX, UG_SPDU, UG_VALU, UG_SATU, UG_HUEU, UG_TOGG,
        OLED_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 UG_SPDD, UG_VALD, UG_SATD, UG_HUED, XXXXXXX,
                          QK_USER_15,
        UG_NEXT, UG_PREV,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX,                            XXXXXXX,
        // 右手
        _______, UG_NEXT, UG_PREV, XXXXXXX, XXXXXXX, XXXXXXX,
        UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, UG_SPDU, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OLED_MOD,
        XXXXXXX, UG_HUED, UG_SATD, UG_VALD, UG_SPDD,
                                   QK_USER_15,
        UG_PREV, UG_NEXT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX,                            XXXXXXX
    )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] =   {
        ENCODER_CCW_CW(KC_ESC, KC_TAB),
        ENCODER_CCW_CW(REDO, UNDO),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_DEL, KC_BSPC),
        ENCODER_CCW_CW(KC_UP, KC_DOWN),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
    },
    [LIGHT_SETTINGS] =   {
        ENCODER_CCW_CW(UG_SPDU, UG_SPDD),
        ENCODER_CCW_CW(UG_VALU, UG_VALD),
        ENCODER_CCW_CW(UG_SATU, UG_SATD),
        ENCODER_CCW_CW(UG_HUEU, UG_HUED),
        ENCODER_CCW_CW(UG_SPDU, UG_SPDD),
        ENCODER_CCW_CW(UG_VALU, UG_VALD),
        ENCODER_CCW_CW(UG_SATU, UG_SATD),
        ENCODER_CCW_CW(UG_HUEU, UG_HUED),
    },
};


void layer_on_qwerty_when_modifier(keyrecord_t *record) {

    if (record->event.pressed) {
        layer_on(QWERTY);
    } else {
        layer_off(QWERTY);
    }

};

bool process_record_user(uint16_t keycode, keyrecord_t *record){

    switch (keycode) {
        case KC_LEFT_CTRL:
            layer_on_qwerty_when_modifier(record);
            break;
        case KC_LEFT_ALT:
            layer_on_qwerty_when_modifier(record);
            break;
        case KC_LEFT_GUI:
            layer_on_qwerty_when_modifier(record);
            break;
        case KC_LEFT_SHIFT:
            if ( BASE != get_highest_layer(layer_state)) {
                layer_on_qwerty_when_modifier(record);
            }
            break;
        case KC_RIGHT_CTRL:
            layer_on_qwerty_when_modifier(record);
            break;
        case KC_RIGHT_ALT:
            layer_on_qwerty_when_modifier(record);
            break;
        case KC_RIGHT_GUI:
            layer_on_qwerty_when_modifier(record);
            break;
        case KC_RIGHT_SHIFT:
            if ( BASE != get_highest_layer(layer_state)) {
                layer_on_qwerty_when_modifier(record);
            }
            break;
        case KC_ESC:
            layer_on(SHINGETA);
            break;
    }

    return true;
};

