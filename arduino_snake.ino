#include <VGAX.h>
#include <VGAXUtils.h>
#include "pitches.h"

#define FTN_HEIGHT 6
#define FTN_SYMBOLS_COUNT 95

VGAX vga;
VGAXUtils vgaUtils;

const unsigned char fnt_data[FTN_SYMBOLS_COUNT][1 + FTN_HEIGHT] PROGMEM = {
{ 1, 128, 128, 128, 0, 128, 0, }, //glyph '!' code=0
{ 3, 160, 160, 0, 0, 0, 0, }, //glyph '"' code=1
{ 5, 248, 248, 248, 248, 248, 0, },  //glyph '#' code=2 - full rectangle
{ 5, 120, 160, 112, 40, 240, 0, },  //glyph '$' code=3
{ 5, 136, 16, 32, 64, 136, 0, },  //glyph '%' code=4
{ 5, 96, 144, 104, 144, 104, 0, },  //glyph '&' code=5
{ 2, 128, 64, 0, 0, 0, 0, },  //glyph ''' code=6
{ 2, 64, 128, 128, 128, 64, 0, }, //glyph '(' code=7
{ 2, 128, 64, 64, 64, 128, 0, },  //glyph ')' code=8
{ 3, 0, 160, 64, 160, 0, 0, },  //glyph '*' code=9
{ 3, 0, 64, 224, 64, 0, 0, }, //glyph '+' code=10
{ 2, 0, 0, 0, 0, 128, 64, },  //glyph ',' code=11
{ 3, 0, 0, 224, 0, 0, 0, }, //glyph '-' code=12
{ 1, 0, 0, 0, 0, 128, 0, }, //glyph '.' code=13
{ 5, 8, 16, 32, 64, 128, 0, },  //glyph '/' code=14
{ 4, 96, 144, 144, 144, 96, 0, }, //glyph '0' code=15
{ 3, 64, 192, 64, 64, 224, 0, },  //glyph '1' code=16
{ 4, 224, 16, 96, 128, 240, 0, }, //glyph '2' code=17
{ 4, 224, 16, 96, 16, 224, 0, },  //glyph '3' code=18
{ 4, 144, 144, 240, 16, 16, 0, }, //glyph '4' code=19
{ 4, 240, 128, 224, 16, 224, 0, },  //glyph '5' code=20
{ 4, 96, 128, 224, 144, 96, 0, }, //glyph '6' code=21
{ 4, 240, 16, 32, 64, 64, 0, }, //glyph '7' code=22
{ 4, 96, 144, 96, 144, 96, 0, },  //glyph '8' code=23
{ 4, 96, 144, 112, 16, 96, 0, },  //glyph '9' code=24
{ 1, 0, 128, 0, 128, 0, 0, }, //glyph ':' code=25
{ 2, 0, 128, 0, 0, 128, 64, },  //glyph ';' code=26
{ 3, 32, 64, 128, 64, 32, 0, }, //glyph '<' code=27
{ 3, 0, 224, 0, 224, 0, 0, }, //glyph '=' code=28
{ 3, 128, 64, 32, 64, 128, 0, },  //glyph '>' code=29
{ 4, 224, 16, 96, 0, 64, 0, },  //glyph '?' code=30
{ 4, 96, 144, 176, 128, 112, 0, },  //glyph '@' code=31
{ 4, 96, 144, 240, 144, 144, 0, },  //glyph 'A' code=32
{ 4, 224, 144, 224, 144, 224, 0, }, //glyph 'B' code=33
{ 4, 112, 128, 128, 128, 112, 0, }, //glyph 'C' code=34
{ 4, 224, 144, 144, 144, 224, 0, }, //glyph 'D' code=35
{ 4, 240, 128, 224, 128, 240, 0, }, //glyph 'E' code=36
{ 4, 240, 128, 224, 128, 128, 0, }, //glyph 'F' code=37
{ 4, 112, 128, 176, 144, 112, 0, }, //glyph 'G' code=38
{ 4, 144, 144, 240, 144, 144, 0, }, //glyph 'H' code=39
{ 3, 224, 64, 64, 64, 224, 0, },  //glyph 'I' code=40
{ 4, 240, 16, 16, 144, 96, 0, },  //glyph 'J' code=41
{ 4, 144, 160, 192, 160, 144, 0, }, //glyph 'K' code=42
{ 4, 128, 128, 128, 128, 240, 0, }, //glyph 'L' code=43
{ 5, 136, 216, 168, 136, 136, 0, }, //glyph 'M' code=44
{ 4, 144, 208, 176, 144, 144, 0, }, //glyph 'N' code=45
{ 4, 96, 144, 144, 144, 96, 0, }, //glyph 'O' code=46
{ 4, 224, 144, 224, 128, 128, 0, }, //glyph 'P' code=47
{ 4, 96, 144, 144, 144, 96, 16, },  //glyph 'Q' code=48
{ 4, 224, 144, 224, 160, 144, 0, }, //glyph 'R' code=49
{ 4, 112, 128, 96, 16, 224, 0, }, //glyph 'S' code=50
{ 3, 224, 64, 64, 64, 64, 0, }, //glyph 'T' code=51
{ 4, 144, 144, 144, 144, 96, 0, },  //glyph 'U' code=52
{ 3, 160, 160, 160, 160, 64, 0, },  //glyph 'V' code=53
{ 5, 136, 168, 168, 168, 80, 0, },  //glyph 'W' code=54
{ 4, 144, 144, 96, 144, 144, 0, },  //glyph 'X' code=55
{ 3, 160, 160, 64, 64, 64, 0, },  //glyph 'Y' code=56
{ 4, 240, 16, 96, 128, 240, 0, }, //glyph 'Z' code=57
{ 2, 192, 128, 128, 128, 192, 0, }, //glyph '[' code=58
{ 5, 128, 64, 32, 16, 8, 0, },  //glyph '\' code=59
{ 2, 192, 64, 64, 64, 192, 0, },  //glyph ']' code=60
{ 5, 32, 80, 136, 0, 0, 0, }, //glyph '^' code=61
{ 4, 0, 0, 0, 0, 240, 0, }, //glyph '_' code=62
{ 2, 128, 64, 0, 0, 0, 0, },  //glyph '`' code=63
{ 3, 0, 224, 32, 224, 224, 0, },  //glyph 'a' code=64
{ 3, 128, 224, 160, 160, 224, 0, }, //glyph 'b' code=65
{ 3, 0, 224, 128, 128, 224, 0, }, //glyph 'c' code=66
{ 3, 32, 224, 160, 160, 224, 0, },  //glyph 'd' code=67
{ 3, 0, 224, 224, 128, 224, 0, }, //glyph 'e' code=68
{ 2, 64, 128, 192, 128, 128, 0, },  //glyph 'f' code=69
{ 3, 0, 224, 160, 224, 32, 224, },  //glyph 'g' code=70
{ 3, 128, 224, 160, 160, 160, 0, }, //glyph 'h' code=71
{ 1, 128, 0, 128, 128, 128, 0, }, //glyph 'i' code=72
{ 2, 0, 192, 64, 64, 64, 128, },  //glyph 'j' code=73
{ 3, 128, 160, 192, 160, 160, 0, }, //glyph 'k' code=74
{ 1, 128, 128, 128, 128, 128, 0, }, //glyph 'l' code=75
{ 5, 0, 248, 168, 168, 168, 0, }, //glyph 'm' code=76
{ 3, 0, 224, 160, 160, 160, 0, }, //glyph 'n' code=77
{ 3, 0, 224, 160, 160, 224, 0, }, //glyph 'o' code=78
{ 3, 0, 224, 160, 160, 224, 128, }, //glyph 'p' code=79
{ 3, 0, 224, 160, 160, 224, 32, },  //glyph 'q' code=80
{ 3, 0, 224, 128, 128, 128, 0, }, //glyph 'r' code=81
{ 2, 0, 192, 128, 64, 192, 0, },  //glyph 's' code=82
{ 3, 64, 224, 64, 64, 64, 0, }, //glyph 't' code=83
{ 3, 0, 160, 160, 160, 224, 0, }, //glyph 'u' code=84
{ 3, 0, 160, 160, 160, 64, 0, },  //glyph 'v' code=85
{ 5, 0, 168, 168, 168, 80, 0, },  //glyph 'w' code=86
{ 3, 0, 160, 64, 160, 160, 0, },  //glyph 'x' code=87
{ 3, 0, 160, 160, 224, 32, 224, },  //glyph 'y' code=88
{ 2, 0, 192, 64, 128, 192, 0, },  //glyph 'z' code=89
{ 3, 96, 64, 192, 64, 96, 0, }, //glyph '{' code=90
{ 1, 128, 128, 128, 128, 128, 0, }, //glyph '|' code=91
{ 3, 192, 64, 96, 64, 192, 0, },  //glyph '}' code=92
{ 3, 96, 192, 0, 0, 0, 0, },  //glyph '~' code=93
{ 4, 48, 64, 224, 64, 240, 0, },  //glyph '£' code=94
};

#define IMG_SPLASH_WIDTH 120
#define IMG_SPLASH_BWIDTH 30
#define IMG_SPLASH_HEIGHT 60
const unsigned char img_splash_data[IMG_SPLASH_HEIGHT][IMG_SPLASH_BWIDTH] PROGMEM = {
	{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0, 252, 127,  20,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0, 252, 127,  20,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0, 241, 127, 196,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   3,   1,   3, 197,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   3,   1,   3, 197,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   3,   5,   3, 197,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   3, 197,  63,  21,   0,   0,  15, 255, 240,  63,   0, 252,  15, 255, 240, 252,   3, 240,  63, 255, 240,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,  21,  60,  85,   0,   0,  63, 255, 252,  63, 192, 252,  63, 255, 252, 252,   3, 240, 255, 255, 240,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,  85,  85,  20,   0,   0,  63, 255, 252,  63, 192, 252,  63, 255, 252, 252,   3, 240, 255, 255, 240,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,  84,   0,   0,  63,   0, 252,  63, 240, 252,  63,   0, 252, 252,   3, 240, 252,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0, 168,  85,  80,   0,   0,  63,   0,   0,  63, 240, 252,  63,   0, 252, 252,   3, 240, 252,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,  10, 128, 213,  64,   0,   0,  63, 255, 240,  63, 240, 252,  63, 255, 252, 255, 255, 240, 255, 252,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   2, 170,   1,  85,   5,   0,   0,  63, 255, 252,  63,  60, 252,  63, 255, 252, 255, 255, 192, 255, 252,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,  10, 168,   3, 253,  21,  64,   0,  15, 255, 252,  63,  15, 252,  63, 255, 252, 255, 255, 240, 255, 252,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,  32,   1,  85,  21,  80,   0,   0,   0, 252,  63,  15, 252,  63,   0, 252, 252,   3, 240, 252,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   2, 160,   3, 213,  85,  85,  64,  63,   0, 252,  63,  15, 252,  63,   0, 252, 252,   3, 240, 252,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   3, 213,  81,  85,  64,  63, 255, 252,  63,   3, 252,  63,   0, 252, 252,   3, 240, 255, 255, 240,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   1,  85,  64,  84,   0,  63, 255, 252,  63,   3, 252,  63,   0, 252, 252,   3, 240, 255, 255, 240,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   1,  85,  64,  84,   0,  15, 255, 240,  63,   0, 252,  63,   0, 252, 252,   3, 240,  63, 255, 240,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,  15, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 240,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,  42, 160, 170, 128, 170, 128, 170,   2, 168,   0,  42, 130, 170, 138, 130, 170,   2, 170, 128,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,  40,  40, 160, 160, 160,   2, 130, 138,  10,   0, 160, 160,  40,  10, 130, 130, 128,  40,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,  40,  40, 160, 160, 160,   2, 128,  10,   0,   0, 160,   0,  40,  40, 162, 130, 128,  40,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,  40,  40, 160, 160, 170, 130, 168,  10, 160,   0, 170,   0,  40,  40, 162, 130, 128,  40,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,  42, 160, 170, 128, 160,   0,  42, 128, 170,   0,  10, 160,  40,  40, 162, 170,   0,  40,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,  40,   0, 162, 128, 160,   0,   2, 128,  10,   0,   0, 160,  40, 170, 170, 138,   0,  40,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,  40,   0, 160, 160, 160,   2, 130, 138,  10,   0, 160, 160,  40, 160,  42, 130, 128,  40,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,  40,   0, 160,  40, 170, 128, 170,   2, 168,   0,  42, 128,  40, 160,  42, 128, 160,  40,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, },{ 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, }, };

static const char str0[] PROGMEM = "0";
static const char str1[] PROGMEM = "1";
static const char str2[] PROGMEM = "2";
static const char str3[] PROGMEM = "3";
static const char str4[] PROGMEM = "4";
static const char str5[] PROGMEM = "5";
static const char str6[] PROGMEM = "6";
static const char str7[] PROGMEM = "7";
static const char str8[] PROGMEM = "8";
static const char str9[] PROGMEM = "9";
static const char strStart[] PROGMEM = "PRESS START!";
static const char strGameOver[] PROGMEM = "GAME OVER";
static const char strLevel1[] PROGMEM = "LEVEL 1";
static const char strLevel2[] PROGMEM = "LEVEL 2";
static const char strLevel3[] PROGMEM = "LEVEL 3";
static const char strLevel4[] PROGMEM = "LEVEL 4";
static const char strLevel5[] PROGMEM = "LEVEL 5";
static const char strLevel6[] PROGMEM = "LEVEL 6";
static const char strLevel7[] PROGMEM = "LEVEL 7";
static const char strLevel8[] PROGMEM = "LEVEL 8";
static const char strLevel9[] PROGMEM = "LEVEL 9";
static const char strLevel10[] PROGMEM = "LEVEL 10";
static const char strCompleted[] PROGMEM = "YOU COMPLETED ALL STAGES!";

byte COLOR_BLACK = 0;
byte COLOR_RED = 1;
byte COLOR_GREEN = 2;
byte COLOR_YELLOW = 3;

// 0 = MENU
// 1 = GAME
// 2 = GAME OVER
// 3 = COMPLETE GAME
byte gameState = 0;

bool joyUp = 0;
bool joyDown = 0;
bool joyLeft = 0;
bool joyRight = 0;

byte prevActionButton = 0;
byte actionButton = 0;

byte moveX = 0;
byte moveY = 0;

// 1 = UP
// 2 = RIGHT
// 3 = DOWN
// 4 = LEFT
byte snakeDir = 2;

byte snakeX[50];
byte snakeY[50];
byte snakeLength = 3;
byte snakeMaxLength = 50;
byte snakeDelay = 60;

byte borderX = 0;
byte borderY = 0;
byte borderWidth = VGAX_WIDTH;
byte borderHeight = VGAX_HEIGHT;

byte foodX;
byte foodY;
byte eatCount = 0;

byte counter = 0;
byte currentLevel = 1;

int foodTimer = 0;
byte foodLife = 200;

int snakeSegment;
int score = 0;
int prevScore = -1;

bool playIntro = true;

void setup() {

	vga.begin();

	randomSeed(analogRead(5));

	pinMode(11, INPUT);
	pinMode(12, INPUT);
	pinMode(13, INPUT);
	pinMode(4, INPUT);
	pinMode(5, INPUT);
	pinMode(10, OUTPUT);

	digitalWrite(10, HIGH);
}

void nextLevel() {

	currentLevel++;
	snakeDelay -= 5;
	score += 1000;

	vga.clear(0);

	if (currentLevel == 2)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel2, (VGAX_WIDTH / 2) - 17, (VGAX_HEIGHT / 2) - 3, COLOR_GREEN);
	}
	else if (currentLevel == 3)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel3, (VGAX_WIDTH / 2) - 17, (VGAX_HEIGHT / 2) - 3, COLOR_GREEN);
	}
	else if (currentLevel == 4)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel4, (VGAX_WIDTH / 2) - 17, (VGAX_HEIGHT / 2) - 3, COLOR_GREEN);
	}
	else if (currentLevel == 5)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel5, (VGAX_WIDTH / 2) - 17, (VGAX_HEIGHT / 2) - 3, COLOR_YELLOW);
	}
	else if (currentLevel == 6)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel6, (VGAX_WIDTH / 2) - 17, (VGAX_HEIGHT / 2) - 3, COLOR_YELLOW);
	}
	else if (currentLevel == 7)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel7, (VGAX_WIDTH / 2) - 17, (VGAX_HEIGHT / 2) - 3, COLOR_YELLOW);
	}
	else if (currentLevel == 8)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel8, (VGAX_WIDTH / 2) - 17, (VGAX_HEIGHT / 2) - 3, COLOR_RED);
	}
	else if (currentLevel == 9)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel9, (VGAX_WIDTH / 2) - 17, (VGAX_HEIGHT / 2) - 3, COLOR_RED);
	}
	else if (currentLevel == 10)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel10, (VGAX_WIDTH / 2) - 20, (VGAX_HEIGHT / 2) - 3, COLOR_RED);
	}
	else
	{
		gameState = 3;
		return;
	}

	vga.delay(500);
	playNote(NOTE_C4, 150);
	playNote(NOTE_C4, 150);
	playNote(NOTE_C4, 150);
	playNote(NOTE_F4, 300);

	vga.delay(2000);
	vga.clear(0);

	initSnake();
	eatCount = 0;
}

void initSnake() {

	snakeDir = random(1, 4);

	if (snakeDir == 1)
	{
		moveX = 0;
		moveY = -1;
	}
	else if (snakeDir == 2)
	{
		moveX = 1;
		moveY = 0;
	}
	else if (snakeDir == 3)
	{
		moveX = 0;
		moveY = 1;
	}
	else if (snakeDir == 4)
	{
		moveX = -1;
		moveY = 0;
	}

	foodTimer = 0;
	eatCount = 0;
	snakeLength = 3;
	snakeSegment = snakeLength - 1;
	for (byte i = 0; i < snakeMaxLength; i++)
	{
		snakeX[i] = 0;
		snakeY[i] = 0;
	}
	for (byte i = 0; i < snakeLength; i++)
	{
		snakeX[i] = 60 + i;
		snakeY[i] = 30;
	}
}

void readInput() {
	joyUp = digitalRead(5);
	joyDown = digitalRead(13);
	joyLeft = digitalRead(4);
	joyRight = digitalRead(12);
	actionButton = digitalRead(11);

	if (joyUp || joyDown)
	{
		joyLeft = 0;
		joyRight = 0;
	}

	if (joyLeft || joyRight)
	{
		joyUp = 0;
		joyDown = 0;
	}
}

void drawBorders(byte color) {
	vgaUtils.draw_line_safe(borderX, borderY + 8, (borderX + borderWidth) - 1, borderY + 8, color);
	vgaUtils.draw_line_safe(borderX, (borderY + borderHeight) - 1, (borderX + borderWidth), (borderY + borderHeight) - 1, color);
	vgaUtils.draw_line_safe(borderX, borderY + 8, borderX, (borderY + borderHeight) - 1, color);
	vgaUtils.draw_line_safe((borderX + borderWidth) - 1, borderY + 8, (borderX + borderWidth) - 1, (borderY + borderHeight) - 1, color);
}

void drawLevel(byte level, byte color) {
	if (level == 1)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel1, VGAX_WIDTH - 31, 0, COLOR_GREEN);
	} 
	else if (level == 2)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel2, VGAX_WIDTH - 32, 0, COLOR_GREEN);

		vgaUtils.draw_line_safe(borderX + 20, borderY + 20, borderX + 20, (borderY + borderHeight) - 12, color);
		vgaUtils.draw_line_safe((borderX + borderWidth) - 20, borderY + 20, (borderX + borderWidth) - 20, (borderY + borderHeight) - 12, color);	
	}
	else if (level == 3)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel3, VGAX_WIDTH - 32, 0, COLOR_GREEN);

		vgaUtils.draw_line_safe(borderX + 30, borderY + 17, (borderX + borderWidth) - 30, borderY + 17, color); 
		vgaUtils.draw_line_safe(borderX + 30, (borderY + borderHeight) - 10, (borderX + borderWidth) - 30, (borderY + borderHeight) - 10, color); 
	}
	else if (level == 4)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel4, VGAX_WIDTH - 32, 0, COLOR_GREEN);

		vgaUtils.draw_line_safe(borderX + 30, borderY + 17, (borderX + borderWidth) - 30, borderY + 17, color); 
		vgaUtils.draw_line_safe(borderX + 30, (borderY + borderHeight) - 10, (borderX + borderWidth) - 30, (borderY + borderHeight) - 10, color); 
		vgaUtils.draw_line_safe(borderX + 15, borderY + 20, borderX + 15, (borderY + borderHeight) - 12, color); 
		vgaUtils.draw_line_safe((borderX + borderWidth) - 15, borderY + 20, (borderX + borderWidth) - 15, (borderY + borderHeight) - 12, color);
	}
	else if (level == 5)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel5, VGAX_WIDTH - 32, 0, COLOR_YELLOW);

		vgaUtils.draw_line_safe(borderX + 15, borderY + 17, (borderX + borderWidth) - 30, borderY + 17, color);
		vgaUtils.draw_line_safe(borderX + 30, (borderY + borderHeight) - 10, (borderX + borderWidth) - 14, (borderY + borderHeight) - 10, color);
		vgaUtils.draw_line_safe(borderX + 15, borderY + 17, borderX + 15, (borderY + borderHeight) - 12, color);
		vgaUtils.draw_line_safe((borderX + borderWidth) - 15, borderY + 20, (borderX + borderWidth) - 15, (borderY + borderHeight) - 10, color);
	}
	else if (level == 6)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel6, VGAX_WIDTH - 32, 0, COLOR_YELLOW);

		vgaUtils.draw_line_safe(borderX + 10, borderY + 15, borderX + 20, borderY + 15, color);
		vgaUtils.draw_line_safe(borderX + 20, borderY + 15, borderX + 20, borderY + 25, color);
		vgaUtils.draw_line_safe(borderX + 20, borderY + 25, borderX + 40, borderY + 25, color);

		vgaUtils.draw_line_safe(borderX + 10, (borderY + borderHeight) - 9, borderX + 20, (borderY + borderHeight) - 9, color);
		vgaUtils.draw_line_safe(borderX + 20, (borderY + borderHeight) - 8, borderX + 20, (borderY + borderHeight) - 19, color);
		vgaUtils.draw_line_safe(borderX + 20, (borderY + borderHeight) - 19, borderX + 40, (borderY + borderHeight) - 19, color);

		vgaUtils.draw_line_safe((borderX + borderWidth) - 10, borderY + 15, (borderX + borderWidth) - 20, borderY + 15, color);
		vgaUtils.draw_line_safe((borderX + borderWidth) - 20, borderY + 15, (borderX + borderWidth) - 20, borderY + 25, color);
		vgaUtils.draw_line_safe((borderX + borderWidth) - 19, borderY + 25, (borderX + borderWidth) - 40, borderY + 25, color);

		vgaUtils.draw_line_safe((borderX + borderWidth) - 10, (borderY + borderHeight) - 9, (borderX + borderWidth) - 20, (borderY + borderHeight) - 9, color);
		vgaUtils.draw_line_safe((borderX + borderWidth) - 20, (borderY + borderHeight) - 8, (borderX + borderWidth) - 20, (borderY + borderHeight) - 19, color);
		vgaUtils.draw_line_safe((borderX + borderWidth) - 20, (borderY + borderHeight) - 19, (borderX + borderWidth) - 40, (borderY + borderHeight) - 19, color);
	}
	else if (level == 7)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel7, VGAX_WIDTH - 32, 0, COLOR_YELLOW);

		vgaUtils.draw_line_safe(borderX + 10, borderY + 14, borderX + 10, (borderY + borderHeight) - 6, color);
		vgaUtils.draw_line_safe(borderX + 20, borderY + 14, borderX + 20, (borderY + borderHeight) - 6, color);
		vgaUtils.draw_line_safe(borderX + 30, borderY + 14, borderX + 30, (borderY + borderHeight) - 6, color);

		vgaUtils.draw_line_safe((borderX + borderWidth) - 10, borderY + 14, (borderX + borderWidth) - 10, (borderY + borderHeight) - 6, color);
		vgaUtils.draw_line_safe((borderX + borderWidth) - 20, borderY + 14, (borderX + borderWidth) - 20, (borderY + borderHeight) - 6, color);
		vgaUtils.draw_line_safe((borderX + borderWidth) - 30, borderY + 14, (borderX + borderWidth) - 30, (borderY + borderHeight) - 6, color);
	}
	else if (level == 8)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel8, VGAX_WIDTH - 32, 0, COLOR_RED);

		vgaUtils.draw_line_safe(borderX + 10, borderY + 32, borderX + 30, borderY + 32, color);
		vgaUtils.draw_line_safe((borderX + borderWidth) - 10, borderY + 32, (borderX + borderWidth) - 30, borderY + 32, color);
		vgaUtils.draw_line_safe(borderX + 40, borderY + 18, (borderX + borderWidth) - 40, borderY + 18, color);
		vgaUtils.draw_line_safe(borderX + 40, borderY + 48, (borderX + borderWidth) - 40, borderY + 48, color);
	}
	else if (level == 9)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel9, VGAX_WIDTH - 32, 0, COLOR_RED);

		vgaUtils.draw_line_safe((borderX + borderWidth) - 10, borderY + 14, (borderX + borderWidth) - 10, (borderY + borderHeight) - 6, color);
		vgaUtils.draw_line_safe((borderX + borderWidth) - 20, borderY + 22, (borderX + borderWidth) - 20, (borderY + borderHeight) - 14, color);
		vgaUtils.draw_line_safe((borderX + borderWidth) - 30, borderY + 14, (borderX + borderWidth) - 30, (borderY + borderHeight) - 6, color);
		vgaUtils.draw_line_safe((borderX + borderWidth) - 40, borderY + 22, (borderX + borderWidth) - 40, (borderY + borderHeight) - 14, color);
		vgaUtils.draw_line_safe((borderX + borderWidth) - 50, borderY + 14, (borderX + borderWidth) - 50, (borderY + borderHeight) - 6, color);

		vgaUtils.draw_line_safe(borderX + 10, borderY + 14, borderX + 10, (borderY + borderHeight) - 6, color);
		vgaUtils.draw_line_safe(borderX + 20, borderY + 22, borderX + 20, (borderY + borderHeight) - 14, color);
		vgaUtils.draw_line_safe(borderX + 30, borderY + 14, borderX + 30, (borderY + borderHeight) - 6, color);
		vgaUtils.draw_line_safe(borderX + 40, borderY + 22, borderX + 40, (borderY + borderHeight) - 14, color);
		vgaUtils.draw_line_safe(borderX + 50, borderY + 14, borderX + 50, (borderY + borderHeight) - 6, color);
	}
	else if (level == 10)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strLevel10, VGAX_WIDTH - 36, 0, COLOR_RED);

		vgaUtils.draw_line_safe((borderX + borderWidth) - 10, borderY + 14, (borderX + borderWidth) - 10, (borderY + borderHeight) - 7, color);
		vgaUtils.draw_line_safe(borderX + 10, borderY + 14, (borderX + borderWidth) - 10, borderY + 14, color);
		vgaUtils.draw_line_safe(borderX + 10, (borderY + borderHeight) - 7, (borderX + borderWidth) - 9, (borderY + borderHeight) - 7, color);
		vgaUtils.draw_line_safe(borderX + 10, borderY + 14, borderX + 10, borderY + 28, color);
		vgaUtils.draw_line_safe(borderX + 10, borderY + 33, borderX + 10, (borderY + borderHeight) - 7, color);

		vgaUtils.draw_line_safe((borderX + borderWidth) - 20, borderY + 21, (borderX + borderWidth) - 20, borderY + 38, color);
		vgaUtils.draw_line_safe((borderX + borderWidth) - 20, borderY + 43, (borderX + borderWidth) - 20, (borderY + borderHeight) - 14, color);
		vgaUtils.draw_line_safe(borderX + 20, borderY + 21, (borderX + borderWidth) - 20, borderY + 21, color);
		vgaUtils.draw_line_safe(borderX + 20, (borderY + borderHeight) - 14, (borderX + borderWidth) - 19, (borderY + borderHeight) - 14, color);
		vgaUtils.draw_line_safe(borderX + 20, borderY + 21, borderX + 20, (borderY + borderHeight) - 14, color);
	}
}

void deleteTail() {

	vga.putpixel(snakeX[snakeSegment], snakeY[snakeSegment], COLOR_BLACK);

	if (snakeSegment == snakeLength - 1)
	{
		snakeX[snakeSegment] = snakeX[0] + moveX;
		snakeY[snakeSegment] = snakeY[0] + moveY;
	}
	else
	{
		snakeX[snakeSegment] = snakeX[snakeSegment + 1] + moveX;
		snakeY[snakeSegment] = snakeY[snakeSegment + 1] + moveY;
	}
}

void seedFood() {

	if (gameState != 1)
	{
		return;
	}

	if (vga.getpixel(foodX, foodY) == COLOR_YELLOW)
	{
		vga.putpixel(foodX, foodY, COLOR_BLACK);
	}

	foodX = random(borderX + 4, (borderX + borderWidth) - 4);
	foodY = random(borderY + 12, (borderY + borderHeight) - 12);

	if (vga.getpixel(foodX, foodY) == COLOR_RED || vga.getpixel(foodX, foodY) == COLOR_GREEN)
	{
		seedFood();
		return;
	}

	playNote(NOTE_F6, 50);
	vga.putpixel(foodX, foodY, COLOR_YELLOW);
	foodTimer = 0;
}

void drawFood() {

	if (snakeX[snakeSegment] == foodX && snakeY[snakeSegment] == foodY) {
		snakeLength = clamp(snakeLength + 5, snakeMaxLength, 1);
		score += 10;
		eatCount++;

		playNote(NOTE_C6, 100);

		if (eatCount == 10)
		{
			nextLevel();
		}

		seedFood();
	}
	else 
	{
		if (foodTimer >= foodLife)
		{
			score -= 5;

			if (score < 0) {
				score = 0;
			}

			seedFood();
		}
	}
}

void drawScore() {

	if (prevScore == score)
	{
		return;
	}

	vgaUtils.draw_rect(0, 0, 35, 6, 0, COLOR_BLACK);

	byte x = 25;
	byte cnt = 0;

	int value = score;

	while (value > 0)
	{
		int digit = value % 10;

		if (digit == 0)
		{
			vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, str0, x, 0, COLOR_YELLOW);
		}
		else if (digit == 1)
		{
			vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, str1, x, 0, COLOR_YELLOW);
		}
		else if (digit == 2)
		{
			vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, str2, x, 0, COLOR_YELLOW);
		}
		else if (digit == 3)
		{
			vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, str3, x, 0, COLOR_YELLOW);
		}
		else if (digit == 4)
		{
			vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, str4, x, 0, COLOR_YELLOW);
		}
		else if (digit == 5)
		{
			vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, str5, x, 0, COLOR_YELLOW);
		}
		else if (digit == 6)
		{
			vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, str6, x, 0, COLOR_YELLOW);
		}
		else if (digit == 7)
		{
			vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, str7, x, 0, COLOR_YELLOW);
		}
		else if (digit == 8)
		{
			vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, str8, x, 0, COLOR_YELLOW);
		}
		else if (digit == 9)
		{
			vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, str9, x, 0, COLOR_YELLOW);
		}

		x -= 5;
		value /= 10;
		cnt++;
	}

	byte remnant = 6 - cnt;
	while (remnant > 0)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, str0, x, 0, COLOR_YELLOW);
		x -= 5;
		remnant -= 1;
	}

	prevScore = score;
}

void loop() {

	counter++;

	readInput();

	// MENU
	if (gameState == 0)
	{
		vga.delay(100);

		/*vgaUtils.draw_line_safe(0, VGAX_HEIGHT - 21, VGAX_WIDTH, VGAX_HEIGHT - 21, (counter % 3) + 1);
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strStart, (VGAX_WIDTH / 2) - 28, (VGAX_HEIGHT / 2) - 3, (counter % 3) + 1);
		vgaUtils.draw_line_safe(0, 20, VGAX_WIDTH, 20, (counter % 3) + 1);*/

		vga.copy((byte*)img_splash_data);

		playIntroSong();

		if (actionButton == 1)
		{
			reset();
			gameState = 1;
			seedFood();
		}
	}

	// GAME
	else if (gameState == 1)
	{
		foodTimer++;

		if (snakeDir == 2 || snakeDir == 4)
		{
			if (joyUp == 1)
			{
				joyLeft = 0;
				joyRight = 0;
				moveX = 0;
				moveY = -1;
				snakeDir = 1;
			}
			else if (joyDown == 1)
			{
				joyLeft = 0;
				joyRight = 0;
				moveX = 0;
				moveY = 1;
				snakeDir = 3;
			}
		}
		else if (snakeDir == 1 || snakeDir == 3)
		{
			if (joyRight == 1)
			{
				joyUp = 0;
				joyDown = 0;
				moveY = 0;
				moveX = 1;
				snakeDir = 2;
			}
			else if (joyLeft == 1)
			{
				joyUp = 0;
				joyDown = 0;
				moveY = 0;
				moveX = -1;
				snakeDir = 4;
			}
		}

		drawScore();
		drawLevel(currentLevel, COLOR_RED);
		drawBorders(COLOR_RED);
		deleteTail();

		if (vga.getpixel(snakeX[snakeSegment], snakeY[snakeSegment]) == COLOR_BLACK || vga.getpixel(snakeX[snakeSegment], snakeY[snakeSegment]) == COLOR_YELLOW)
		{
			vga.putpixel(snakeX[snakeSegment], snakeY[snakeSegment], COLOR_GREEN);
		}
		else
		{
			playNote(NOTE_C3, 100);
			vga.clear(0);
			gameState = 2;
		}

		drawFood();

		snakeSegment--;
		if (snakeSegment < 0)
		{
			snakeSegment = snakeLength - 1;
		}

		vga.delay(snakeDelay);
		return;
	}

	// GAME OVER
	else if (gameState == 2)
	{
		vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strGameOver, (VGAX_WIDTH / 2) - 23, (VGAX_HEIGHT / 2) - 3, COLOR_RED);
		vga.delay(250);
		playNote(NOTE_C3, 300);
		playNote(NOTE_F2, 300);
		vga.delay(2000);
		reset();
		gameState = 0;
	}

	// COMPLETED GAME
	else if (gameState == 3)
	{
		for (byte i = 0; i < 4; i++)
		{
			for (byte j = 0; j < 12; j++)
			{
				vga.printPROGMEM((byte*)fnt_data, FTN_SYMBOLS_COUNT, FTN_HEIGHT, 1, 1, strCompleted, 2, (VGAX_HEIGHT / 2) - 3, (j % 3) + 1);
				vga.delay(100);
			}

			playNote(NOTE_C4, 150);
			playNote(NOTE_C4, 150);
			playNote(NOTE_C4, 150);
			playNote(NOTE_E4, 300);
			playNote(NOTE_C4, 150);
			playNote(NOTE_G4, 400);
		}

		reset();
		gameState = 0;
	}

	vga.delay(30);
}

void reset() {
	vga.clear(0);
	score = 0;
	prevScore = -1;
	counter = 0;
	borderX = 0;
	borderY = 0;
	borderWidth = VGAX_WIDTH;
	borderHeight = VGAX_HEIGHT;
	currentLevel = 1;
	snakeDelay = 60;
	playIntro = true;
	initSnake();
}

void playIntroSong() {
	if (playIntro) {
		vga.delay(500);
		playNote(NOTE_A4, 83);
		vga.delay(108);
		playNote(NOTE_C5, 83);
		vga.delay(108);
		playNote(NOTE_B4, 83);
		vga.delay(108);
		playNote(NOTE_A4, 83);
		vga.delay(108);
		playNote(NOTE_A4, 83);
		vga.delay(108);
		playNote(NOTE_D5, 83);
		vga.delay(108);
		playNote(NOTE_C5, 83);
		vga.delay(108);
		playNote(NOTE_B4, 83);
		vga.delay(108);
		playIntro = false;
	}
}

void playNote(int note, int delay)
{
	vga.tone(note);
	vga.delay(delay);
	vga.noTone();
}

byte clamp(byte val, byte upper, byte lower)
{
	return min(upper, max(val, lower));
}
