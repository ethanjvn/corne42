#pragma once

#include <dt-bindings/zmk/keys.h>

// ZMK ne parle que "clavier US" : chaque &kp envoie un code HID, et c'est le
// layout clavier AZERTY réglé sur l'ordinateur qui le traduit en caractère
// français. Ces alias servent juste à écrire le .keymap directement en
// français (ex: FR_A) au lieu d'avoir à retenir/deviner le code HID US qui
// produit ce caractère une fois traduit par l'OS (ex: Q).

// --- Lettres qui changent de position vs un clavier US ---
#define FR_A       Q
#define FR_Z       W
#define FR_Q       A
#define FR_W       Z
#define FR_M       SEMICOLON

// --- Touche "ù" (à côté du M) : sans Maj = ù, avec Maj = %, AltGr = $ ---
#define FR_UGRAVE  APOSTROPHE
#define FR_PERCENT LS(APOSTROPHE)
#define FR_DOLLAR  RA(APOSTROPHE)

// --- Touche ISO à gauche de Maj.G : sans Maj = <, avec Maj = > ---
#define FR_LT      NON_US_BSLH
#define FR_GT      LS(NON_US_BSLH)

// --- Rangée du bas : virgule/point-virgule/deux-points/point d'exclamation ---
// Sans Maj : , ; : !   |   Avec Maj : ? . / §
#define FR_COMMA   M
#define FR_SEMI    COMMA
#define FR_COLON   DOT
#define FR_EXCL    SLASH

// --- Rangée des chiffres : sans Maj = accents, avec Maj = chiffres ---
// Sans Maj : & é " ' ( - è _ ç à   |   Avec Maj : 1 2 3 4 5 6 7 8 9 0
#define FR_AMPR    N1
#define FR_EACUTE  N2
#define FR_DQT     N3
#define FR_QUOT    N4
#define FR_LPAR    N5
#define FR_HYPHEN  N6
#define FR_EGRAVE  N7
#define FR_UNDER   N8
#define FR_CCEDIL  N9
#define FR_AGRAVE  N0
#define FR_RPAR    MINUS
#define FR_EQUAL   EQUAL

// --- Symboles de code, via AltGr (RA = touche AltGr) ---
// ^ et ` sont des touches mortes (se combinent avec la touche suivante).
#define FR_TILDE   RA(N2)
#define FR_HASH    RA(N3)
#define FR_LBRACE  RA(N4)
#define FR_LBRKT   RA(N5)
#define FR_PIPE    RA(N6)
#define FR_GRAVE   RA(N7)
#define FR_BSLH    RA(N8)
#define FR_CARET   RA(N9)
#define FR_AT      RA(N0)
#define FR_RBRKT   RA(MINUS)
#define FR_RBRACE  RA(EQUAL)
#define FR_EURO    RA(E)
