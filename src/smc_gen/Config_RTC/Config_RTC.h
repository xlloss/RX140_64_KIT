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
* File Name        : Config_RTC.h
* Component Version: 1.8.0
* Device(s)        : R5F51403AxFM
* Description      : This file implements device driver for Config_RTC.
***********************************************************************************************************************/

#ifndef CFG_Config_RTC_H
#define CFG_Config_RTC_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_rtc.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _04_FOUR_READ_COUNT                         (0x04U)/* Perform 4 read operations */
#define _06DF_RTC_SUB_6_CYCLE_WAIT                  (0x06DFU)
#define _000124F9_RTC_2_PERIODIC_INTERRUPTS_CYCLE   (0x000124F9UL)
#define _00_RTC_COUNT_SECOND_VALUE                  (0x00U)
#define _00_RTC_COUNT_MINUTE_VALUE                  (0x00U)
#define _00_RTC_COUNT_HOUR_VALUE                    (0x00U)
#define _06_RTC_COUNT_WEEK_VALUE                    (0x06U)
#define _01_RTC_COUNT_DAY_VALUE                     (0x01U)
#define _01_RTC_COUNT_MONTH_VALUE                   (0x01U)
#define _0000_RTC_COUNT_YEAR_VALUE                  (0x0000U)
#define _00_RTC_ALARM_SECOND_VALUE                  (0x00U)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_RTC_Create(void);
void R_Config_RTC_Create_UserInit(void);
void R_Config_RTC_Start(void);
void R_Config_RTC_Stop(void);
void R_Config_RTC_Restart(rtc_calendarcounter_value_t counter_write_val);
void R_Config_RTC_Get_CalendarCounterValue(rtc_calendarcounter_value_t * const counter_read_val);
void R_Config_RTC_Set_CalendarCounterValue(rtc_calendarcounter_value_t counter_write_val);
void R_Config_RTC_Set_CalendarAlarm(rtc_calendar_alarm_enable_t alarm_enable, rtc_calendar_alarm_value_t alarm_val);
void R_Config_RTC_Enable_Alarm_Interrupt(void);
void R_Config_RTC_Disable_Alarm_Interrupt(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
