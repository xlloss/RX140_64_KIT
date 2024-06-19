/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_RTC_user.c
* Component Version: 1.8.0
* Device(s)        : R5F51403AxFM
* Description      : This file implements device driver for Config_RTC.
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_RTC.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
uint32_t read_rtc_flag = 1;
uint32_t enable_rtc_flashing = 0;
uint8_t led_7sec_flashing = 0;
rtc_calendarcounter_value_t *read_rtc;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_RTC_Create_UserInit
* Description  : This function add user code after initializing RTC module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_RTC_Create_UserInit(void)
{
    /* Start user code for code init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_RTC_alm_interrupt
* Description  : This function is ALM interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_RTC_ALM
#pragma interrupt r_Config_RTC_alm_interrupt(vect=VECT(RTC,ALM),fint)
#else
#pragma interrupt r_Config_RTC_alm_interrupt(vect=VECT(RTC,ALM))
#endif
static void r_Config_RTC_alm_interrupt(void)
{
    /* Start user code for r_Config_RTC_alm_interrupt. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_RTC_prd_interrupt
* Description  : This function is PRD interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_RTC_PRD
#pragma interrupt r_Config_RTC_prd_interrupt(vect=VECT(RTC,PRD),fint)
#else
#pragma interrupt r_Config_RTC_prd_interrupt(vect=VECT(RTC,PRD))
#endif
static void r_Config_RTC_prd_interrupt(void)
{
    /* Start user code for r_Config_RTC_prd_interrupt. Do not edit comment generated here */
    read_rtc_flag = 0;
    R_Config_RTC_Get_CalendarCounterValue(read_rtc);
    read_rtc_flag = 1;

    if (enable_rtc_flashing) {
        if (led_7sec_flashing)
            max7219_set_intensity(INTENSITY_0);
        else
            max7219_set_intensity(INTENSITY_15);

        led_7sec_flashing = led_7sec_flashing ^ 1;
    }

    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
void rtc_sec_notice_rigster(rtc_calendarcounter_value_t *rtc_data)
{
    read_rtc = rtc_data;
}

void rtc_enable_flashing()
{
    enable_rtc_flashing = 1;
}

void rtc_disable_flashing()
{
    enable_rtc_flashing = 0;
}
/* End user code. Do not edit comment generated here */
