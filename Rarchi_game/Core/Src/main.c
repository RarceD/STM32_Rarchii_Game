/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "ssd1306.h"
#include "fonts.h"
#include "test.h"
#include "bitmap.h"
#include "cartoons.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
typedef struct {
	int points;
	uint8_t state_machine;
	uint8_t scrol_position;
} Player;
typedef enum {
	INIT, MENU, GAME_1, GAME_2, GAME_3, GAME_4
} State_machine;

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	/* USER CODE BEGIN 1 */
	Player children;
	children.points = 33;
	children.state_machine = INIT;
	children.scrol_position = 18;

	uint16_t timer_val;
	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_I2C1_Init();
	MX_TIM2_Init();
	/* USER CODE BEGIN 2 */
	SSD1306_Init(); // initialise
	HAL_TIM_Base_Init(&htim2);
	HAL_TIM_Base_Start_IT(&htim2);
	timer_val = __HAL_TIM_GET_COUNTER(&htim2);
	SSD1306_GotoXY(0, 0);
	SSD1306_Puts("PTS:", &Font_11x18, 1);
	SSD1306_GotoXY(42, 0);
	char *numberstring[(((sizeof children.points)) + 2) / 3 + 2];
	sprintf(numberstring, "%d", children.points++);
	SSD1306_Puts(numberstring, &Font_11x18, 1);
	HAL_GPIO_WritePin(RGB_GREEN_GPIO_Port, RGB_GREEN_Pin, 0);
	uint8_t update_screen = 0;
	SSD1306_DrawBitmap(0, 0, image_data_test_real, 128, 64, 1);
	SSD1306_UpdateScreen();
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {

		switch (children.state_machine) {
		case INIT:
			if (HAL_GPIO_ReadPin(BUTTON_RIGHT_GPIO_Port, BUTTON_RIGHT_Pin) == 0
					|| HAL_GPIO_ReadPin(BUTTON_LEFT_GPIO_Port, BUTTON_LEFT_Pin)
							== 0) {
				HAL_GPIO_WritePin(RGB_RED_GPIO_Port, RGB_RED_Pin, 1);
				HAL_GPIO_WritePin(RGB_GREEN_GPIO_Port, RGB_GREEN_Pin, 0);
				//I update the screen
				SSD1306_Clear();
				SSD1306_GotoXY(20, 18);
				SSD1306_Puts("GAME 1", &Font_7x10, 1);
				SSD1306_GotoXY(20, 28);
				SSD1306_Puts("GAME 2", &Font_7x10, 1);
				SSD1306_GotoXY(20, 38);
				SSD1306_Puts("GAME 3", &Font_7x10, 1);
				SSD1306_GotoXY(20, 48);
				SSD1306_Puts("GAME 4", &Font_7x10, 1);
				SSD1306_GotoXY(50, 0);
				SSD1306_Puts("Select game", &Font_7x10, 1);
				children.scrol_position = 28;
				SSD1306_GotoXY(10, 18);
				SSD1306_Puts(">", &Font_7x10, 1);
				SSD1306_UpdateScreen(); //display
				HAL_Delay(60);
				children.state_machine = MENU;
			}
			break;
		case MENU:
			if (HAL_GPIO_ReadPin(BUTTON_LEFT_GPIO_Port, BUTTON_LEFT_Pin) == 0) {
				SSD1306_GotoXY(10, 18);
				SSD1306_Puts(" ", &Font_7x10, 1);
				SSD1306_GotoXY(10, 28);
				SSD1306_Puts(" ", &Font_7x10, 1);
				SSD1306_GotoXY(10, 38);
				SSD1306_Puts(" ", &Font_7x10, 1);
				SSD1306_GotoXY(10, 48);
				SSD1306_Puts(" ", &Font_7x10, 1);
				SSD1306_GotoXY(10, children.scrol_position);
				SSD1306_Puts(">", &Font_7x10, 1);
				SSD1306_UpdateScreen(); //display
				if (children.scrol_position >= 48) {
					children.scrol_position = 18;
				} else if (children.scrol_position != 48) {
					children.scrol_position += 10;
				}
				HAL_Delay(60);
			}
			if (HAL_GPIO_ReadPin(BUTTON_RIGHT_GPIO_Port, BUTTON_RIGHT_Pin)
					== 0) {
				SSD1306_Clear();
				HAL_GPIO_WritePin(RGB_RED_GPIO_Port, RGB_RED_Pin, 0);
				HAL_GPIO_WritePin(RGB_GREEN_GPIO_Port, RGB_GREEN_Pin, 0);
				HAL_GPIO_WritePin(RGB_BLUE_GPIO_Port, RGB_BLUE_Pin, 1);
				SSD1306_GotoXY(0, 0);

				if (children.scrol_position == 28) {
					children.state_machine = GAME_1;
					SSD1306_Puts("GAME 1", &Font_11x18, 1);
				} else if (children.scrol_position == 38) {
					SSD1306_Puts("GAME 2", &Font_11x18, 1);
					children.state_machine = GAME_2;
				} else if (children.scrol_position == 48) {
					SSD1306_Puts("GAME 3", &Font_11x18, 1);
					children.state_machine = GAME_3;
				} else if (children.scrol_position == 18) {
					SSD1306_Puts("GAME 4", &Font_11x18, 1);
					children.state_machine = GAME_4;
				}
				SSD1306_UpdateScreen();
			}
			break;
		case (GAME_1):
			if (HAL_GPIO_ReadPin(BUTTON_RIGHT_GPIO_Port, BUTTON_RIGHT_Pin)
					== 0) {
				children.state_machine = INIT;
				character_draw(1);
				SSD1306_GotoXY(0, 0);
				SSD1306_Puts("PTS:", &Font_11x18, 1);
				SSD1306_GotoXY(42, 0);
				char *numberstring[(((sizeof children.points)) + 2) / 3 + 2];
				sprintf(numberstring, "%d", children.points++);
				SSD1306_Puts(numberstring, &Font_11x18, 1);
				SSD1306_UpdateScreen(); //display
				HAL_GPIO_WritePin(RGB_BLUE_GPIO_Port, RGB_BLUE_Pin, 0);
				HAL_GPIO_WritePin(RGB_GREEN_GPIO_Port, RGB_GREEN_Pin, 1);
			}
			break;
		case (GAME_2):
			if (HAL_GPIO_ReadPin(BUTTON_RIGHT_GPIO_Port, BUTTON_RIGHT_Pin)
					== 0) {
				children.state_machine = INIT;
				character_draw(1);
				SSD1306_GotoXY(0, 0);
				SSD1306_Puts("PTS:", &Font_11x18, 1);
				SSD1306_GotoXY(42, 0);
				char *numberstring[(((sizeof children.points)) + 2) / 3 + 2];
				sprintf(numberstring, "%d", children.points++);
				SSD1306_Puts(numberstring, &Font_11x18, 1);
				SSD1306_UpdateScreen(); //display
				HAL_GPIO_WritePin(RGB_BLUE_GPIO_Port, RGB_BLUE_Pin, 0);
				HAL_GPIO_WritePin(RGB_GREEN_GPIO_Port, RGB_GREEN_Pin, 1);
			}
			break;
		case (GAME_3):
			if (HAL_GPIO_ReadPin(BUTTON_RIGHT_GPIO_Port, BUTTON_RIGHT_Pin)
					== 0) {
				children.state_machine = INIT;
				character_draw(1);
				SSD1306_GotoXY(0, 0);
				SSD1306_Puts("PTS:", &Font_11x18, 1);
				SSD1306_GotoXY(42, 0);
				char *numberstring[(((sizeof children.points)) + 2) / 3 + 2];
				sprintf(numberstring, "%d", children.points++);
				SSD1306_Puts(numberstring, &Font_11x18, 1);
				SSD1306_UpdateScreen(); //display
				HAL_GPIO_WritePin(RGB_BLUE_GPIO_Port, RGB_BLUE_Pin, 0);
				HAL_GPIO_WritePin(RGB_GREEN_GPIO_Port, RGB_GREEN_Pin, 1);
			}
			break;
		case (GAME_4):
			if (HAL_GPIO_ReadPin(BUTTON_RIGHT_GPIO_Port, BUTTON_RIGHT_Pin)
					== 0) {
				children.state_machine = INIT;
				character_draw(1);
				SSD1306_GotoXY(0, 0);
				SSD1306_Puts("PTS:", &Font_11x18, 1);
				SSD1306_GotoXY(42, 0);
				char *numberstring[(((sizeof children.points)) + 2) / 3 + 2];
				sprintf(numberstring, "%d", children.points++);
				SSD1306_Puts(numberstring, &Font_11x18, 1);
				SSD1306_UpdateScreen(); //display
				HAL_GPIO_WritePin(RGB_BLUE_GPIO_Port, RGB_BLUE_Pin, 0);
				HAL_GPIO_WritePin(RGB_GREEN_GPIO_Port, RGB_GREEN_Pin, 1);
			}
			break;

		}

		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL15;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief I2C1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_I2C1_Init(void) {

	/* USER CODE BEGIN I2C1_Init 0 */

	/* USER CODE END I2C1_Init 0 */

	/* USER CODE BEGIN I2C1_Init 1 */

	/* USER CODE END I2C1_Init 1 */
	hi2c1.Instance = I2C1;
	hi2c1.Init.ClockSpeed = 400000;
	hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c1.Init.OwnAddress1 = 0;
	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c1.Init.OwnAddress2 = 0;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	if (HAL_I2C_Init(&hi2c1) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN I2C1_Init 2 */

	/* USER CODE END I2C1_Init 2 */

}

/**
 * @brief TIM2 Initialization Function
 * @param None
 * @retval None
 */
static void MX_TIM2_Init(void) {

	/* USER CODE BEGIN TIM2_Init 0 */

	/* USER CODE END TIM2_Init 0 */

	TIM_ClockConfigTypeDef sClockSourceConfig = { 0 };
	TIM_MasterConfigTypeDef sMasterConfig = { 0 };

	/* USER CODE BEGIN TIM2_Init 1 */

	/* USER CODE END TIM2_Init 1 */
	htim2.Instance = TIM2;
	htim2.Init.Prescaler = 6000 - 1;
	htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim2.Init.Period = 10000 - 1;
	htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
	if (HAL_TIM_Base_Init(&htim2) != HAL_OK) {
		Error_Handler();
	}
	sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK) {
		Error_Handler();
	}
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig)
			!= HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN TIM2_Init 2 */

	/* USER CODE END TIM2_Init 2 */

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(LED_BUILD_GPIO_Port, LED_BUILD_Pin, GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB, RGB_RED_Pin | RGB_BLUE_Pin | RGB_GREEN_Pin,
			GPIO_PIN_RESET);

	/*Configure GPIO pin : LED_BUILD_Pin */
	GPIO_InitStruct.Pin = LED_BUILD_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LED_BUILD_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : BUTTON_LEFT_Pin BUTTON_RIGHT_Pin */
	GPIO_InitStruct.Pin = BUTTON_LEFT_Pin | BUTTON_RIGHT_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/*Configure GPIO pins : RGB_RED_Pin RGB_BLUE_Pin RGB_GREEN_Pin */
	GPIO_InitStruct.Pin = RGB_RED_Pin | RGB_BLUE_Pin | RGB_GREEN_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	HAL_GPIO_TogglePin(RGB_RED_GPIO_Port, RGB_RED_Pin);

}
/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
