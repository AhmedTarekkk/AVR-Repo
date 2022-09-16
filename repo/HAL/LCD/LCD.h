/*
 * LCD.h
 *
 *  Created on: Aug 23, 2022
 *      Author: Ahmed
 */

#ifndef REPO_HAL_LCD_LCD_H_
#define REPO_HAL_LCD_LCD_H_

void LCD_Initialization();

void LCD_WriteCmd(uint8 Cmd);

void LCD_WriteData(uint8 Data);

void LCD_GoToPos(uint8 Row , uint8 Col);

void LCD_WriteString(uint8* String , uint8 Row , uint8 Col);

void LCD_StorePattern(uint8* Pattern,uint8 Index);

void LCD_WritePattern(uint8 Index , uint8 Row , uint8 Col);

#endif /* REPO_HAL_LCD_LCD_H_ */
