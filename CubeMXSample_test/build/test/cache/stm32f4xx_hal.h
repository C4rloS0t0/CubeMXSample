typedef unsigned int uint32_t;

typedef unsigned short int uint16_t;

typedef struct

{

  uint32_t PLLState;





  uint32_t PLLSource;





  uint32_t PLLM;





  uint32_t PLLN;







  uint32_t PLLP;





  uint32_t PLLQ;



}RCC_PLLInitTypeDef;











typedef struct

{

  uint32_t OscillatorType;





  uint32_t HSEState;





  uint32_t LSEState;





  uint32_t HSIState;





  uint32_t HSICalibrationValue;





  uint32_t LSIState;





  RCC_PLLInitTypeDef PLL;

}RCC_OscInitTypeDef;











typedef struct

{

  uint32_t ClockType;





  uint32_t SYSCLKSource;





  uint32_t AHBCLKDivider;





  uint32_t APB1CLKDivider;





  uint32_t APB2CLKDivider;





}RCC_ClkInitTypeDef;











typedef struct

{

  uint32_t Pin;





  uint32_t Mode;





  uint32_t Pull;





  uint32_t Speed;





  uint32_t Alternate;



}GPIO_InitTypeDef;











typedef struct

{

  uint32_t MODER;

  uint32_t OTYPER;

  uint32_t OSPEEDR;

  uint32_t PUPDR;

  uint32_t IDR;

  uint32_t ODR;

  uint32_t BSRR;

  uint32_t LCKR;

  uint32_t AFR[2];

} GPIO_TypeDef;









typedef enum

{

  GPIO_PIN_RESET = 0,

  GPIO_PIN_SET

}GPIO_PinState;









typedef enum

{

  HAL_OK = 0x00U,

  HAL_ERROR = 0x01U,

  HAL_BUSY = 0x02U,

  HAL_TIMEOUT = 0x03U

} HAL_StatusTypeDef;





void HAL_Init();

HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);

void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency);

void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);

void HAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init);
