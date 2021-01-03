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
typedef struct{
	const char* question;
	const char* yes; //0
	const char* no; //1
	uint8_t answare;
}Answers;

static const Answers game1[] = {
		{"Capital of Spain ?","Andorra", "Madrid",1},
		{"Capital of Italy ?","aasdf", "ggggg",0},
		{"Capital of Germany ?","3244as", "asdf234",1},
		{"Capital of Russia ?","Madrid","Berlin",1},
		{"Capital of Spain ?","Ecuador","Venezuela",1},
		{"Capital of Germany ?","Suiza","Berlin",0},
		{"Capital of France ?","Ecuador",	"Venezuela",0}
};
static const Answers game4[] = {
		{"__ave","LL", "Y", 0},
		{"__ueso","Q", "K", 0},
};




#endif /* INC_GAME_DATA_H_ */
