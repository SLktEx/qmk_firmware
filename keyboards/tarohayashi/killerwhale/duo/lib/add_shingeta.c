#include "quantum.h"
#include "lib/add_shingeta.h"

#define SYMBOL_LAYER 4
#define NUM_LAYER 5

bool ime_on = true;

bool process_record_shingetakeycodes(uint16_t keycode, keyrecord_t *record, uint8_t layer){
    switch (keycode) {
        case SG_い:
            if(record->event.pressed) {
                SEND_STRING("i");
            }
            break;
        case SG_う:
            if(record->event.pressed) {
                SEND_STRING("u");
            }
            break;
        case SG_か:
            if(record->event.pressed) {
                SEND_STRING("ka");
            }
            break;
        case SG_が:
            if(record->event.pressed) {
                SEND_STRING("ga");
            }
            break;
        case SG_き:
            if(record->event.pressed) {
                SEND_STRING("ki");
            }
            break;
        case SG_く:
            if(record->event.pressed) {
                SEND_STRING("ku");
            }
            break;
        case SG_ぐ:
            if(record->event.pressed) {
                SEND_STRING("gu");
            }
            break;
        case SG_こ:
            if(record->event.pressed) {
                SEND_STRING("ko");
            }
            break;
        case SG_し:
            if(record->event.pressed) {
                SEND_STRING("si");
            }
            break;
        case SG_す:
            if(record->event.pressed) {
                SEND_STRING("su");
            }
            break;
        case SG_た:
            if(record->event.pressed) {
                SEND_STRING("ta");
            }
            break;
        case SG_ち:
            if(record->event.pressed) {
                SEND_STRING("ti");
            }
            break;
        case SG_っ:
            if(record->event.pressed) {
                SEND_STRING("xtu");
            }
            break;
        case SG_つ:
            if(record->event.pressed) {
                SEND_STRING("tu");
            }
            break;
        case SG_て:
            if(record->event.pressed) {
                SEND_STRING("te");
            }
            break;
        case SG_で:
            if(record->event.pressed) {
                SEND_STRING("de");
            }
            break;
        case SG_と:
            if(record->event.pressed) {
                SEND_STRING("to");
            }
            break;
        case SG_な:
            if(record->event.pressed) {
                SEND_STRING("na");
            }
            break;
        case SG_に:
            if(record->event.pressed) {
                SEND_STRING("ni");
            }
            break;
        case SG_の:
            if(record->event.pressed) {
                SEND_STRING("no");
            }
            break;
        case SG_は:
            if(record->event.pressed) {
                SEND_STRING("ha");
            }
            break;
        case SG_ば:
            if(record->event.pressed) {
                SEND_STRING("ba");
            }
            break;
        case SG_ひ:
            if(record->event.pressed) {
                SEND_STRING("hi");
            }
            break;
        case SG_ぶ:
            if(record->event.pressed) {
                SEND_STRING("bu");
            }
            break;
        case SG_ま:
            if(record->event.pressed) {
                SEND_STRING("ma");
            }
            break;
        case SG_る:
            if(record->event.pressed) {
                SEND_STRING("ru");
            }
            break;
        case SG_ん:
            if(record->event.pressed) {
                SEND_STRING("nn");
            }
            break;
        case SG_げ:
            if(record->event.pressed) {
                SEND_STRING("ge");
            }
            break;
        case SG_COMM:
            if(record->event.pressed) {
                register_code(KC_COMM);
            }else {
                unregister_code(KC_COMM);
            }
            break;
        case SG_DOT:
            if(record->event.pressed) {
                register_code(KC_DOT);
            }else {
                unregister_code(KC_DOT);
            }
            break;
        // IMEとうまく連携できないとき用
        case SG_TOGGLE:
            if(record->event.pressed) {
                if(ime_on) {
                    layer_on(layer);
                    ime_on = false;
                }else {
                    layer_off(layer);
                    ime_on = true;
                }
            }
            break;
        // 全角半角対応
        // PCと日本語英語がずれたらSG_TOGGLEで変更してもろて
        case KC_GRV:
            if(record->event.pressed) {
                if(ime_on) {
                    layer_on(layer);
                    ime_on = false;
                }else {
                    layer_off(layer);
                    ime_on = true;
                }
            }
        // 新下駄配列のON/OFF
        case LT(SYMBOL_LAYER,KC_LNG1):
            if (record->tap.count && record->event.pressed) {
                layer_on(layer);
            }
            break;
        case LT(NUM_LAYER,KC_LNG2):
            if (record->tap.count && record->event.pressed) {
                layer_off(layer);
            }
            break;
        case KC_LNG1:
        case KC_INTERNATIONAL_4:
            layer_on(layer);
            break;
        case KC_LNG2:
        case KC_INTERNATIONAL_5:
            layer_off(layer);
            break;
    }
    return true;
}
