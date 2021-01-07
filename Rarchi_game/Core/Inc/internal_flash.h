/*
 * internal_flash.h
 *
 *  Created on: Jan 7, 2021
 *      Author: Tecnica2
 */

#ifndef INC_INTERNAL_FLASH_H_
#define INC_INTERNAL_FLASH_H_

#include <string.h>
#include "main.h"

#define FLASH_STORAGE 0x08008000
#define page_size 0x800



void save_to_flash(uint8_t *data);
void read_flash(uint8_t *data);

#endif /* INC_INTERNAL_FLASH_H_ */
