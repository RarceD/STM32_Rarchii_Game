/*
 * gameplay_logic.h
 *
 *  Created on: 3 ene. 2021
 *      Author: Tecnica2
 */

#ifndef INC_GAMEPLAY_LOGIC_H_
#define INC_GAMEPLAY_LOGIC_H_
#include "stm32f1xx_hal.h"
#include "ssd1306.h"
#include "game_data.h"
#include "cartoons.h"
#include "main.h"

typedef struct {
	int points;
	uint8_t state_machine;
	uint8_t scrol_position;
	uint16_t game_questions;
	uint8_t selected_game_item;
} Player;

typedef enum {
	INIT, MENU, GAME_1, GAME_2, GAME_3, GAME_4
} State_machine;



void gameplay_1_confirm(Player *child);

#endif /* INC_GAMEPLAY_LOGIC_H_ */
