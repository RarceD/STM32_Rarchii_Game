/*
 * gameplay_logic.c
 *
 *  Created on: 3 ene. 2021
 *      Author: Tecnica2
 */

#include "gameplay_logic.h"

void gameplay_1_confirm(Player *child) {

	//I check if is the right response:
	if (game1[child->game_questions].answare == child->selected_game_item) {
		HAL_GPIO_WritePin(RGB_BLUE_GPIO_Port, RGB_BLUE_Pin, 0);
		child->points++;
	} else {
		HAL_GPIO_WritePin(RGB_BLUE_GPIO_Port, RGB_BLUE_Pin, 1);
	}
	//Add the points in case of win and then roll over other question:
	child->game_questions++;
	child->selected_game_item = 0;
	if (child->game_questions <= 5) {
		SSD1306_Clear();
		SSD1306_GotoXY(0, 0);
		SSD1306_Puts(game1[child->game_questions].question, &Font_7x10, 1);
		SSD1306_GotoXY(0, 30);
		SSD1306_Puts(game1[child->game_questions].yes, &Font_7x10, 1);
		SSD1306_GotoXY(80, 30);
		SSD1306_Puts(game1[child->game_questions].no, &Font_7x10, 1);
		child->selected_game_item = 0;
		SSD1306_GotoXY(20, 50);
		SSD1306_Puts("<=>", &Font_7x10, 1);
		//SSD1306_GotoXY(100, 50);
		//SSD1306_Puts("<=>", &Font_7x10, 1);
		SSD1306_UpdateScreen();
	} else {
		SSD1306_Clear();
		child->state_machine = INIT;
		SSD1306_DrawBitmap(0, 0, image_data_test_real, 128, 64, 1);
		SSD1306_GotoXY(0, 0);
		SSD1306_Puts("PTS:", &Font_11x18, 1);
		SSD1306_GotoXY(42, 0);
		char *numberstring[(((sizeof child->points)) + 2) / 3 + 2];
		sprintf((char *)numberstring, "%d", child->points);
		SSD1306_Puts(numberstring, &Font_11x18, 1);
		SSD1306_UpdateScreen(); //display
		HAL_GPIO_WritePin(RGB_BLUE_GPIO_Port, RGB_BLUE_Pin, 0);
		HAL_GPIO_WritePin(RGB_GREEN_GPIO_Port, RGB_GREEN_Pin, 1);

	}
	HAL_Delay(100);

}
void gameplay_2_confirm(Player *child) {

	//I check if is the right response:
	if (game2[child->game_questions].answare == child->selected_game_item) {
		HAL_GPIO_WritePin(RGB_BLUE_GPIO_Port, RGB_BLUE_Pin, 0);
		child->points++;
	} else {
		HAL_GPIO_WritePin(RGB_BLUE_GPIO_Port, RGB_BLUE_Pin, 1);
	}
	//Add the points in case of win and then roll over other question:
	child->game_questions++;
	child->selected_game_item = 0;
	if (child->game_questions <= 5) {
		SSD1306_Clear();
		SSD1306_GotoXY(0, 0);
		SSD1306_Puts(game2[child->game_questions].question, &Font_11x18, 1);
		int position_icon = 20;
		SSD1306_DrawBitmap(position_icon, 20,
				game2[child->game_questions].icon_1, 25, 25, 1);
		position_icon += 60;
		SSD1306_DrawBitmap(position_icon, 20,
				game2[child->game_questions].icon_2, 25, 25, 1);
		SSD1306_GotoXY(22, 50);
		SSD1306_Puts("<=>", &Font_7x10, 1);
		//SSD1306_GotoXY(100, 50);
		//SSD1306_Puts("<=>", &Font_7x10, 1);
		SSD1306_UpdateScreen();
	} else {
		SSD1306_Clear();
		child->state_machine = INIT;
		SSD1306_DrawBitmap(0, 0, image_data_test_real, 128, 64, 1);
		SSD1306_GotoXY(0, 0);
		SSD1306_Puts("PTS:", &Font_11x18, 1);
		SSD1306_GotoXY(42, 0);
		char *numberstring[(((sizeof child->points)) + 2) / 3 + 2];
		sprintf((char *)numberstring, "%d", child->points);
		SSD1306_Puts(numberstring, &Font_11x18, 1);
		SSD1306_UpdateScreen(); //display
		HAL_GPIO_WritePin(RGB_BLUE_GPIO_Port, RGB_BLUE_Pin, 0);
		HAL_GPIO_WritePin(RGB_GREEN_GPIO_Port, RGB_GREEN_Pin, 1);

	}
	HAL_Delay(100);

}

void gameplay_3_confirm(Player *child) {

	//I check if is the right response:
	if (game2[child->game_questions].answare == child->selected_game_item) {
		HAL_GPIO_WritePin(RGB_BLUE_GPIO_Port, RGB_BLUE_Pin, 0);
		child->points++;
	} else {
		HAL_GPIO_WritePin(RGB_BLUE_GPIO_Port, RGB_BLUE_Pin, 1);
	}
	//Add the points in case of win and then roll over other question:
	child->game_questions++;
	child->selected_game_item = 0;
	if (child->game_questions <= 5) {
		SSD1306_Clear();

		SSD1306_GotoXY(0, 0);
		SSD1306_Puts(game3[child->game_questions].question, &Font_11x18, 1);
		SSD1306_GotoXY(20-5, 30);
		SSD1306_Puts(game3[child->game_questions].yes, &Font_11x18, 1);
		SSD1306_GotoXY(100-5, 30);
		SSD1306_Puts(game3[child->game_questions].no, &Font_11x18, 1);
		child->selected_game_item = 0;
		SSD1306_GotoXY(20, 50);
		SSD1306_Puts("<=>", &Font_7x10, 1);
	} else {
		SSD1306_Clear();
		child->state_machine = INIT;
		SSD1306_DrawBitmap(0, 0, image_data_test_real, 128, 64, 1);
		SSD1306_GotoXY(0, 0);
		SSD1306_Puts("PTS:", &Font_11x18, 1);
		SSD1306_GotoXY(42, 0);
		char *numberstring[(((sizeof child->points)) + 2) / 3 + 2];
		sprintf((char *)numberstring, "%d", child->points);
		SSD1306_Puts(numberstring, &Font_11x18, 1);
		HAL_GPIO_WritePin(RGB_BLUE_GPIO_Port, RGB_BLUE_Pin, 0);
		HAL_GPIO_WritePin(RGB_GREEN_GPIO_Port, RGB_GREEN_Pin, 1);
	}
	SSD1306_UpdateScreen(); //display
	HAL_Delay(100);

}

