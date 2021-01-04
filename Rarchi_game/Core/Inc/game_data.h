/*
 * game_data.h
 *
 *  Created on: 2 ene. 2021
 *      Author: Rarced
 *
 * Save all the data from the games
 */

#ifndef INC_GAME_DATA_H_
#define INC_GAME_DATA_H_
#include "cartoons.h"

typedef struct{
	const char* question;
	const char* yes; //0
	const char* no; //1
	uint8_t answare;
}Answers;

typedef struct{
	uint8_t* icon_1;
	uint8_t* icon_2;
	uint8_t answare;
	const char* question;
}Icon_answers;

static const Answers game1[] = {
		{"Capital of Spain ?","Andorra", "Madrid",1},
		{"Capital of Italy ?","aasdf", "ggggg",0},
		{"Capital of Germany ?","3244as", "asdf234",1},
		{"Capital of Russia ?","Madrid","Berlin",1},
		{"Capital of Spain ?","Ecuador","Venezuela",1},
		{"Capital of Germany ?","Suiza","Berlin",0},
		{"Capital of France ?","Ecuador",	"Venezuela",0}
};
static const Icon_answers game2[] = {
		{icon_house,icon_circle, 0, "Casa"},
		{icon_circle,icon_house, 0, "Circulo"},
		{icon_house,icon_circle, 0, "Otro"},
		{icon_circle,icon_house, 0, "Imaginacion"},
		{icon_house,icon_circle, 0, "Casa"},
		{icon_circle,icon_house, 0, "Queso"}
};
static const Answers game3[] = {
		{"4 + _ = 7","3", "2", 0},
		{"5 - _ = -1","3", "6", 1},
		{"12 + _ = 10","-2", "4", 0},
		{"5 + _ = 7","3", "2", 1},
		{"5 - _ = -1","3", "6", 1},
		{"12 + _ = 10","-2", "4", 0},
		{"5 + _ = 7","3", "2", 1}

};
static const Answers game4[] = {
		{"_ave","LL", "Y", 0},
		{"hue_o","V", "B", 0},
		{"_ueso","Q", "K", 0},
		{"fran_a","G", "J", 1},
		{"ele_ante","F", "G", 1},
		{"_ueso","Q", "K", 0}
};




#endif /* INC_GAME_DATA_H_ */
