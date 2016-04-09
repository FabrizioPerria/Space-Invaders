#ifndef __FONT_H
#	define __FONT_H

#	define FONT_WIDTH 8
#	define FONT_HEIGHT 8

static unsigned char const font[] = {
    0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,    // [0x20] ' '
    0x0,  0x0,  0x0,  0xDF,  0xDF,  0x0,  0x0,  0x0,    // [0x21] '!'
    0x0,  0x3,  0x7,  0x0,  0x3,  0x7,  0x0,  0x0,    // [0x22] '"'
    0x0,  0x14,  0x3E,  0x14,  0x3E,  0x14,  0x0,  0x0,    // [0x23] '#'
    0x0,  0x24,  0x2A,  0x7F,  0x2A,  0x12,  0x0,  0x0,    // [0x24] '$'
    0x43,  0x23,  0x10,  0x8,  0x4,  0x62,  0x61,  0x0,    // [0x25] '%'
    0x38,  0x7C,  0x44,  0x7F,  0x3F,  0x4,  0x4,  0x0,    // [0x26] '&'
    0x0,  0x0,  0x0,  0x7,  0x7,  0x0,  0x0,  0x0,    // [0x27] '''
    0x0,  0x0,  0x7E,  0xFF,  0x81,  0x0,  0x0,  0x0,    // [0x28] '('
    0x0,  0x0,  0x81,  0xFF,  0x7E,  0x0,  0x0,  0x0,    // [0x29] ')'
    0x8,  0x2A,  0x1C,  0x7F,  0x1C,  0x2A,  0x8,  0x0,    // [0x2A] '*'
    0x0,  0x8,  0x8,  0x3E,  0x3E,  0x8,  0x8,  0x0,    // [0x2B] '+'
    0x0,  0x0,  0x80,  0xE0,  0x60,  0x0,  0x0,  0x0,    // [0x2C] ','
    0x0,  0x8,  0x8,  0x8,  0x8,  0x8,  0x8,  0x0,    // [0x2D] '-'
    0x0,  0x0,  0x0,  0xC0,  0xC0,  0x0,  0x0,  0x0,    // [0x2E] '.'
    0x0,  0xC0,  0xF0,  0x3C,  0xF,  0x3,  0x0,  0x0,    // [0x2F] '/'
    0x3E,  0x7F,  0x51,  0x49,  0x45,  0x7F,  0x3E,  0x0,    // [0x30] '0'
    0x0,  0x40,  0x42,  0x7F,  0x7F,  0x40,  0x40,  0x0,    // [0x31] '1'
    0x72,  0x7B,  0x49,  0x49,  0x49,  0x4F,  0x46,  0x0,    // [0x32] '2'
    0x22,  0x63,  0x41,  0x49,  0x49,  0x7F,  0x36,  0x0,    // [0x33] '3'
    0x7,  0xF,  0x8,  0x8,  0x8,  0x7E,  0x7E,  0x0,    // [0x34] '4'
    0x27,  0x6F,  0x49,  0x49,  0x49,  0x79,  0x31,  0x0,    // [0x35] '5'
    0x3E,  0x7F,  0x49,  0x49,  0x49,  0x79,  0x30,  0x0,    // [0x36] '6'
    0x1,  0x1,  0x1,  0x1,  0x1,  0x7F,  0x7E,  0x0,    // [0x37] '7'
    0x36,  0x7F,  0x49,  0x49,  0x49,  0x7F,  0x36,  0x0,    // [0x38] '8'
    0x6,  0xF,  0x9,  0x9,  0x9,  0x7F,  0x7F,  0x0,    // [0x39] '9'
    0x0,  0x0,  0x0,  0x63,  0x63,  0x0,  0x0,  0x0,    // [0x3A] ':'
    0x0,  0x0,  0x80,  0xE3,  0x63,  0x0,  0x0,  0x0,    // [0x3B] ';'
    0x0,  0x8,  0x1C,  0x36,  0x63,  0x41,  0x0,  0x0,    // [0x3C] '<'
    0x0,  0x14,  0x14,  0x14,  0x14,  0x14,  0x14,  0x0,    // [0x3D] '='
    0x0,  0x41,  0x63,  0x36,  0x1C,  0x8,  0x0,  0x0,    // [0x3E] '>'
    0x2,  0x3,  0xD1,  0xD9,  0x9,  0xF,  0x6,  0x0,    // [0x3F] '?'
    0x3E,  0x7F,  0x41,  0x5D,  0x55,  0x5F,  0xE,  0x0,    // [0x40] '@'
    0x7E,  0x7F,  0x9,  0x9,  0x9,  0x7F,  0x7E,  0x0,    // [0x41] 'A'
    0x7F,  0x7F,  0x49,  0x49,  0x49,  0x7F,  0x36,  0x0,    // [0x42] 'B'
    0x3E,  0x7F,  0x41,  0x41,  0x41,  0x63,  0x22,  0x0,    // [0x43] 'C'
    0x7F,  0x7F,  0x41,  0x41,  0x63,  0x3E,  0x1C,  0x0,    // [0x44] 'D'
    0x7F,  0x7F,  0x49,  0x49,  0x49,  0x41,  0x41,  0x0,    // [0x45] 'E'
    0x7F,  0x7F,  0x9,  0x9,  0x9,  0x1,  0x1,  0x0,    // [0x46] 'F'
    0x3E,  0x7F,  0x41,  0x49,  0x49,  0x7B,  0x7A,  0x0,    // [0x47] 'G'
    0x7F,  0x7F,  0x8,  0x8,  0x8,  0x7F,  0x7F,  0x0,    // [0x48] 'H'
    0x0,  0x41,  0x41,  0x7F,  0x7F,  0x41,  0x41,  0x0,    // [0x49] 'I'
    0x20,  0x61,  0x41,  0x7F,  0x3F,  0x1,  0x1,  0x0,    // [0x4A] 'J'
    0x7F,  0x7F,  0x8,  0x1C,  0x36,  0x63,  0x41,  0x0,    // [0x4B] 'K'
    0x7F,  0x7F,  0x40,  0x40,  0x40,  0x40,  0x40,  0x0,    // [0x4C] 'L'
    0x7F,  0x7F,  0x6,  0xC,  0x6,  0x7F,  0x7F,  0x0,    // [0x4D] 'M'
    0x7F,  0x7F,  0x6,  0xC,  0x18,  0x7F,  0x7F,  0x0,    // [0x4E] 'N'
    0x3E,  0x7F,  0x41,  0x41,  0x41,  0x7F,  0x3E,  0x0,    // [0x4F] 'O'
    0x7F,  0x7F,  0x9,  0x9,  0x9,  0xF,  0x6,  0x0,    // [0x50] 'P'
    0x3E,  0x7F,  0x41,  0x61,  0xC1,  0xFF,  0xBE,  0x0,    // [0x51] 'Q'
    0x7F,  0x7F,  0x9,  0x9,  0x9,  0x7F,  0x76,  0x0,    // [0x52] 'R'
    0x26,  0x6F,  0x49,  0x49,  0x49,  0x7B,  0x32,  0x0,    // [0x53] 'S'
    0x0,  0x1,  0x1,  0x7F,  0x7F,  0x1,  0x1,  0x0,    // [0x54] 'T'
    0x3F,  0x7F,  0x40,  0x40,  0x40,  0x7F,  0x7F,  0x0,    // [0x55] 'U'
    0x0,  0x7,  0x1F,  0x78,  0x78,  0x1F,  0x7,  0x0,    // [0x56] 'V'
    0x7F,  0x7F,  0x30,  0x18,  0x30,  0x7F,  0x7F,  0x0,    // [0x57] 'W'
    0x63,  0x77,  0x1C,  0x8,  0x1C,  0x77,  0x63,  0x0,    // [0x58] 'X'
    0x27,  0x6F,  0x48,  0x48,  0x48,  0x7F,  0x3F,  0x0,    // [0x59] 'Y'
    0x61,  0x71,  0x59,  0x4D,  0x47,  0x43,  0x41,  0x0,    // [0x5A] 'Z'
    0x0,  0x0,  0xFF,  0xFF,  0x81,  0x81,  0x0,  0x0,    // [0x5B] '['
    0x0,  0x3,  0xF,  0x3C,  0xF0,  0xC0,  0x0,  0x0,    // [0x5C] '\\'
    0x0,  0x0,  0x81,  0x81,  0xFF,  0xFF,  0x0,  0x0,    // [0x5D] ']'
    0x4,  0x6,  0x3,  0x1,  0x3,  0x6,  0x4,  0x0,    // [0x5E] '^'
    0x80,  0x80,  0x80,  0x80,  0x80,  0x80,  0x80,  0x0,    // [0x5F] '_'
    0x3,  0x7,  0x4,  0x0,  0x0,  0x0,  0x0,  0x0,    // [0x60] '`'
    0x38,  0x7C,  0x44,  0x44,  0x24,  0x7C,  0x78,  0x0,    // [0x61] 'a'
    0x7F,  0x7F,  0x24,  0x44,  0x44,  0x7C,  0x38,  0x0,    // [0x62] 'b'
    0x38,  0x7C,  0x44,  0x44,  0x44,  0x44,  0x44,  0x0,    // [0x63] 'c'
    0x38,  0x7C,  0x44,  0x44,  0x24,  0x7F,  0x7F,  0x0,    // [0x64] 'd'
    0x38,  0x7C,  0x54,  0x54,  0x54,  0x5C,  0x8,  0x0,    // [0x65] 'e'
    0x0,  0x4,  0x7E,  0x7F,  0x5,  0x1,  0x0,  0x0,    // [0x66] 'f'
    0x18,  0xBC,  0xA4,  0xA4,  0x94,  0xFC,  0x78,  0x0,    // [0x67] 'g'
    0x7F,  0x7F,  0x8,  0x4,  0x4,  0x7C,  0x78,  0x0,    // [0x68] 'h'
    0x0,  0x0,  0x0,  0x7D,  0x7D,  0x0,  0x0,  0x0,    // [0x69] 'i'
    0x0,  0x40,  0x40,  0x40,  0x7D,  0x3D,  0x0,  0x0,    // [0x6A] 'j'
    0x7F,  0x7F,  0x8,  0x8,  0x1C,  0x76,  0x62,  0x0,    // [0x6B] 'k'
    0x0,  0x0,  0x0,  0x7F,  0x7F,  0x0,  0x0,  0x0,    // [0x6C] 'l'
    0x78,  0x7C,  0x18,  0x30,  0x18,  0x7C,  0x78,  0x0,    // [0x6D] 'm'
    0x7C,  0x7C,  0x8,  0x4,  0x4,  0x7C,  0x78,  0x0,    // [0x6E] 'n'
    0x38,  0x7C,  0x44,  0x44,  0x44,  0x7C,  0x38,  0x0,    // [0x6F] 'o'
    0xFC,  0xFC,  0x28,  0x24,  0x24,  0x3C,  0x18,  0x0,    // [0x70] 'p'
    0x1C,  0x1E,  0x22,  0x22,  0x12,  0xFE,  0xFE,  0x0,    // [0x71] 'q'
    0x7C,  0x7C,  0x8,  0x4,  0x4,  0xC,  0x8,  0x0,    // [0x72] 'r'
    0x48,  0x5C,  0x54,  0x54,  0x54,  0x74,  0x20,  0x0,    // [0x73] 's'
    0x3F,  0x7F,  0x44,  0x44,  0x44,  0x60,  0x20,  0x0,    // [0x74] 't'
    0x3C,  0x7C,  0x40,  0x40,  0x20,  0x7C,  0x7C,  0x0,    // [0x75] 'u'
    0x0,  0xC,  0x3C,  0x70,  0x70,  0x3C,  0xC,  0x0,    // [0x76] 'v'
    0x3C,  0x7C,  0x30,  0x18,  0x30,  0x7C,  0x3C,  0x0,    // [0x77] 'w'
    0x44,  0x6C,  0x38,  0x10,  0x38,  0x6C,  0x44,  0x0,    // [0x78] 'x'
    0xC,  0x5C,  0x50,  0x50,  0x50,  0x7C,  0x3C,  0x0,    // [0x79] 'y'
    0x44,  0x64,  0x74,  0x54,  0x5C,  0x4C,  0x44,  0x0,    // [0x7A] 'z'
    0x0,  0x8,  0x3E,  0x77,  0x41,  0x0,  0x0,  0x0,    // [0x7B] '{'
    0x0,  0x0,  0x0,  0xFF,  0xFF,  0x0,  0x0,  0x0,    // [0x7C] '|'
    0x0,  0x41,  0x77,  0x3E,  0x8,  0x0,  0x0,  0x0,    // [0x7D] '}'
    0x2,  0x3,  0x1,  0x3,  0x2,  0x3,  0x1,  0x0,    // [0x7E] '~'
};

#endif
