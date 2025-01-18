#include "quantum.h"
#include "lib/add_shingeta.h"


bool process_record_shingetakeycodes(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        case SG_I:
            if(record->event.pressed) {
                SEND_STRING("i");
            }
            break;
        case SG_U:
            if(record->event.pressed) {
                SEND_STRING("u");
            }
            break;
        case SG_KA:
            if(record->event.pressed) {
                SEND_STRING("ka");
            }
            break;
        case SG_GA:
            if(record->event.pressed) {
                SEND_STRING("ga");
            }
            break;
        case SG_KI:
            if(record->event.pressed) {
                SEND_STRING("ki");
            }
            break;
        case SG_KU:
            if(record->event.pressed) {
                SEND_STRING("ku");
            }
            break;
        case SG_GU:
            if(record->event.pressed) {
                SEND_STRING("gu");
            }
            break;
        case SG_KO:
            if(record->event.pressed) {
                SEND_STRING("ko");
            }
            break;
        case SG_SI:
            if(record->event.pressed) {
                SEND_STRING("si");
            }
            break;
        case SG_SU:
            if(record->event.pressed) {
                SEND_STRING("su");
            }
            break;
        case SG_TA:
            if(record->event.pressed) {
                SEND_STRING("ta");
            }
            break;
        case SG_TI:
            if(record->event.pressed) {
                SEND_STRING("ti");
            }
            break;
        case SG_XTU:
            if(record->event.pressed) {
                SEND_STRING("xtu");
            }
            break;
        case SG_TU:
            if(record->event.pressed) {
                SEND_STRING("tu");
            }
            break;
        case SG_TE:
            if(record->event.pressed) {
                SEND_STRING("te");
            }
            break;
        case SG_DE:
            if(record->event.pressed) {
                SEND_STRING("de");
            }
            break;
        case SG_TO:
            if(record->event.pressed) {
                SEND_STRING("to");
            }
            break;
        case SG_NA:
            if(record->event.pressed) {
                SEND_STRING("na");
            }
            break;
        case SG_NI:
            if(record->event.pressed) {
                SEND_STRING("ni");
            }
            break;
        case SG_NO:
            if(record->event.pressed) {
                SEND_STRING("no");
            }
            break;
        case SG_HA:
            if(record->event.pressed) {
                SEND_STRING("ha");
            }
            break;
        case SG_BA:
            if(record->event.pressed) {
                SEND_STRING("ba");
            }
            break;
        case SG_HI:
            if(record->event.pressed) {
                SEND_STRING("hi");
            }
            break;
        case SG_BU:
            if(record->event.pressed) {
                SEND_STRING("bu");
            }
            break;
        case SG_MA:
            if(record->event.pressed) {
                SEND_STRING("ma");
            }
            break;
        case SG_RU:
            if(record->event.pressed) {
                SEND_STRING("ru");
            }
            break;
        case SG_NN:
            if(record->event.pressed) {
                SEND_STRING("nn");
            }
            break;
        case SG_GE:
            if(record->event.pressed) {
                SEND_STRING("ge");
            }
            break;
    }
    return true;
}
