/*
 * lcdIli9341.h
 *
 *  Created on: Aug 19, 2021
 *      Author: CVH
 */

#ifndef INC_LCDILI9341_H_
#define INC_LCDILI9341_H_

RET lcdIli9341_init();
void lcdIli9341_setArea(uint16_t xStart, uint16_t yStart, uint16_t xEnd, uint16_t yEnd);
void lcdIli9341_setAreaRead(uint16_t xStart, uint16_t yStart, uint16_t xEnd, uint16_t yEnd);
void lcdIli9341_drawRect(uint16_t xStart, uint16_t yStart, uint16_t width, uint16_t height, uint16_t color);
uint16_t* lcdIli9341_getDrawAddress();
void LCD_RESET(void);

#define LCD_ILI9341_COLOR_RED    0xf800
#define LCD_ILI9341_COLOR_GREEN  0x07e0
#define LCD_ILI9341_COLOR_BLUE   0x001f

#define LCD_ILI9341_WIDTH  320
#define LCD_ILI9341_HEIGHT 240

#endif /* INC_LCDILI9341_H_ */
