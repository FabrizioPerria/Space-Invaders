#include "Video.h"
#include "font.h"

#define ENABLE_ALPHA_BLEND	// 0 in the framebuffer means alpha channel

#define RESET_VALUE 0


	static unsigned char frameBuffer[SCREEN_WIDTH * SCREEN_HEIGHT / 8] = {RESET_VALUE};
	//------------initVideo------------
// Initialization of the video related devices and data structures 
// Input: none
// Output: none
void initVideo(void)
{
	int numElements = sizeof(initVideoList) / sizeof(void*);
	int i = 0;
	
	for (i = 0; i < numElements; ++i ) {
		initVideoList[i]();
	}
	
	setCursor(0,0);
}

//------------setCursor------------
// set where you are going to start drawing in the screen
// Input: x and y coordinates of the screen
// Output: none
void setCursor(int x, int y)
{
	if((x > 11) || (y > 5)){        // bad input
		return;                       // do nothing
  }
  // multiply newX by FONT_WIDTH because each character is columns wide
  sendCMD(0x80 | (x * FONT_WIDTH));     // setting bit 7 updates X-position
  sendCMD(0x40 | y );         						// setting bit 6 updates Y-position
}


//------------drawSection------------
// draw a set of pixels defined by ySection in the frameBuffer in position x and y
// Input: x and y coordinates of the screen, ySection is the 8bit values to color 8 pixels in a column
// Output: none
void drawSection(int x, int y, unsigned long ySection)
{
#ifdef ENABLE_ALPHA_BLEND
	unsigned char *fb = &frameBuffer[((y / 8) * SCREEN_WIDTH) + x];
	if((((y / 8) * SCREEN_WIDTH) + x) < (SCREEN_WIDTH * SCREEN_HEIGHT / 8)) {
			(*fb) |= ySection;
	}
#else
	if((((y / 8) * SCREEN_WIDTH) + x) < (SCREEN_WIDTH * SCREEN_HEIGHT / 8))
		frameBuffer[((y / 8) * SCREEN_WIDTH) + x] = ySection;
#endif
}


//------------clearBuffer------------
// Reset the frameBuffer(all the values are set to 0)
// Input: none
// Output: none
void clearBuffer(void)
{
	int i = 0;
	for(i = 0; i < (SCREEN_WIDTH * SCREEN_HEIGHT / 8); ++i)
		frameBuffer[i] = RESET_VALUE;
}


//------------drawChar------------
// Given the character and its position, draw it on the frameBuffer
// Input: x and y coordinates on the screen, ch is the character
// Output: none
void drawChar(int x, int y, unsigned char ch)
{
	int k = 0;
	if(ch < 0x20){                  //the font i'm using starts from the 0x20 of the ascii code, 
																	//so from 0 to 0x1F the non-pritable characters are not considered)
		return;
	}else{
		for(k = 0; k < FONT_WIDTH; k++){
			drawSection(x + k, y, font[8 * (ch - ' ') + k]);
		}
	}
}


//------------num2str------------
// Translate a number into a string (used by printString in case of %d)
// Input: number and base (only 10 used)
// Output: string containing the number.
static char *num2Str(unsigned int num,int base)
{
	static char buffer[33];				// keep it static otherwise at the end of the function the buffer will be discarded...
	char *ptr;
	if (base == 0 || base > 16) 
		return 0;
	ptr=&buffer[sizeof(buffer)-1];
	*ptr='\0';
	do{
		*--ptr="0123456789ABCDEF"[num%base];
		num/=base;
	}while(num != 0);

	return(ptr);
}


//------------printString------------
// simplified printf-like function to put a string in the frame buffer and print a number through %d
// Input: x and y coordinates on the screen, format of the string and its possible fields
// Output: none
void printString(int x, int y, char const *format, ...)
{
	char const *p=0;
	int i=0;
	va_list arguments;
	va_start(arguments,format);

	for(p=format; *p!='\0'; p++){
		if(*p!='%'){
			if(*p == '\n'){
				x = 0;
				y += FONT_HEIGHT;
			} else {
				drawChar(x,y,*p);
				x += FONT_WIDTH;
				if(x >= SCREEN_WIDTH){
					x = 0;
					y += FONT_HEIGHT;
				}
			}			
			continue;
		} else {
			p++;
			switch(*p){
				case 'd':
					i=va_arg(arguments,int);
					if(i < 0){
						drawChar(x, y, '-');
						i = -i;
					}
					printString(x,y,num2Str(i,10));
					x += FONT_WIDTH;
					if(x >= SCREEN_WIDTH){
						x = 0;
						y += FONT_HEIGHT;
					}
					break;
			}
		}
	}
	va_end(arguments);
}


//------------drawElement------------
// put 16x8 images on the frame Buffer
// Input: x and y coordinates on the screen, width of the image (the height is always 8) 
// and the pointer to the bitmap of the image
// Output: none
void drawElement(int x, int y, int width, unsigned char const *element)
{
	int k = 0;
	int section = 0;
	for(k = 0; k < width; k++){
		section = element[k] << (y % 8);
		drawSection(x + k, y, section & 0xFF);
		if((y % 8) && (section > 0xFF)) {
				drawSection(x + k + SCREEN_WIDTH, y, (section & 0xFF00) >> 8);
		}
	}
}


//------------displayBuffer------------
// function to send the frame buffer to the display and see things there :)
// Input: none
// Output: none
void displayBuffer(void)
{
	int i = 0;
	for(i = 0; i < (SCREEN_WIDTH * SCREEN_HEIGHT / 8); ++i)
		sendDATA(frameBuffer[i]);
	
	//Reset cursor's position
	setCursor(0,0);
}
