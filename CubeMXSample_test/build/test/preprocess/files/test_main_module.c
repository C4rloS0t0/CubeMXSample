#include "build/test/mocks/mock_stm32f4xx_hal.h"
#include "src/main_module.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
















int retVal;



void setUp(void)

{



    retVal = 0;

}



void tearDown(void)

{

}



void test_main_module_OscConfigandClockConfig_HALOK(void)

{



    HAL_Init_CMockIgnore();

    HAL_RCC_OscConfig_CMockIgnoreAndReturn(28, HAL_OK);

    HAL_RCC_ClockConfig_CMockIgnoreAndReturn(29, HAL_OK);

    HAL_GPIO_WritePin_CMockExpect(30, ((GPIO_TypeDef *)0xFF942300), 0x0020, GPIO_PIN_SET);

    HAL_GPIO_Init_CMockIgnore();

    HAL_GPIO_TogglePin_CMockExpect(32, ((GPIO_TypeDef *)0xFF942300), 0x0020);

    (void)main_module();



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((retVal)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

}





void test_main_module_OscConfig_HALERROR(void)

{



    HAL_Init_CMockIgnore();

    HAL_RCC_OscConfig_CMockIgnoreAndReturn(43, HAL_ERROR);

    HAL_RCC_ClockConfig_CMockIgnoreAndReturn(44, HAL_OK);

    HAL_GPIO_WritePin_CMockExpect(45, ((GPIO_TypeDef *)0xFF942300), 0x0020, GPIO_PIN_SET);

    HAL_GPIO_Init_CMockIgnore();

    HAL_GPIO_TogglePin_CMockExpect(47, ((GPIO_TypeDef *)0xFF942300), 0x0020);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((retVal)), (

   ((void *)0)

   ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_INT);

    (void)main_module();



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((retVal)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);

}





void test_main_module_ClockConfig_HALERROR(void)

{



    HAL_Init_CMockIgnore();

    HAL_RCC_OscConfig_CMockIgnoreAndReturn(60, HAL_OK);

    HAL_RCC_ClockConfig_CMockIgnoreAndReturn(61, HAL_ERROR);

    HAL_GPIO_WritePin_CMockExpect(62, ((GPIO_TypeDef *)0xFF942300), 0x0020, GPIO_PIN_SET);

    HAL_GPIO_Init_CMockIgnore();

    HAL_GPIO_TogglePin_CMockExpect(64, ((GPIO_TypeDef *)0xFF942300), 0x0020);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((retVal)), (

   ((void *)0)

   ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_INT);

    (void)main_module();



    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((retVal)), (

   ((void *)0)

   ), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_INT);

}
