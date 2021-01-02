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
	const char* yes;
	const char* no;
}Answers;
static const char* const game1_questions[] = {
		"Capital of Spain ?",
		"Capital of Italy ?",
		"Capital of Germany ?",
		"Capital of Russia ?",
		"Capital of Germany ?",
		"Capital of France ?"
};

static const Answers game1_answers_struct[] = {
		{"Andorra", "Madrid"},
		{"aasdf", "ggggg"},
		{"3244as", "asdf234"},
		{"Madrid","Berlin"},
		{"Ecuador","Venezuela"},
		{"Suiza","Berlin"},
		{"Ecuador",	"Venezuela"}

};




#endif /* INC_GAME_DATA_H_ */
