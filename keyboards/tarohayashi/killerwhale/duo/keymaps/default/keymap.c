// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "lib/add_keycodes.h"
#include "lib/add_shingeta.h"

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
    C_SG_げ,
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
};

const uint16_t PROGMEM C_SG_ぁ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_あ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぅ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_うぃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_うぇ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_うぉ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぇ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_え_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぉ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_お_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_きゃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_きゅ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_きょ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぎ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぎゃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぎゅ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぎょ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぐぁ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぐぃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぐぅ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぐぇ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぐぉ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_け_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_げ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ご_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_さ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ざ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_しぇ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_しゃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_しゅ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_しょ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_じ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_じぇ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_じゃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_じゅ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_じょ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ず_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_せ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぜ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_そ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぞ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_だ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ちぇ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ちゃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ちゅ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ちょ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぢ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぢゃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぢゅ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぢょ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_づ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_てぃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_でぃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ど_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_にゃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_にゅ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_にょ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぬ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ね_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぱ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ひゃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ひゅ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ひょ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_び_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_びゃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_びゅ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_びょ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぴ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぴゃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぴゅ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぴょ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ふ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ふぁ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ふぃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ふぇ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ふぉ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぷ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_へ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_べ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぺ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ほ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぼ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ぽ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_み_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_みゃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_みゅ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_みょ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_む_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_め_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_も_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ゃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_や_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ゅ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ゆ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ょ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_よ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ら_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_り_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_りゃ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_りゅ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_りょ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_れ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ろ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ゎ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_わ_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_を_COMBO[] = {SG_, SG_, COMBO_END};
const uint16_t PROGMEM C_SG_ヴ_COMBO[] = {SG_, SG_, COMBO_END};


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
    [C_SG_げ] = COMBO_ACTION(C_SG_げ_COMBO),
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
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

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
    case C_SG_げ:
      if (pressed) {
        SEND_STRING("ge");
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
        SEND_STRING("nyu");
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
  }
}

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
        _______,  SG_げ, SG_に, SG_は, KC_COMM, SG_ち,
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

