#include "tia_bch.h"

static uint16_t matrix[16][4] = {
   0x8000, 0xcd93, 0x0bdd, 0x3b2a,
   0x4000, 0xab5a, 0x8e33, 0xa6be,
   0x2000, 0x983e, 0x4cc4, 0xe874,
   0x1000, 0x4c1f, 0x2662, 0x743a,
   0x0800, 0xeb9c, 0x98ec, 0x0136,
   0x0400, 0xb85d, 0x47ab, 0x3bb0,
   0x0200, 0x5c2e, 0xa3d5, 0x9dd8,
   0x0100, 0x2e17, 0x51ea, 0xceec,
   0x0080, 0x170b, 0xa8f5, 0x6776,
   0x0040, 0xc616, 0xdfa7, 0x8890,
   0x0020, 0x630b, 0x6fd3, 0xc448,
   0x0010, 0x3185, 0xb7e9, 0xe224,
   0x0008, 0x18c2, 0xdbf4, 0xf112,
   0x0004, 0xc1f2, 0x6627, 0x43a2,
   0x0002, 0xad6a, 0x38ce, 0x9afb,
   0x0001, 0x9b26, 0x17ba, 0x7657
};

static uint16_t code_word_mask[16] = {
   0x8000,
   0x4000,
   0x2000,
   0x1000,
   0x0800,
   0x0400,
   0x0200,
   0x0100,
   0x0080,
   0x0040,
   0x0020,
   0x0010,
   0x0008,
   0x0004,
   0x0002,
   0x0001
};

void
tia_bch_64_encode(uint16_t in_word, uint16_t *code_word_out)
{
   uint8_t i, j;
   uint16_t temp_word;
   for(j=0; j<4; j++) {
      code_word_out[j] = 0;
      for(i=0; i<16; i++) {
         temp_word = in_word & code_word_mask[i];
         if(temp_word >= 1) {
            code_word_out[j] = code_word_out[j] ^ matrix[i][j];
         }
      }
   }
}