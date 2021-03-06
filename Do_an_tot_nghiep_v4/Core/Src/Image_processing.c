/*
 * Image_processing.c
 *
 *  Created on: Aug 20, 2021
 *      Author: CVH
 */


#include <stdio.h>
#include "main.h"
#include "stm32f4xx_hal.h"
#include "lcdIli9341.h"
#include "lcdIli9341Config.h"

uint16_t convRGB565(unsigned char lowByte, unsigned char highByte)
{
  uint8_t dataHigh = highByte ;
  uint8_t dataLow = lowByte;
  uint16_t data=dataHigh<< 8 | dataLow;
 //uint16_t data = dataLow<< 8 | dataHigh;
  return data;
}



RET RGB_Image(unsigned char *p_buffer, uint32_t lenght)
{
	uint16_t* p_lcdData;
	uint32_t n=0;
	lcdIli9341_setArea(0, 0, LCD_ILI9341_WIDTH - 1, LCD_ILI9341_HEIGHT - 1);
	p_lcdData=lcdIli9341_getDrawAddress();
		  for(uint16_t y = 0; y <  LCD_ILI9341_HEIGHT*2; y++)
		  	  for(uint16_t x = 0; x < LCD_ILI9341_WIDTH/2; x++){
		  		  uint16_t lcdData = convRGB565(*(p_buffer + (LCD_ILI9341_WIDTH*y) + 2*x), *(p_buffer + (LCD_ILI9341_WIDTH*y) +2*x + 1));
		  		 *p_lcdData = lcdData;
		  		 n++;
		  		 if(n>lenght) break;
		  	  	  }
	 return HAL_OK;
}

RET Gray_Image(unsigned char *p_buffer, uint32_t lenght)
{
	uint32_t n=0;
	uint16_t graypixel=0;
	lcdIli9341_setArea(0, 0, LCD_ILI9341_WIDTH - 1, LCD_ILI9341_HEIGHT - 1);
	uint16_t* p_lcdData=lcdIli9341_getDrawAddress();
	for(uint32_t y = 0; y <  LCD_ILI9341_HEIGHT*2; y++)
			  	  for(uint32_t x = 0; x < LCD_ILI9341_WIDTH/2; x++)
			  	  {
			  			graypixel=convRGB565(*(p_buffer + (LCD_ILI9341_WIDTH*y) + 2*x), *(p_buffer + (LCD_ILI9341_WIDTH*y) +2*x + 1));

			  		  graypixel = ((graypixel&248)<<8)|((graypixel&252)<<3)|((graypixel&248)>>3) ;
			  		  *p_lcdData = graypixel;
			  		  n=n+2;
			  		  if(n>lenght) break;
			  	  	  }
	 return HAL_OK;
}

RET Red_Image(unsigned char *p_buffer, uint32_t lenght)
{
	uint16_t* p_lcdData;
	lcdIli9341_setArea(0, 0, LCD_ILI9341_WIDTH - 1, LCD_ILI9341_HEIGHT - 1);
	p_lcdData=lcdIli9341_getDrawAddress();
		  for(uint16_t y = 0; y <  LCD_ILI9341_HEIGHT*2; y++)
		    {
		  	  for(uint16_t x = 0; x < LCD_ILI9341_WIDTH/2; x++){
		  		  uint16_t lcdData = convRGB565(*(p_buffer + (LCD_ILI9341_WIDTH*y) + 2*x), *(p_buffer + (LCD_ILI9341_WIDTH*y) +2*x + 1));
		  		 *p_lcdData = (lcdData & LCD_ILI9341_COLOR_RED);

		  	  	  }
		    }
	return HAL_OK;
}

RET Green_Image(unsigned char *p_buffer, uint32_t lenght)
{
	uint16_t* p_lcdData;
	lcdIli9341_setArea(0, 0, LCD_ILI9341_WIDTH - 1, LCD_ILI9341_HEIGHT - 1);
	p_lcdData=lcdIli9341_getDrawAddress();
		  for(uint16_t y = 0; y <  LCD_ILI9341_HEIGHT*2; y++)
		    {

			  for(uint16_t x = 0; x < LCD_ILI9341_WIDTH/2; x++){
		  		  uint16_t lcdData = convRGB565(*(p_buffer + (LCD_ILI9341_WIDTH*y) + 2*x), *(p_buffer + (LCD_ILI9341_WIDTH*y) +2*x + 1));
		  		 *p_lcdData = (lcdData & LCD_ILI9341_COLOR_GREEN);

		  	  	  }
		    }
}

RET Blue_Image(unsigned char *p_buffer, uint32_t lenght)
{
	uint16_t* p_lcdData;
	lcdIli9341_setArea(0, 0, LCD_ILI9341_WIDTH - 1, LCD_ILI9341_HEIGHT - 1);
	p_lcdData=lcdIli9341_getDrawAddress();
	for(uint16_t y = 0; y <  LCD_ILI9341_HEIGHT*2; y++)
		    {
		  	  for(uint16_t x = 0; x < LCD_ILI9341_WIDTH/2; x++)
		  	  {
		  		  uint16_t lcdData = convRGB565(*(p_buffer + (LCD_ILI9341_WIDTH*y) + 2*x), *(p_buffer + (LCD_ILI9341_WIDTH*y) +2*x + 1));
		  		 *p_lcdData = (lcdData & LCD_ILI9341_COLOR_BLUE);

		  	  }
		    }
	return HAL_OK;
}
RET Gray32_Image(unsigned char *p_buffer, uint32_t lenght)
{
	uint32_t check=0;
	uint16_t graypixel=0;
	lcdIli9341_setArea(0, 0, LCD_ILI9341_WIDTH - 1, LCD_ILI9341_HEIGHT - 1);
	uint16_t* p_lcdData=lcdIli9341_getDrawAddress();
	for(uint32_t y = 0; y <  LCD_ILI9341_HEIGHT*2; y++)
			    {
			  	  for(uint32_t x = 0; x < LCD_ILI9341_WIDTH/2; x++)
			  	  {
			  		  graypixel=convRGB565(*(p_buffer + (LCD_ILI9341_WIDTH*y) + 2*x), *(p_buffer + (LCD_ILI9341_WIDTH*y) +2*x + 1));

			  		  uint16_t r = graypixel>>11;
			  		  uint16_t g = (graypixel &  LCD_ILI9341_COLOR_GREEN)>>5;
			  		  uint16_t b =graypixel & LCD_ILI9341_COLOR_BLUE;
			  		  if(graypixel!=0xffff)
			  		  {
			  			  graypixel = (r+ g*(32/64) +b)/3;
			  			  graypixel = ((graypixel)<<11)|((graypixel*(64/32))<<5)|((graypixel)>>0) ;
			  		  }
			  		  *p_lcdData = graypixel;
			  		  check = check +2;
			  		  if(check>=153600) break;
			  	  	  }
			    }
	return HAL_OK;

}

RET Negative_Image(unsigned char *p_buffer, uint32_t lenght)
{
	uint32_t check=0;
		uint16_t negpixel=0;
		lcdIli9341_setArea(0, 0, LCD_ILI9341_WIDTH - 1, LCD_ILI9341_HEIGHT - 1);
		uint16_t* p_lcdData=lcdIli9341_getDrawAddress();
		for(uint32_t y = 0; y <  LCD_ILI9341_HEIGHT*2; y++)

				  	  for(uint32_t x = 0; x < LCD_ILI9341_WIDTH/2; x++)
				  	  {
				  		  negpixel=convRGB565(*(p_buffer + (LCD_ILI9341_WIDTH*y) + 2*x), *(p_buffer + (LCD_ILI9341_WIDTH*y) +2*x + 1));

				  		  uint16_t r = negpixel>>11;
				  		  uint16_t g = (negpixel &  LCD_ILI9341_COLOR_GREEN)>>5;
				  		  uint16_t b =negpixel & LCD_ILI9341_COLOR_BLUE;
				  		   negpixel = ((0x1f-r)<<11)|((0x3f-g)<<5)|((0x1f-b)>>0) ;
				  		  *p_lcdData = negpixel;
				  		  check = check +2;
				  		  if(check>=153600) break;
				  	  }
		return HAL_OK;
}

RET Bin_Image(unsigned char *p_buffer, uint32_t lenght)
{
		 uint16_t thress = 10;
		uint32_t check=0;
		uint16_t graypixel=0;
		uint16_t binpixel=0;
		lcdIli9341_setArea(0, 0, LCD_ILI9341_WIDTH - 1, LCD_ILI9341_HEIGHT - 1);
		uint16_t* p_lcdData=lcdIli9341_getDrawAddress();
		for(uint32_t y = 0; y <  LCD_ILI9341_HEIGHT*2; y++)

				  	  for(uint32_t x = 0; x < LCD_ILI9341_WIDTH/2; x++)
				  	  	  {
				  		  graypixel=convRGB565(*(p_buffer + (LCD_ILI9341_WIDTH*y) + 2*x), *(p_buffer + (LCD_ILI9341_WIDTH*y) +2*x + 1));

				  		  uint16_t r = graypixel>>11;
				  		  uint16_t g = (graypixel &  LCD_ILI9341_COLOR_GREEN)>>5;
				  		  uint16_t b =graypixel & LCD_ILI9341_COLOR_BLUE;
				  		  graypixel = (r + b*(64/32) + g)/3;
				  		  if(graypixel>=thress) binpixel= 0xffff;
				  		  else binpixel = 0;
				  		  *p_lcdData = binpixel;
				  		  check = check +2;
				  		  if(check>=153600) break;
				  	  	  }
		return HAL_OK;

}
RET ColorFiler_Image(unsigned char *p_buffer, uint32_t lenght, uint16_t color)
{
	uint16_t* p_lcdData;
	lcdIli9341_setArea(0, 0, LCD_ILI9341_WIDTH - 1, LCD_ILI9341_HEIGHT - 1);
	p_lcdData=lcdIli9341_getDrawAddress();
	for(uint16_t y = 0; y <  LCD_ILI9341_HEIGHT*2; y++)
		    {
		  	  for(uint16_t x = 0; x < LCD_ILI9341_WIDTH/2; x++)
		  	  {
		  		  uint16_t lcdData = convRGB565(*(p_buffer + (LCD_ILI9341_WIDTH*y) + 2*x), *(p_buffer + (LCD_ILI9341_WIDTH*y) +2*x + 1));
		  		 *p_lcdData = (lcdData & color);

		  	  }
		    }
	return HAL_OK;
}

RET Histogram(unsigned char *p_buffer, uint32_t lenght)
{

	return HAL_OK;
}

RET Histo(unsigned char *p_buffer, uint32_t lenght)
{

		return HAL_OK;
}
