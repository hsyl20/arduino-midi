/* Roland E-A7 */

#include "midi.h"

#define EA7_CHANNEL_STYLE 10
#define EA7_CHANNEL_UPPER 1

// Varations [1-4]
void ea7_set_variation(uint8_t n);

// Endings [1-4]
void ea7_set_ending(uint8_t n);

// Intro [1-4]
void ea7_set_intro(uint8_t n);

/*
Patchs:
   Accordeon fr:
      CC 0  64
      CC 32 4
      PC 21
   BlowAltoSib
      CC 0  50
      CC 32 4
      PC 65
   PortaLead
      CC 0  15
      CC 32 5
      PC 81
   Strings
      CC 0  16
      CC 32 4
      PC 48
   Vibraphone
      CC 0  0
      CC 32 4
      PC 11
   Meloharm
      CC 0  1
      CC 32 4
      PC 22
   Piano+string
      CC 0  24
      CC 32 4
      PC 0
   Piano+choir
      CC 0  26
      CC 32 4
      PC 0
*/
