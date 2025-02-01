// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "quantum.h"
#include "lib/add_shingeta.h"

// 追加するキーコード
enum IK_keycodes{
    IK_GUI = SG_LAST,
    IK_END,
    IK_MAX,
    IK_MIN,
    IK_LAST
};

bool process_record_ichikawakeycodes(uint16_t keycode, keyrecord_t *record, uint8_t layer);
