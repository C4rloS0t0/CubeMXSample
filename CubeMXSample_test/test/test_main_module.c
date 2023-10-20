#ifdef TEST

#include "unity.h"

#include "main_module.h"
#include "mock_stm32f4xx_hal.h"

#define EXPECTED_RESULT_HALOK 0
#define EXPECTED_RESULT_HALERROR 1

//Global variable definition to know if Error_Handler function is executed
int retVal;

void setUp(void)
{
    //For each test case retVal is initialized to zero
    retVal = 0;
}

void tearDown(void)
{
}

void test_main_module_OscConfigandClockConfig_HALOK(void)
{
    /*This test case tests the functions HAL_RCC_OscConfig and HAL_RCC_ClockConfig returning a HAL_OK value*/
    HAL_Init_Ignore();
    HAL_RCC_OscConfig_IgnoreAndReturn(HAL_OK);
    HAL_RCC_ClockConfig_IgnoreAndReturn(HAL_OK);
    HAL_GPIO_WritePin_Expect(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
    HAL_GPIO_Init_Ignore();
    HAL_GPIO_TogglePin_Expect(GPIOA, GPIO_PIN_5);
    (void)main_module();
    //retVal must not be affected so must be zero
    TEST_ASSERT_EQUAL_INT(EXPECTED_RESULT_HALOK, retVal);
}


void test_main_module_OscConfig_HALERROR(void)
{
    /*This test case tests the function HAL_RCC_OscConfig returning a non-HAL_OK value and HAL_RCC_ClockConfig returning a HAL_OK value*/
    HAL_Init_Ignore();
    HAL_RCC_OscConfig_IgnoreAndReturn(HAL_ERROR);
    HAL_RCC_ClockConfig_IgnoreAndReturn(HAL_OK);
    HAL_GPIO_WritePin_Expect(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
    HAL_GPIO_Init_Ignore();
    HAL_GPIO_TogglePin_Expect(GPIOA, GPIO_PIN_5);
    //Robustness test to ensure that retVal is set to zero before the main_module execution
    TEST_ASSERT_EQUAL_INT(EXPECTED_RESULT_HALOK, retVal);
    (void)main_module();
    //retVal must be 1
    TEST_ASSERT_EQUAL_INT(EXPECTED_RESULT_HALERROR, retVal);
}


void test_main_module_ClockConfig_HALERROR(void)
{
    /*This test case tests the functions HAL_RCC_OscConfig and HAL_RCC_ClockConfig returning a non-HAL_OK value*/
    HAL_Init_Ignore();
    HAL_RCC_OscConfig_IgnoreAndReturn(HAL_OK);
    HAL_RCC_ClockConfig_IgnoreAndReturn(HAL_ERROR);
    HAL_GPIO_WritePin_Expect(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
    HAL_GPIO_Init_Ignore();
    HAL_GPIO_TogglePin_Expect(GPIOA, GPIO_PIN_5);
    //Robustness test to ensure that retVal is set to zero before the main_module execution
    TEST_ASSERT_EQUAL_INT(EXPECTED_RESULT_HALOK, retVal);
    (void)main_module();
    //retVal must be 1
    TEST_ASSERT_EQUAL_INT(EXPECTED_RESULT_HALERROR, retVal);
}


#endif // TEST
