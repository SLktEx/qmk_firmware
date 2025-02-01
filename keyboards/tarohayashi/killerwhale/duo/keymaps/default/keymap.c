// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "lib/add_keycodes.h"
#include "lib/add_shingeta.h"
#include "lib/add_ichikawa.h"
uint16_t startup_timer;

#define TAP_TERM_KEYMAP 100

enum KEYMAP_keycodes{
    KM_TOGGLE_SWITCH_RIGHT = IK_LAST,
    KM_TOGGLE_SWITCH_LEFT,
    KM_SYMBOL_QUOT,
    KM_SYMBOL_BSPC,
    KM_SYMBOL_SPC,
    KM_ICHIKAWA_ENT,
    KM_ICHIKAWA_GUI,
    KM_ICHIKAWA_TAB,
    KM_NUM_ENT,
    KM_NUM_GUI,
    KM_NUM_TAB,
};


// レイヤー名
enum layer_number {
    BASE = 0,
    SHINGETA,
    QWERTY, ONLY_QWERTY,                       // トグルスイッチで変更するレイヤー
    SYMBOL, NUM, ICHIKAWA,                       // 長押しで変更するレイヤー
    MOUSE, BALL_SETTINGS, LIGHT_SETTINGS // 自動マウスレイヤー切り替えや設定用のレイヤー
};

bool toggle_switch_right = false;
bool toggle_switch_left = false;

enum combo_events {
    C_SG_ぁ,
    C_SG_あ,
    C_SG_ぃ,
    C_SG_ぅ,
    C_SG_うぃ,
    C_SG_うぇ,
    C_SG_うぉ,
    C_SG_ぇ,
    C_SG_え,
    C_SG_ぉ,
    C_SG_お,
    C_SG_きゃ,
    C_SG_きゅ,
    C_SG_きょ,
    C_SG_ぎ,
    C_SG_ぎゃ,
    C_SG_ぎゅ,
    C_SG_ぎょ,
    C_SG_ぐぁ,
    C_SG_ぐぃ,
    C_SG_ぐぅ,
    C_SG_ぐぇ,
    C_SG_ぐぉ,
    C_SG_け,
    C_SG_ご,
    C_SG_さ,
    C_SG_ざ,
    C_SG_しぇ,
    C_SG_じぇ,
    C_SG_しゃ,
    C_SG_しゅ,
    C_SG_しょ,
    C_SG_じ,
    C_SG_じゃ,
    C_SG_じゅ,
    C_SG_じょ,
    C_SG_ず,
    C_SG_せ,
    C_SG_ぜ,
    C_SG_そ,
    C_SG_ぞ,
    C_SG_だ,
    C_SG_ちぇ,
    C_SG_ちゃ,
    C_SG_ちゅ,
    C_SG_ちょ,
    C_SG_ぢ,
    C_SG_ぢゃ,
    C_SG_ぢゅ,
    C_SG_ぢょ,
    C_SG_づ,
    C_SG_てぃ,
    C_SG_でぃ,
    C_SG_ど,
    C_SG_にゃ,
    C_SG_にゅ,
    C_SG_にょ,
    C_SG_ぬ,
    C_SG_ね,
    C_SG_ぱ,
    C_SG_ひゃ,
    C_SG_ひゅ,
    C_SG_ひょ,
    C_SG_び,
    C_SG_びゃ,
    C_SG_びゅ,
    C_SG_びょ,
    C_SG_ぴ,
    C_SG_ぴゃ,
    C_SG_ぴゅ,
    C_SG_ぴょ,
    C_SG_ふ,
    C_SG_ふぁ,
    C_SG_ふぃ,
    C_SG_ふぇ,
    C_SG_ふぉ,
    C_SG_ぷ,
    C_SG_へ,
    C_SG_べ,
    C_SG_ぺ,
    C_SG_ほ,
    C_SG_ぼ,
    C_SG_ぽ,
    C_SG_み,
    C_SG_みゃ,
    C_SG_みゅ,
    C_SG_みょ,
    C_SG_む,
    C_SG_め,
    C_SG_も,
    C_SG_ゃ,
    C_SG_や,
    C_SG_ゅ,
    C_SG_ゆ,
    C_SG_ょ,
    C_SG_よ,
    C_SG_ら,
    C_SG_り,
    C_SG_りゃ,
    C_SG_りゅ,
    C_SG_りょ,
    C_SG_れ,
    C_SG_ろ,
    C_SG_ゎ,
    C_SG_わ,
    C_SG_を,
    C_SG_ヴ,

    // win -> ctrl + shift
    QUOT_Ctrl_Shift,
    BSPC_Ctrl_Shift,
    SPC_Ctrl_Shift,
    LNG2_Ctrl_Shift,
};

const uint16_t PROGMEM C_SG_ぁ_COMBO[] = {SG_ぐ, SG_は, COMBO_END};
const uint16_t PROGMEM C_SG_あ_COMBO[] = {SG_う, SG_か, COMBO_END};
const uint16_t PROGMEM C_SG_ぃ_COMBO[] = {SG_く, SG_は, COMBO_END};
const uint16_t PROGMEM C_SG_ぅ_COMBO[] = {SG_て, SG_は, COMBO_END};
const uint16_t PROGMEM C_SG_うぃ_COMBO[] = {SG_ぐ, SG_か, COMBO_END};
const uint16_t PROGMEM C_SG_うぇ_COMBO[] = {SG_ひ, SG_か, COMBO_END};
const uint16_t PROGMEM C_SG_うぉ_COMBO[] = {SG_う, SG_は, COMBO_END};
const uint16_t PROGMEM C_SG_ぇ_COMBO[] = {SG_ば, SG_は, COMBO_END};
const uint16_t PROGMEM C_SG_え_COMBO[] = {SG_な, SG_か, COMBO_END};
const uint16_t PROGMEM C_SG_ぉ_COMBO[] = {SG_た, SG_は, COMBO_END};
const uint16_t PROGMEM C_SG_お_COMBO[] = {SG_し, SG_か, COMBO_END};
const uint16_t PROGMEM C_SG_きゃ_COMBO[] = {SG_る, SG_こ, COMBO_END};
const uint16_t PROGMEM C_SG_きゅ_COMBO[] = {SG_こ, SG_COMM, COMBO_END};
const uint16_t PROGMEM C_SG_きょ_COMBO[] = {SG_ん, SG_こ, COMBO_END};
const uint16_t PROGMEM C_SG_ぎ_COMBO[] = {SG_き, SG_し, COMBO_END};
const uint16_t PROGMEM C_SG_ぎゃ_COMBO[] = {SG_る, SG_が, COMBO_END};
const uint16_t PROGMEM C_SG_ぎゅ_COMBO[] = {SG_COMM, SG_が, COMBO_END};
const uint16_t PROGMEM C_SG_ぎょ_COMBO[] = {SG_ん, SG_が, COMBO_END};
const uint16_t PROGMEM C_SG_ぐぁ_COMBO[] = {SG_ぐ, SG_に, COMBO_END};
const uint16_t PROGMEM C_SG_ぐぃ_COMBO[] = {SG_く, SG_に, COMBO_END};
const uint16_t PROGMEM C_SG_ぐぅ_COMBO[] = {SG_て, SG_に, COMBO_END};
const uint16_t PROGMEM C_SG_ぐぇ_COMBO[] = {SG_ば, SG_に, COMBO_END};
const uint16_t PROGMEM C_SG_ぐぉ_COMBO[] = {SG_う, SG_に, COMBO_END};
const uint16_t PROGMEM C_SG_け_COMBO[] = {SG_し, SG_は, COMBO_END};
const uint16_t PROGMEM C_SG_ご_COMBO[] = {SG_い, SG_に, COMBO_END};
const uint16_t PROGMEM C_SG_さ_COMBO[] = {SG_と, SG_し, COMBO_END};
const uint16_t PROGMEM C_SG_ざ_COMBO[] = {SG_ま, SG_し, COMBO_END};
const uint16_t PROGMEM C_SG_しぇ_COMBO[] = {SG_と, SG_ぐ, COMBO_END};
const uint16_t PROGMEM C_SG_しゃ_COMBO[] = {SG_き, SG_こ, COMBO_END};
const uint16_t PROGMEM C_SG_しゅ_COMBO[] = {SG_に, SG_こ, COMBO_END};
const uint16_t PROGMEM C_SG_しょ_COMBO[] = {SG_は, SG_こ, COMBO_END};
const uint16_t PROGMEM C_SG_じ_COMBO[] = {SG_と, SG_い, COMBO_END};
const uint16_t PROGMEM C_SG_じぇ_COMBO[] = {SG_と, SG_ひ, COMBO_END};
const uint16_t PROGMEM C_SG_じゃ_COMBO[] = {SG_き, SG_が, COMBO_END};
const uint16_t PROGMEM C_SG_じゅ_COMBO[] = {SG_に, SG_が, COMBO_END};
const uint16_t PROGMEM C_SG_じょ_COMBO[] = {SG_は, SG_が, COMBO_END};
const uint16_t PROGMEM C_SG_ず_COMBO[] = {SG_っ, SG_し, COMBO_END};
const uint16_t PROGMEM C_SG_せ_COMBO[] = {SG_て, SG_か, COMBO_END};
const uint16_t PROGMEM C_SG_ぜ_COMBO[] = {SG_す, SG_し, COMBO_END};
const uint16_t PROGMEM C_SG_そ_COMBO[] = {SG_な, SG_と, COMBO_END};
const uint16_t PROGMEM C_SG_ぞ_COMBO[] = {SG_ま, SG_い, COMBO_END};
const uint16_t PROGMEM C_SG_だ_COMBO[] = {SG_た, SG_と, COMBO_END};
const uint16_t PROGMEM C_SG_ちぇ_COMBO[] = {SG_ぶ, SG_と, COMBO_END};
const uint16_t PROGMEM C_SG_ちゃ_COMBO[] = {SG_つ, SG_こ, COMBO_END};
const uint16_t PROGMEM C_SG_ちゅ_COMBO[] = {SG_ち, SG_こ, COMBO_END};
const uint16_t PROGMEM C_SG_ちょ_COMBO[] = {SG_っ, SG_こ, COMBO_END};
const uint16_t PROGMEM C_SG_ぢ_COMBO[] = {SG_し, SG_げ, COMBO_END};
const uint16_t PROGMEM C_SG_ぢゃ_COMBO[] = {SG_つ, SG_な, COMBO_END};
const uint16_t PROGMEM C_SG_ぢゅ_COMBO[] = {SG_ち, SG_な, COMBO_END};
const uint16_t PROGMEM C_SG_ぢょ_COMBO[] = {SG_っ, SG_な, COMBO_END};
const uint16_t PROGMEM C_SG_づ_COMBO[] = {SG_い, SG_す, COMBO_END};
const uint16_t PROGMEM C_SG_てぃ_COMBO[] = {SG_し, SG_COMM, COMBO_END};
const uint16_t PROGMEM C_SG_でぃ_COMBO[] = {SG_ち, SG_し, COMBO_END};
const uint16_t PROGMEM C_SG_ど_COMBO[] = {SG_と, SG_こ, COMBO_END};
const uint16_t PROGMEM C_SG_にゃ_COMBO[] = {SG_つ, SG_が, COMBO_END};
const uint16_t PROGMEM C_SG_にゅ_COMBO[] = {SG_ち, SG_が, COMBO_END};
const uint16_t PROGMEM C_SG_にょ_COMBO[] = {SG_っ, SG_が, COMBO_END};
const uint16_t PROGMEM C_SG_ぬ_COMBO[] = {SG_つ, SG_し, COMBO_END};
const uint16_t PROGMEM C_SG_ね_COMBO[] = {SG_た, SG_か, COMBO_END};
const uint16_t PROGMEM C_SG_ぱ_COMBO[] = {SG_ば, SG_か, COMBO_END};
const uint16_t PROGMEM C_SG_ひゃ_COMBO[] = {SG_す, SG_こ, COMBO_END};
const uint16_t PROGMEM C_SG_ひゅ_COMBO[] = {SG_げ, SG_こ, COMBO_END};
const uint16_t PROGMEM C_SG_ひょ_COMBO[] = {SG_の, SG_こ, COMBO_END};
const uint16_t PROGMEM C_SG_び_COMBO[] = {SG_と, SG_く, COMBO_END};
const uint16_t PROGMEM C_SG_びゃ_COMBO[] = {SG_る, SG_な, COMBO_END};
const uint16_t PROGMEM C_SG_びゅ_COMBO[] = {SG_COMM, SG_な, COMBO_END};
const uint16_t PROGMEM C_SG_びょ_COMBO[] = {SG_ん, SG_な, COMBO_END};
const uint16_t PROGMEM C_SG_ぴ_COMBO[] = {SG_で, SG_と, COMBO_END};
const uint16_t PROGMEM C_SG_ぴゃ_COMBO[] = {SG_き, SG_な, COMBO_END};
const uint16_t PROGMEM C_SG_ぴゅ_COMBO[] = {SG_に, SG_な, COMBO_END};
const uint16_t PROGMEM C_SG_ぴょ_COMBO[] = {SG_は, SG_な, COMBO_END};
const uint16_t PROGMEM C_SG_ふ_COMBO[] = {SG_は, SG_い, COMBO_END};
const uint16_t PROGMEM C_SG_ふぁ_COMBO[] = {SG_げ, SG_い, COMBO_END};
const uint16_t PROGMEM C_SG_ふぃ_COMBO[] = {SG_い, SG_COMM, COMBO_END};
const uint16_t PROGMEM C_SG_ふぇ_COMBO[] = {SG_い, SG_ち, COMBO_END};
const uint16_t PROGMEM C_SG_ふぉ_COMBO[] = {SG_つ, SG_い, COMBO_END};
const uint16_t PROGMEM C_SG_ぷ_COMBO[] = {SG_DOT, SG_か, COMBO_END};
const uint16_t PROGMEM C_SG_へ_COMBO[] = {SG_く, SG_か, COMBO_END};
const uint16_t PROGMEM C_SG_べ_COMBO[] = {SG_で, SG_か, COMBO_END};
const uint16_t PROGMEM C_SG_ぺ_COMBO[] = {SG_ば, SG_と, COMBO_END};
const uint16_t PROGMEM C_SG_ほ_COMBO[] = {SG_い, SG_の, COMBO_END};
const uint16_t PROGMEM C_SG_ぼ_COMBO[] = {SG_き, SG_い, COMBO_END};
const uint16_t PROGMEM C_SG_ぽ_COMBO[] = {SG_DOT, SG_と, COMBO_END};
const uint16_t PROGMEM C_SG_み_COMBO[] = {SG_か, SG_が, COMBO_END};
const uint16_t PROGMEM C_SG_みゃ_COMBO[] = {SG_す, SG_な, COMBO_END};
const uint16_t PROGMEM C_SG_みゅ_COMBO[] = {SG_げ, SG_な, COMBO_END};
const uint16_t PROGMEM C_SG_みょ_COMBO[] = {SG_の, SG_な, COMBO_END};
const uint16_t PROGMEM C_SG_む_COMBO[] = {SG_い, SG_る, COMBO_END};
const uint16_t PROGMEM C_SG_め_COMBO[] = {SG_に, SG_し, COMBO_END};
const uint16_t PROGMEM C_SG_も_COMBO[] = {SG_い, SG_ん, COMBO_END};
const uint16_t PROGMEM C_SG_ゃ_COMBO[] = {SG_ま, SG_こ, COMBO_END};
const uint16_t PROGMEM C_SG_や_COMBO[] = {SG_と, SG_が, COMBO_END};
const uint16_t PROGMEM C_SG_ゅ_COMBO[] = {SG_ま, SG_が, COMBO_END};
const uint16_t PROGMEM C_SG_ゆ_COMBO[] = {SG_っ, SG_い, COMBO_END};
const uint16_t PROGMEM C_SG_ょ_COMBO[] = {SG_ま, SG_な, COMBO_END};
const uint16_t PROGMEM C_SG_よ_COMBO[] = {SG_か, SG_こ, COMBO_END};
const uint16_t PROGMEM C_SG_ら_COMBO[] = {SG_と, SG_う, COMBO_END};
const uint16_t PROGMEM C_SG_り_COMBO[] = {SG_し, SG_ん, COMBO_END};
const uint16_t PROGMEM C_SG_りゃ_COMBO[] = {SG_す, SG_が, COMBO_END};
const uint16_t PROGMEM C_SG_りゅ_COMBO[] = {SG_が, SG_げ, COMBO_END};
const uint16_t PROGMEM C_SG_りょ_COMBO[] = {SG_の, SG_が, COMBO_END};
const uint16_t PROGMEM C_SG_れ_COMBO[] = {SG_い, SG_か, COMBO_END};
const uint16_t PROGMEM C_SG_ろ_COMBO[] = {SG_る, SG_し, COMBO_END};
const uint16_t PROGMEM C_SG_ゎ_COMBO[] = {SG_ひ, SG_は, COMBO_END};
const uint16_t PROGMEM C_SG_わ_COMBO[] = {SG_て, SG_と, COMBO_END};
const uint16_t PROGMEM C_SG_を_COMBO[] = {SG_し, SG_の, COMBO_END};
const uint16_t PROGMEM C_SG_ヴ_COMBO[] = {SG_ぶ, SG_か, COMBO_END};

// win -> ctrl + shift
const uint16_t PROGMEM QUOT_Ctrl_Shift_COMBO[] = {IK_GUI, C_S_T(KC_QUOT), COMBO_END};
const uint16_t PROGMEM BSPC_Ctrl_Shift_COMBO[] = {IK_GUI, LT(ICHIKAWA,KC_BSPC), COMBO_END};
const uint16_t PROGMEM SPC_Ctrl_Shift_COMBO[] = {IK_GUI, LSFT_T(KC_SPC), COMBO_END};


combo_t key_combos[] = {
    [C_SG_ぁ] = COMBO_ACTION(C_SG_ぁ_COMBO),
    [C_SG_あ] = COMBO_ACTION(C_SG_あ_COMBO),
    [C_SG_ぃ] = COMBO_ACTION(C_SG_ぃ_COMBO),
    [C_SG_ぅ] = COMBO_ACTION(C_SG_ぅ_COMBO),
    [C_SG_うぃ] = COMBO_ACTION(C_SG_うぃ_COMBO),
    [C_SG_うぇ] = COMBO_ACTION(C_SG_うぇ_COMBO),
    [C_SG_うぉ] = COMBO_ACTION(C_SG_うぉ_COMBO),
    [C_SG_ぇ] = COMBO_ACTION(C_SG_ぇ_COMBO),
    [C_SG_え] = COMBO_ACTION(C_SG_え_COMBO),
    [C_SG_ぉ] = COMBO_ACTION(C_SG_ぉ_COMBO),
    [C_SG_お] = COMBO_ACTION(C_SG_お_COMBO),
    [C_SG_きゃ] = COMBO_ACTION(C_SG_きゃ_COMBO),
    [C_SG_きゅ] = COMBO_ACTION(C_SG_きゅ_COMBO),
    [C_SG_きょ] = COMBO_ACTION(C_SG_きょ_COMBO),
    [C_SG_ぎ] = COMBO_ACTION(C_SG_ぎ_COMBO),
    [C_SG_ぎゃ] = COMBO_ACTION(C_SG_ぎゃ_COMBO),
    [C_SG_ぎゅ] = COMBO_ACTION(C_SG_ぎゅ_COMBO),
    [C_SG_ぎょ] = COMBO_ACTION(C_SG_ぎょ_COMBO),
    [C_SG_ぐぁ] = COMBO_ACTION(C_SG_ぐぁ_COMBO),
    [C_SG_ぐぃ] = COMBO_ACTION(C_SG_ぐぃ_COMBO),
    [C_SG_ぐぅ] = COMBO_ACTION(C_SG_ぐぅ_COMBO),
    [C_SG_ぐぇ] = COMBO_ACTION(C_SG_ぐぇ_COMBO),
    [C_SG_ぐぉ] = COMBO_ACTION(C_SG_ぐぉ_COMBO),
    [C_SG_け] = COMBO_ACTION(C_SG_け_COMBO),
    [C_SG_ご] = COMBO_ACTION(C_SG_ご_COMBO),
    [C_SG_さ] = COMBO_ACTION(C_SG_さ_COMBO),
    [C_SG_ざ] = COMBO_ACTION(C_SG_ざ_COMBO),
    [C_SG_しぇ] = COMBO_ACTION(C_SG_しぇ_COMBO),
    [C_SG_しゃ] = COMBO_ACTION(C_SG_しゃ_COMBO),
    [C_SG_しゅ] = COMBO_ACTION(C_SG_しゅ_COMBO),
    [C_SG_しょ] = COMBO_ACTION(C_SG_しょ_COMBO),
    [C_SG_じ] = COMBO_ACTION(C_SG_じ_COMBO),
    [C_SG_じぇ] = COMBO_ACTION(C_SG_じぇ_COMBO),
    [C_SG_じゃ] = COMBO_ACTION(C_SG_じゃ_COMBO),
    [C_SG_じゅ] = COMBO_ACTION(C_SG_じゅ_COMBO),
    [C_SG_じょ] = COMBO_ACTION(C_SG_じょ_COMBO),
    [C_SG_ず] = COMBO_ACTION(C_SG_ず_COMBO),
    [C_SG_せ] = COMBO_ACTION(C_SG_せ_COMBO),
    [C_SG_ぜ] = COMBO_ACTION(C_SG_ぜ_COMBO),
    [C_SG_そ] = COMBO_ACTION(C_SG_そ_COMBO),
    [C_SG_ぞ] = COMBO_ACTION(C_SG_ぞ_COMBO),
    [C_SG_だ] = COMBO_ACTION(C_SG_だ_COMBO),
    [C_SG_ちぇ] = COMBO_ACTION(C_SG_ちぇ_COMBO),
    [C_SG_ちゃ] = COMBO_ACTION(C_SG_ちゃ_COMBO),
    [C_SG_ちゅ] = COMBO_ACTION(C_SG_ちゅ_COMBO),
    [C_SG_ちょ] = COMBO_ACTION(C_SG_ちょ_COMBO),
    [C_SG_ぢ] = COMBO_ACTION(C_SG_ぢ_COMBO),
    [C_SG_ぢゃ] = COMBO_ACTION(C_SG_ぢゃ_COMBO),
    [C_SG_ぢゅ] = COMBO_ACTION(C_SG_ぢゅ_COMBO),
    [C_SG_ぢょ] = COMBO_ACTION(C_SG_ぢょ_COMBO),
    [C_SG_づ] = COMBO_ACTION(C_SG_づ_COMBO),
    [C_SG_てぃ] = COMBO_ACTION(C_SG_てぃ_COMBO),
    [C_SG_でぃ] = COMBO_ACTION(C_SG_でぃ_COMBO),
    [C_SG_ど] = COMBO_ACTION(C_SG_ど_COMBO),
    [C_SG_にゃ] = COMBO_ACTION(C_SG_にゃ_COMBO),
    [C_SG_にゅ] = COMBO_ACTION(C_SG_にゅ_COMBO),
    [C_SG_にょ] = COMBO_ACTION(C_SG_にょ_COMBO),
    [C_SG_ぬ] = COMBO_ACTION(C_SG_ぬ_COMBO),
    [C_SG_ね] = COMBO_ACTION(C_SG_ね_COMBO),
    [C_SG_ぱ] = COMBO_ACTION(C_SG_ぱ_COMBO),
    [C_SG_ひゃ] = COMBO_ACTION(C_SG_ひゃ_COMBO),
    [C_SG_ひゅ] = COMBO_ACTION(C_SG_ひゅ_COMBO),
    [C_SG_ひょ] = COMBO_ACTION(C_SG_ひょ_COMBO),
    [C_SG_び] = COMBO_ACTION(C_SG_び_COMBO),
    [C_SG_びゃ] = COMBO_ACTION(C_SG_びゃ_COMBO),
    [C_SG_びゅ] = COMBO_ACTION(C_SG_びゅ_COMBO),
    [C_SG_びょ] = COMBO_ACTION(C_SG_びょ_COMBO),
    [C_SG_ぴ] = COMBO_ACTION(C_SG_ぴ_COMBO),
    [C_SG_ぴゃ] = COMBO_ACTION(C_SG_ぴゃ_COMBO),
    [C_SG_ぴゅ] = COMBO_ACTION(C_SG_ぴゅ_COMBO),
    [C_SG_ぴょ] = COMBO_ACTION(C_SG_ぴょ_COMBO),
    [C_SG_ふ] = COMBO_ACTION(C_SG_ふ_COMBO),
    [C_SG_ふぁ] = COMBO_ACTION(C_SG_ふぁ_COMBO),
    [C_SG_ふぃ] = COMBO_ACTION(C_SG_ふぃ_COMBO),
    [C_SG_ふぇ] = COMBO_ACTION(C_SG_ふぇ_COMBO),
    [C_SG_ふぉ] = COMBO_ACTION(C_SG_ふぉ_COMBO),
    [C_SG_ぷ] = COMBO_ACTION(C_SG_ぷ_COMBO),
    [C_SG_へ] = COMBO_ACTION(C_SG_へ_COMBO),
    [C_SG_べ] = COMBO_ACTION(C_SG_べ_COMBO),
    [C_SG_ぺ] = COMBO_ACTION(C_SG_ぺ_COMBO),
    [C_SG_ほ] = COMBO_ACTION(C_SG_ほ_COMBO),
    [C_SG_ぼ] = COMBO_ACTION(C_SG_ぼ_COMBO),
    [C_SG_ぽ] = COMBO_ACTION(C_SG_ぽ_COMBO),
    [C_SG_み] = COMBO_ACTION(C_SG_み_COMBO),
    [C_SG_みゃ] = COMBO_ACTION(C_SG_みゃ_COMBO),
    [C_SG_みゅ] = COMBO_ACTION(C_SG_みゅ_COMBO),
    [C_SG_みょ] = COMBO_ACTION(C_SG_みょ_COMBO),
    [C_SG_む] = COMBO_ACTION(C_SG_む_COMBO),
    [C_SG_め] = COMBO_ACTION(C_SG_め_COMBO),
    [C_SG_も] = COMBO_ACTION(C_SG_も_COMBO),
    [C_SG_ゃ] = COMBO_ACTION(C_SG_ゃ_COMBO),
    [C_SG_や] = COMBO_ACTION(C_SG_や_COMBO),
    [C_SG_ゅ] = COMBO_ACTION(C_SG_ゅ_COMBO),
    [C_SG_ゆ] = COMBO_ACTION(C_SG_ゆ_COMBO),
    [C_SG_ょ] = COMBO_ACTION(C_SG_ょ_COMBO),
    [C_SG_よ] = COMBO_ACTION(C_SG_よ_COMBO),
    [C_SG_ら] = COMBO_ACTION(C_SG_ら_COMBO),
    [C_SG_り] = COMBO_ACTION(C_SG_り_COMBO),
    [C_SG_りゃ] = COMBO_ACTION(C_SG_りゃ_COMBO),
    [C_SG_りゅ] = COMBO_ACTION(C_SG_りゅ_COMBO),
    [C_SG_りょ] = COMBO_ACTION(C_SG_りょ_COMBO),
    [C_SG_れ] = COMBO_ACTION(C_SG_れ_COMBO),
    [C_SG_ろ] = COMBO_ACTION(C_SG_ろ_COMBO),
    [C_SG_ゎ] = COMBO_ACTION(C_SG_ゎ_COMBO),
    [C_SG_わ] = COMBO_ACTION(C_SG_わ_COMBO),
    [C_SG_を] = COMBO_ACTION(C_SG_を_COMBO),
    [C_SG_ヴ] = COMBO_ACTION(C_SG_ヴ_COMBO),

    // win -> ctrl + shift
    [QUOT_Ctrl_Shift] = COMBO_ACTION(QUOT_Ctrl_Shift_COMBO),
    [BSPC_Ctrl_Shift] = COMBO_ACTION(BSPC_Ctrl_Shift_COMBO),
    [SPC_Ctrl_Shift] = COMBO_ACTION(SPC_Ctrl_Shift_COMBO),

};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case C_SG_ぁ:
      if (pressed) {
        SEND_STRING("xa");
      }
      break;
    case C_SG_あ:
      if (pressed) {
        SEND_STRING("a");
      }
      break;
    case C_SG_ぃ:
      if (pressed) {
        SEND_STRING("xi");
      }
      break;
    case C_SG_ぅ:
      if (pressed) {
        SEND_STRING("xu");
      }
      break;
    case C_SG_うぃ:
      if (pressed) {
        SEND_STRING("uxi");
      }
      break;
    case C_SG_うぇ:
      if (pressed) {
        SEND_STRING("uxe");
      }
      break;
    case C_SG_うぉ:
      if (pressed) {
        SEND_STRING("uxo");
      }
      break;
    case C_SG_ぇ:
      if (pressed) {
        SEND_STRING("xe");
      }
      break;
    case C_SG_え:
      if (pressed) {
        SEND_STRING("e");
      }
      break;
    case C_SG_ぉ:
      if (pressed) {
        SEND_STRING("xo");
      }
      break;
    case C_SG_お:
      if (pressed) {
        SEND_STRING("o");
      }
      break;
    case C_SG_きゃ:
      if (pressed) {
        SEND_STRING("kya");
      }
      break;
    case C_SG_きゅ:
      if (pressed) {
        SEND_STRING("kyu");
      }
      break;
    case C_SG_きょ:
      if (pressed) {
        SEND_STRING("kyo");
      }
      break;
    case C_SG_ぎ:
      if (pressed) {
        SEND_STRING("gi");
      }
      break;
    case C_SG_ぎゃ:
      if (pressed) {
        SEND_STRING("gya");
      }
      break;
    case C_SG_ぎゅ:
      if (pressed) {
        SEND_STRING("gyu");
      }
      break;
    case C_SG_ぎょ:
      if (pressed) {
        SEND_STRING("gyo");
      }
      break;
    case C_SG_ぐぁ:
      if (pressed) {
        SEND_STRING("gwa");
      }
      break;
    case C_SG_ぐぃ:
      if (pressed) {
        SEND_STRING("gwi");
      }
      break;
    case C_SG_ぐぅ:
      if (pressed) {
        SEND_STRING("gwu");
      }
      break;
    case C_SG_ぐぇ:
      if (pressed) {
        SEND_STRING("gwe");
      }
      break;
    case C_SG_ぐぉ:
      if (pressed) {
        SEND_STRING("gwo");
      }
      break;
    case C_SG_け:
      if (pressed) {
        SEND_STRING("ke");
      }
      break;
    case C_SG_ご:
      if (pressed) {
        SEND_STRING("go");
      }
      break;
    case C_SG_さ:
      if (pressed) {
        SEND_STRING("sa");
      }
      break;
    case C_SG_ざ:
      if (pressed) {
        SEND_STRING("za");
      }
      break;
    case C_SG_しぇ:
      if (pressed) {
        SEND_STRING("sye");
      }
      break;
    case C_SG_しゃ:
      if (pressed) {
        SEND_STRING("sya");
      }
      break;
    case C_SG_しゅ:
      if (pressed) {
        SEND_STRING("syu");
      }
      break;
    case C_SG_しょ:
      if (pressed) {
        SEND_STRING("syo");
      }
      break;
    case C_SG_じ:
      if (pressed) {
        SEND_STRING("zi");
      }
      break;
    case C_SG_じぇ:
      if (pressed) {
        SEND_STRING("zye");
      }
      break;
    case C_SG_じゃ:
      if (pressed) {
        SEND_STRING("zya");
      }
      break;
    case C_SG_じゅ:
      if (pressed) {
        SEND_STRING("zyu");
      }
      break;
    case C_SG_じょ:
      if (pressed) {
        SEND_STRING("zyo");
      }
      break;
    case C_SG_ず:
      if (pressed) {
        SEND_STRING("zu");
      }
      break;
    case C_SG_せ:
      if (pressed) {
        SEND_STRING("se");
      }
      break;
    case C_SG_ぜ:
      if (pressed) {
        SEND_STRING("ze");
      }
      break;
    case C_SG_そ:
      if (pressed) {
        SEND_STRING("so");
      }
      break;
    case C_SG_ぞ:
      if (pressed) {
        SEND_STRING("zo");
      }
      break;
    case C_SG_だ:
      if (pressed) {
        SEND_STRING("da");
      }
      break;
    case C_SG_ちぇ:
      if (pressed) {
        SEND_STRING("tye");
      }
      break;
    case C_SG_ちゃ:
      if (pressed) {
        SEND_STRING("tya");
      }
      break;
    case C_SG_ちゅ:
      if (pressed) {
        SEND_STRING("tyu");
      }
      break;
    case C_SG_ちょ:
      if (pressed) {
        SEND_STRING("tyo");
      }
      break;
    case C_SG_ぢ:
      if (pressed) {
        SEND_STRING("di");
      }
      break;
    case C_SG_ぢゃ:
      if (pressed) {
        SEND_STRING("dya");
      }
      break;
    case C_SG_ぢゅ:
      if (pressed) {
        SEND_STRING("dyu");
      }
      break;
    case C_SG_ぢょ:
      if (pressed) {
        SEND_STRING("dyo");
      }
      break;
    case C_SG_づ:
      if (pressed) {
        SEND_STRING("du");
      }
      break;
    case C_SG_てぃ:
      if (pressed) {
        SEND_STRING("texi");
      }
      break;
    case C_SG_でぃ:
      if (pressed) {
        SEND_STRING("dexi");
      }
      break;
    case C_SG_ど:
      if (pressed) {
        SEND_STRING("do");
      }
      break;
    case C_SG_にゃ:
      if (pressed) {
        SEND_STRING("nya");
      }
      break;
    case C_SG_にゅ:
      if (pressed) {
        SEND_STRING("nyu");
      }
      break;
    case C_SG_にょ:
      if (pressed) {
        SEND_STRING("nyo");
      }
      break;
    case C_SG_ぬ:
      if (pressed) {
        SEND_STRING("nu");
      }
      break;
    case C_SG_ね:
      if (pressed) {
        SEND_STRING("ne");
      }
      break;
    case C_SG_ぱ:
      if (pressed) {
        SEND_STRING("pa");
      }
      break;
    case C_SG_ひゃ:
      if (pressed) {
        SEND_STRING("hya");
      }
      break;
    case C_SG_ひゅ:
      if (pressed) {
        SEND_STRING("hyu");
      }
      break;
    case C_SG_ひょ:
      if (pressed) {
        SEND_STRING("hyo");
      }
      break;
    case C_SG_び:
      if (pressed) {
        SEND_STRING("bi");
      }
      break;
    case C_SG_びゃ:
      if (pressed) {
        SEND_STRING("bya");
      }
      break;
    case C_SG_びゅ:
      if (pressed) {
        SEND_STRING("byu");
      }
      break;
    case C_SG_びょ:
      if (pressed) {
        SEND_STRING("byo");
      }
      break;
    case C_SG_ぴ:
      if (pressed) {
        SEND_STRING("pi");
      }
      break;
    case C_SG_ぴゃ:
      if (pressed) {
        SEND_STRING("pya");
      }
      break;
    case C_SG_ぴゅ:
      if (pressed) {
        SEND_STRING("pyu");
      }
      break;
    case C_SG_ぴょ:
      if (pressed) {
        SEND_STRING("pyo");
      }
      break;
    case C_SG_ふ:
      if (pressed) {
        SEND_STRING("hu");
      }
      break;
    case C_SG_ふぁ:
      if (pressed) {
        SEND_STRING("fa");
      }
      break;
    case C_SG_ふぃ:
      if (pressed) {
        SEND_STRING("fi");
      }
      break;
    case C_SG_ふぇ:
      if (pressed) {
        SEND_STRING("fe");
      }
      break;
    case C_SG_ふぉ:
      if (pressed) {
        SEND_STRING("fo");
      }
      break;
    case C_SG_ぷ:
      if (pressed) {
        SEND_STRING("pu");
      }
      break;
    case C_SG_へ:
      if (pressed) {
        SEND_STRING("he");
      }
      break;
    case C_SG_べ:
      if (pressed) {
        SEND_STRING("be");
      }
      break;
    case C_SG_ぺ:
      if (pressed) {
        SEND_STRING("pe");
      }
      break;
    case C_SG_ほ:
      if (pressed) {
        SEND_STRING("ho");
      }
      break;
    case C_SG_ぼ:
      if (pressed) {
        SEND_STRING("bo");
      }
      break;
    case C_SG_ぽ:
      if (pressed) {
        SEND_STRING("po");
      }
      break;
    case C_SG_み:
      if (pressed) {
        SEND_STRING("mi");
      }
      break;
    case C_SG_みゃ:
      if (pressed) {
        SEND_STRING("mya");
      }
      break;
    case C_SG_みゅ:
      if (pressed) {
        SEND_STRING("myu");
      }
      break;
    case C_SG_みょ:
      if (pressed) {
        SEND_STRING("myo");
      }
      break;
    case C_SG_む:
      if (pressed) {
        SEND_STRING("mu");
      }
      break;
    case C_SG_め:
      if (pressed) {
        SEND_STRING("me");
      }
      break;
    case C_SG_も:
      if (pressed) {
        SEND_STRING("mo");
      }
      break;
    case C_SG_ゃ:
      if (pressed) {
        SEND_STRING("xya");
      }
      break;
    case C_SG_や:
      if (pressed) {
        SEND_STRING("ya");
      }
      break;
    case C_SG_ゅ:
      if (pressed) {
        SEND_STRING("xyu");
      }
      break;
    case C_SG_ゆ:
      if (pressed) {
        SEND_STRING("yu");
      }
      break;
    case C_SG_ょ:
      if (pressed) {
        SEND_STRING("xyo");
      }
      break;
    case C_SG_よ:
      if (pressed) {
        SEND_STRING("yo");
      }
      break;
    case C_SG_ら:
      if (pressed) {
        SEND_STRING("ra");
      }
      break;
    case C_SG_り:
      if (pressed) {
        SEND_STRING("ri");
      }
      break;
    case C_SG_りゃ:
      if (pressed) {
        SEND_STRING("rya");
      }
      break;
    case C_SG_りゅ:
      if (pressed) {
        SEND_STRING("ryu");
      }
      break;
    case C_SG_りょ:
      if (pressed) {
        SEND_STRING("ryo");
      }
      break;
    case C_SG_れ:
      if (pressed) {
        SEND_STRING("re");
      }
      break;
    case C_SG_ろ:
      if (pressed) {
        SEND_STRING("ro");
      }
      break;
    case C_SG_ゎ:
      if (pressed) {
        SEND_STRING("xwa");
      }
      break;
    case C_SG_わ:
      if (pressed) {
        SEND_STRING("wa");
      }
      break;
    case C_SG_を:
      if (pressed) {
        SEND_STRING("wo");
      }
      break;
    case C_SG_ヴ:
      if (pressed) {
        SEND_STRING("vu");
      }
      break;

// win -> ctrl + shift
     case QUOT_Ctrl_Shift:
       if (pressed) {
         register_code(KC_LEFT_SHIFT);
         register_code(KC_LEFT_CTRL);
         register_code(KC_QUOT);
       } else {
         unregister_code(KC_QUOT);
         unregister_code(KC_LEFT_CTRL);
         unregister_code(KC_LEFT_SHIFT);
       }
       break;
     case BSPC_Ctrl_Shift:
       if (pressed) {
         register_code(KC_LEFT_SHIFT);
         register_code(KC_LEFT_CTRL);
         register_code(KC_BSPC);
       } else {
         unregister_code(KC_BSPC);
         unregister_code(KC_LEFT_CTRL);
         unregister_code(KC_LEFT_SHIFT);
       }
       break;
     case SPC_Ctrl_Shift:
       if (pressed) {
         register_code(KC_LEFT_SHIFT);
         register_code(KC_LEFT_CTRL);
         register_code(KC_SPC);
       } else {
         unregister_code(KC_SPC);
         unregister_code(KC_LEFT_CTRL);
         unregister_code(KC_LEFT_SHIFT);
       }
       break;
  }
}


// キーマップの設定
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // MTGAP Thumbshift
  [BASE] = LAYOUT(
        // 左手
        // 天面スイッチ
        XXXXXXX,  KC_1,  KC_2, KC_3, LT(BALL_SETTINGS, KC_4), LT(LIGHT_SETTINGS, KC_5),
        XXXXXXX,  KC_Y,  KC_P, KC_O,  KC_U,  KC_J,
        XXXXXXX, KC_I,  KC_N, KC_E,  KC_A,  KC_SCLN,
                 KC_Q,  KC_Z, KC_COMM, KC_DOT, KC_SLSH,
                               KC_RIGHT_ALT,
        // 側面スイッチ
        C_S_T(KC_QUOT), LT(ICHIKAWA,KC_BSPC),
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,         L_CHMOD,
        // 追加スイッチ                             // トグルスイッチ
        LSFT_T(KC_SPC), LT(NUM,KC_LNG2),                    KM_TOGGLE_SWITCH_LEFT,
        // 右手
        LT(LIGHT_SETTINGS, KC_6), LT(BALL_SETTINGS, KC_7), KC_8, KC_9, KC_0, XXXXXXX,
        KC_K, KC_D, KC_L, KC_C,  KC_W, XXXXXXX,
        KC_M, KC_H, KC_T, KC_S,  KC_R, XXXXXXX,
        KC_B, KC_F, KC_G, KC_V,  KC_X,
                             KC_RIGHT_GUI,
        LALT_T(KC_TAB), IK_GUI,
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,         R_CHMOD,
        LT(SYMBOL,KC_LNG1), LCTL_T(KC_ENT),                    KM_TOGGLE_SWITCH_RIGHT
    ),
  [SHINGETA] = LAYOUT(
        // 左手
        // 天面スイッチ
        _______,  _______, _______, _______, _______, _______,
        _______,  SG_げ, SG_に, SG_は, SG_COMM, SG_ち,
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
        SG_て, SG_た, SG_で, SG_DOT, SG_ぶ,
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
        _______, _______, _______, _______, _______, _______,
        KC_Y, KC_U, KC_I,    KC_O,   KC_P,    _______,
        KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, _______,
        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                             _______,
        _______, _______,
        _______, _______, _______, _______,         _______,
        _______, _______,                    _______
    ),
  [ONLY_QWERTY] = LAYOUT(
        // 左手
        // 天面スイッチ
        KC_ESC,  KC_1,         KC_2,            KC_3, KC_4, KC_5,
        KC_TAB,  KC_Q,         KC_W,            KC_E, KC_R, KC_T,
        CMD_CTL, KC_A,         KC_S,            KC_D, KC_F, KC_G,
                 KC_Z, KC_X,            KC_C, KC_V, KC_B,
                               KC_EQL,
        // 側面スイッチ
        KC_GRV, KC_SPC,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,         KC_MINS,
        // 追加スイッチ                             // トグルスイッチ
        KC_RBRC, KC_NUHS,                    _______,
        // 右手
        KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_LBRC,
        KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_QUOT,
        KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_LSFT,
        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                             KC_INT1,
        KC_ENT, KC_BSPC,
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,         R_CHMOD,
        KC_RIGHT_ALT, KC_RIGHT_GUI,                    _______
    ),
    [SYMBOL] = LAYOUT(
        // 左手
        _______, _______, _______, _______, _______, _______,
        _______, LSFT(KC_8), LSFT(KC_9), KC_QUOT, LSFT(KC_6), KC_INT3,
        _______, LSFT(KC_7), LSFT(KC_2), KC_MINS, LSFT(KC_1), KC_ESC,
                 LSFT(KC_3), LSFT(KC_5), LSFT(KC_INT1), LSFT(KC_MINS), KC_LBRC,
                          _______,
        KM_SYMBOL_QUOT, KM_SYMBOL_BSPC,
        _______, _______, _______, _______,          _______,
        KM_SYMBOL_SPC, LALT_T(KC_LNG2),                    _______,
        // 右手
        _______, _______, _______, _______, _______, _______,
        KC_PGUP, KC_HOME,             KC_END,       LSFT(KC_RBRC), LSFT(KC_NUHS), _______,
        LSFT(KC_QUOT), LSFT(KC_INT3), LSFT(KC_EQL), KC_EQL,        LSFT(KC_4),       _______,
        KC_PGDN, KC_DEL,              KC_RBRC,      KC_NUHS,       LSFT(KC_LBRC),
                                   _______,
        _______, _______,
        _______, _______, _______, _______,         _______,
        _______, _______,                    _______
    ),
    [NUM] = LAYOUT(
        // 左手
        _______, _______,  _______, _______, _______, _______,
        _______, KC_F7, KC_F4, KC_F1, KC_F10, KC_F13,
        _______, KC_F8, KC_F5, KC_F2, KC_F11, KC_BSPC,
                 KC_F9, KC_F6, KC_F3, KC_F12, KC_ENT,
                          _______,
        _______, _______,
        _______, _______, _______, _______,         _______,
        _______, _______,            _______,
        // 右手
        _______, _______, _______, _______, _______, _______,
        KC_MINS,       KC_7, KC_8, KC_9, KC_SLSH , _______,
        LSFT(KC_SCLN), KC_4, KC_5, KC_6, KC_0    , _______,
        LSFT(KC_QUOT), KC_1, KC_2, KC_3, KC_INT1  ,
                                   _______,
        KM_NUM_TAB, KM_NUM_GUI,
        _______, _______, _______, _______,         _______,
        LSFT_T(KC_LNG1), KM_NUM_ENT,         _______
    ),
    [ICHIKAWA] = LAYOUT(
        // 左手
        _______, _______, _______, _______, _______, _______,
        _______, KC_VOLU, IK_END,   IK_MIN,  IK_MAX,       XXXXXXX,
        _______, KC_MUTE, XXXXXXX,  LGUI(LALT(KC_LEFT)), LGUI(LALT(KC_RIGHT)), CAPTCHA,
                 KC_VOLD, XXXXXXX,  XXXXXXX, LGUI(KC_TAB),      XXXXXXX,
                          _______,
        _______, _______,
        _______, _______, _______, _______,          _______,
        _______, _______,                            _______,
        // 右手
        _______, _______, _______, _______, _______, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        XXXXXXX, KC_MS_BTN1, KC_MS_BTN2, MOD_SCRL, XXXXXXX, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______,
        KM_ICHIKAWA_TAB, KM_ICHIKAWA_GUI,
        _______, _______, _______, _______,          _______,
        LSFT_T(KC_LNG1), KM_ICHIKAWA_ENT,         _______
    ),
    [MOUSE] = LAYOUT(
        // 左手
        _______, _______, _______, _______, _______,    _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,
        _______, KC_LEFT_GUI, KC_LEFT_ALT, KC_LEFT_CTRL, KC_LEFT_SHIFT, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX,
        _______, _______,
        _______, _______, _______, _______,          _______,
        _______, _______,                            _______,
        // 右手
        _______, _______, _______, _______, _______, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_MS_BTN1, KC_MS_BTN2, MOD_SCRL, QK_USER_4, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX,
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
        ENCODER_CCW_CW(KC_WH_L, KC_WH_R),
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
    process_record_shingetakeycodes(keycode, record, SHINGETA);
    process_record_ichikawakeycodes(keycode, record, 0);

    switch (keycode) {
        case IK_GUI:
            layer_on_qwerty_when_modifier(record);
            break;
        case LCTL_T(KC_ENT):
        case LALT_T(KC_TAB):
        case C_S_T(KC_QUOT):
            layer_on_qwerty_when_modifier(record);
            break;
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
        case KM_TOGGLE_SWITCH_LEFT:
            if (record->event.pressed) {
                toggle_switch_left = true;
            } else {
                toggle_switch_left = false;
            }
            if (toggle_switch_left && toggle_switch_right) {
                layer_on(ONLY_QWERTY);
            } else {
                layer_off(ONLY_QWERTY);
            }
            break;
        case KM_TOGGLE_SWITCH_RIGHT:
            if (record->event.pressed) {
                toggle_switch_right = true;
            } else {
                toggle_switch_right = false;
            }
            if (toggle_switch_left && toggle_switch_right) {
                layer_on(ONLY_QWERTY);
            } else {
                layer_off(ONLY_QWERTY);
            }
            break;
        case KM_SYMBOL_QUOT:
          if (record->event.pressed) {
            startup_timer = timer_read();
            register_code(KC_LEFT_SHIFT);
            register_code(KC_LEFT_CTRL);
          } else {
            unregister_code(KC_LEFT_CTRL);
            unregister_code(KC_LEFT_SHIFT);
            if(timer_elapsed(startup_timer) < TAP_TERM_KEYMAP){
              register_code(KC_LEFT_SHIFT);
              tap_code(KC_QUOT);
              unregister_code(KC_LEFT_SHIFT);
            }
          }
          break;
        case KM_SYMBOL_BSPC:
          if (record->event.pressed) {
            startup_timer = timer_read();
            register_code(KC_LEFT_CTRL);
          } else {
            unregister_code(KC_LEFT_CTRL);
            if(timer_elapsed(startup_timer) < TAP_TERM_KEYMAP){
              register_code(KC_LEFT_SHIFT);
              tap_code(KC_BSPC);
              unregister_code(KC_LEFT_SHIFT);
            }
          }
          break;
        case KM_SYMBOL_SPC:
          if (record->event.pressed) {
            startup_timer = timer_read();
            register_code(KC_LEFT_SHIFT);
          } else {
            if(timer_elapsed(startup_timer) < TAP_TERM_KEYMAP){
              tap_code(KC_SPC);
            }
            unregister_code(KC_LEFT_SHIFT);
          }
          break;
        case KM_ICHIKAWA_ENT:
          if (record->event.pressed) {
            register_code(KC_LEFT_CTRL);
            register_code(KC_ENT);
          } else {
            unregister_code(KC_ENT);
            unregister_code(KC_LEFT_CTRL);
          }
          break;
        case KM_ICHIKAWA_GUI:
          if (record->event.pressed) {
            register_code(KC_LEFT_CTRL);
            register_code(KC_LEFT_GUI);
          } else {
            unregister_code(KC_LEFT_GUI);
            unregister_code(KC_LEFT_CTRL);
          }
          break;
        case KM_ICHIKAWA_TAB:
          if (record->event.pressed) {
              register_code(KC_LEFT_CTRL);
              register_code(KC_TAB);
          } else {
              unregister_code(KC_TAB);
              unregister_code(KC_LEFT_CTRL);
          }
          break;
        case KM_NUM_ENT:
          if (record->event.pressed) {
            startup_timer = timer_read();
            register_code(KC_LEFT_CTRL);
          } else {
            unregister_code(KC_LEFT_CTRL);
            if(timer_elapsed(startup_timer) < TAP_TERM_KEYMAP){
              register_code(KC_LEFT_ALT);
              tap_code(KC_ENT);
              unregister_code(KC_LEFT_ALT);
            }
          }
          break;
        case KM_NUM_GUI:
          if (record->event.pressed) {
            startup_timer = timer_read();
            register_code(KC_LEFT_CTRL);
            register_code(KC_LEFT_SHIFT);
          } else {
            unregister_code(KC_LEFT_SHIFT);
            unregister_code(KC_LEFT_CTRL);
            if(timer_elapsed(startup_timer) < TAP_TERM_KEYMAP){
              register_code(KC_LEFT_ALT);
              tap_code(KC_LEFT_GUI);
              unregister_code(KC_LEFT_ALT);
            }
          }
          break;
        case KM_NUM_TAB:
          if (record->event.pressed) {
            startup_timer = timer_read();
            register_code(KC_LEFT_ALT);
          } else {
            if(timer_elapsed(startup_timer) < TAP_TERM_KEYMAP){
              tap_code(KC_TAB);
            }
            unregister_code(KC_LEFT_ALT);
          }
          break;
    }

    return true;
};

