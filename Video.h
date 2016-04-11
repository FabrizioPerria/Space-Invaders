#ifndef __VIDEO_H
#	define __VIDEO_H

#include "Display.h"
#include "Enemies.h"
#include "Player.h"
#include "Bunker.h"

/* 
	 Video is a layer that allows to abstract the Display hardware details
   ad see it only as "Video device" where to write text or draw pictures.
*/

typedef void (*VideoInitFuncPtr)(void);

static VideoInitFuncPtr const initVideoList[] = {
	initDisplay,
	initEnemies,
	initPlayer,
	initBunker
};

/*
The following prototypes are required for the ellipsis operator inside printf
*/
typedef int* va_list;

#define va_start(argPtr, firstParam)	(argPtr=(va_list)(&firstParam+1))
#define va_arg(argPtr,type)						(* (((type*)(argPtr=(va_list)((type*)argPtr)+1))-1))
#define va_end(argPtr)								(argPtr=(void*)0)

//------------initVideo------------
// Initialization of the video related devices and data structures 
// Input: none
// Output: none
void initVideo(void);

//------------setCursor------------
// set where you are going to start drawing in the screen
// Input: x and y coordinates of the screen
// Output: none
void setCursor(int x, int y);

//------------drawSection------------
// draw a set of pixels defined by ySection in the frameBuffer in position x and y
// Input: x and y coordinates of the screen, ySection is the 8bit values to color 8 pixels in a column
// Output: none
void drawSection(int x, int y, unsigned long ySection);

//------------clearBuffer------------
// Reset the frameBuffer(all the values are set to 0)
// Input: none
// Output: none
void clearBuffer(void);

//------------drawChar------------
// Given the character and its position, draw it on the frameBuffer
// Input: x and y coordinates on the screen, ch is the character
// Output: none
void drawChar(int x, int y, unsigned char ch);

//------------printString------------
// simplified printf-like function to put a string in the frame buffer and print a number through %d
// Input: x and y coordinates on the screen, format of the string and its possible fields
// Output: none
void printString(int x, int y, const char *format,...);

//------------drawElement------------
// put 16x10 images on the frame Buffer
// Input: x and y coordinates on the screen, width of the image (the height is always 8) 
// and the pointer to the bitmap of the image
// Output: none
void drawElement(int x, int y, int width, unsigned char const *element);

//------------displayBuffer------------
// function to send the frame buffer to the display and see things there :)
// Input: none
// Output: none
void displayBuffer(void);

#endif
