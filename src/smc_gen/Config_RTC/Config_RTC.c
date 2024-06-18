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
* File Name        : Config_RTC.c
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
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_RTC_Create
* Description  : This function initializes the RTC module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_RTC_Create(void)
{
    uint16_t w_count;
    uint32_t rw_count;
    volatile uint32_t dummy;

    /* Disable ALM, PRD and CUP interrupts */
    IEN(RTC, ALM) = 0U;
    IEN(RTC, PRD) = 0U;
    IEN(RTC, CUP) = 0U;

    if (RTC.RCR1.BIT.AIE == 1U)
    {
        /* Disable RTC ALARM interrupt */
        RTC.RCR1.BIT.AIE = 0U;
        while (RTC.RCR1.BIT.AIE != 0U)
        {
            /* Wait for the register modification to complete */
        }

        /* Clear IR flag of ICU ALARM interrupt */
        IR(RTC, ALM) = 0U;
    }

    /* RTC cold start */
    if(0 == SYSTEM.RSTSR1.BIT.CWSF)
    {
        /* Wait for 6 sub-clock cycles */
        for (w_count = 0U; w_count < _06DF_RTC_SUB_6_CYCLE_WAIT; w_count++)
        {
            nop();
        }

        /* Stop all counters */
        RTC.RCR2.BYTE = 0x00U;
        while (RTC.RCR2.BIT.START != 0U)
        {
            /* Wait for the register modification to complete */
        }

        /* Select count mode */
        RTC.RCR2.BIT.CNTMD = 0U;
        while (RTC.RCR2.BIT.CNTMD != 0U)
        {
            /* Wait for the register modification to complete */
        }

        /* Execute RTC software reset */
        RTC.RCR2.BIT.RESET = 1U;
        while (RTC.RCR2.BIT.RESET != 0U)
        {
            /* Wait for the register modification to complete */
        }

        /* Stop RTC counter */
        RTC.RCR2.BIT.START = 0U;
        while (RTC.RCR2.BIT.START != 0U)
        {
            /* Wait for the register modification to complete */
        }

        /* Clear ALM,PRD,CUP IR */
        IR(RTC, ALM) = 0U;
        IR(RTC, PRD) = 0U;
        IR(RTC, CUP) = 0U;

        /* Set counter time */
        RTC.RSECCNT.BYTE = _00_RTC_COUNT_SECOND_VALUE;
        RTC.RMINCNT.BYTE = _00_RTC_COUNT_MINUTE_VALUE;
        RTC.RHRCNT.BYTE = _00_RTC_COUNT_HOUR_VALUE | _00_RTC_HOUR_ATTRIB_AM ;
        RTC.RWKCNT.BYTE = _06_RTC_COUNT_WEEK_VALUE;
        RTC.RDAYCNT.BYTE = _01_RTC_COUNT_DAY_VALUE;
        RTC.RMONCNT.BYTE = _01_RTC_COUNT_MONTH_VALUE;
        RTC.RYRCNT.WORD = _0000_RTC_COUNT_YEAR_VALUE;

        /* Perform 4 read operations after writing */
        for (rw_count = 0U; rw_count < _04_FOUR_READ_COUNT; rw_count++)
        {
            dummy = RTC.RSECCNT.BYTE;
            dummy = RTC.RMINCNT.BYTE;
            dummy = RTC.RHRCNT.BYTE;
            dummy = RTC.RWKCNT.BYTE;
            dummy = RTC.RDAYCNT.BYTE;
            dummy = RTC.RMONCNT.BYTE;
            dummy = RTC.RYRCNT.WORD;
        }

        /* Set control register */
        RTC.RCR2.BYTE |= (_00_RTC_AUTO_ADJUSTMENT_DISABLE | _00_RTC_HOUR_MODE_12);

        /* Perform 4 read operations after writing */
        for (rw_count = 0U; rw_count < _04_FOUR_READ_COUNT; rw_count++)
        {
            dummy = RTC.RCR2.BYTE;
        }

        /* Set alarm time */
        RTC.RSECAR.BYTE = _00_RTC_ALARM_SECOND_VALUE | _80_RTC_ALARM_SECOND_ENABLE;
        RTC.RMINAR.BYTE = _00_RTC_ALARM_MINUTE_DISABLE;
        RTC.RHRAR.BYTE = _00_RTC_ALARM_HOUR_DISABLE;
        RTC.RWKAR.BYTE = _00_RTC_ALARM_WEEK_DISABLE;
        RTC.RDAYAR.BYTE = _00_RTC_ALARM_DAY_DISABLE;
        RTC.RMONAR.BYTE = _00_RTC_ALARM_MONTH_DISABLE;
        RTC.RYRAREN.BIT.ENB = 0U;

        /* Perform 4 read operations after writing */
        for (rw_count = 0U; rw_count < _04_FOUR_READ_COUNT; rw_count++)
        {
            dummy = RTC.RSECAR.BYTE;
            dummy = RTC.RMINAR.BYTE;
            dummy = RTC.RHRAR.BYTE;
            dummy = RTC.RWKAR.BYTE;
            dummy = RTC.RDAYAR.BYTE;
            dummy = RTC.RMONAR.BYTE;
        }

        /* Wait for completion of alarm setting time (until two periodic interrupts are generated) */
        for (rw_count = 0U; rw_count <= _000124F9_RTC_2_PERIODIC_INTERRUPTS_CYCLE; rw_count++)
        {
            nop();
        }

        /* Set control registers */
        dummy = _01_RTC_ALARM_INT_ENABLE | _00_RTC_PERIOD_INT_DISABLE | _00_RTC_PERIODIC_INT_PERIOD_DISABLE;
        RTC.RCR1.BYTE = dummy;
        while (dummy != RTC.RCR1.BYTE)
        {
            /* Wait for this write to complete. */
        }
    }

    /* Set control registers */
    dummy = RTC.RCR1.BYTE | _00_RTC_CARRY_INT_DISABLE;
    RTC.RCR1.BYTE = dummy;
    while (dummy != RTC.RCR1.BYTE)
    {
        /* Wait for this write to complete. */
    }

    /* Wait for completion of alarm setting time (until two periodic interrupts are generated) */
    for (rw_count = 0U; rw_count <= _000124F9_RTC_2_PERIODIC_INTERRUPTS_CYCLE; rw_count++)
    {
        nop();
    }

    /* Set ALM priority level */
    IPR(RTC, ALM) = _0F_RTC_PRIORITY_LEVEL15;

    R_Config_RTC_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_RTC_Start
* Description  : This function starts RTC counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_RTC_Start(void)
{
    /* Enable ALM interrupt */
    IEN(RTC, ALM) = 1U;

    /* Set the START bit to 1 */
    RTC.RCR2.BIT.START = 1U;
    while (RTC.RCR2.BIT.START != 1U)
    {
        /* Wait for the register modification to complete */
    }
}

/***********************************************************************************************************************
* Function Name: R_Config_RTC_Stop
* Description  : This function stops RTC counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_RTC_Stop(void)
{
    /* Disable ALM interrupt */
    IEN(RTC, ALM) = 0U;

    if (RTC.RCR1.BIT.AIE == 1U)
    {
        /* Disable RTC ALARM interrupt */
        RTC.RCR1.BIT.AIE = 0U;
        while (RTC.RCR1.BIT.AIE != 0U)
        {
            /* Wait for the register modification to complete */
        }

        /* Clear IR flag of ICU ALARM interrupt */
        IR(RTC, ALM) = 0U;
    }

    /* Stop all counters */
    RTC.RCR2.BIT.START = 0U;
    while (RTC.RCR2.BIT.START != 0U)
    {
        /* Wait for the register modification to complete */
    }
}

/***********************************************************************************************************************
* Function Name: R_Config_RTC_Restart
* Description  : This function restarts RTC counter
* Arguments    : counter_write_val -
*                    counter write value
* Return Value : None
***********************************************************************************************************************/

void R_Config_RTC_Restart(rtc_calendarcounter_value_t counter_write_val)
{
    uint32_t rw_count;
    volatile uint32_t dummy;

    /* Disable ALM, PRD and CUP interrupts */
    IEN(RTC, ALM) = 0U;
    IEN(RTC, PRD) = 0U;

    if (RTC.RCR1.BIT.AIE == 1U)
    {
        /* Disable RTC ALARM interrupt */
        RTC.RCR1.BIT.AIE = 0U;
        while (RTC.RCR1.BIT.AIE != 0U)
        {
            /* Wait for the register modification to complete */
        }

        /* Clear IR flag of ICU ALARM interrupt */
        IR(RTC, ALM) = 0U;
    }

    /* Stop all counters */
    RTC.RCR2.BIT.START = 0U;
    while (RTC.RCR2.BIT.START != 0U)
    {
        /* Wait for the register modification to complete */
    }

    /* Execute RTC software reset */
    RTC.RCR2.BIT.RESET = 1U;
    while (RTC.RCR2.BIT.RESET != 0U)
    {
        /* Wait for the register modification to complete */
    }

    /* Set control registers */
    RTC.RCR2.BYTE |= (_00_RTC_RTCOUT_OUTPUT_DISABLE | _00_RTC_AUTO_ADJUSTMENT_DISABLE | _00_RTC_HOUR_MODE_12);

    /* Perform 4 read operations after writing */
    for (rw_count = 0U; rw_count < _04_FOUR_READ_COUNT; rw_count++)
    {
        dummy = RTC.RCR2.BYTE;
    }

    /* Set counter values */
    RTC.RSECCNT.BYTE = counter_write_val.rseccnt;
    RTC.RMINCNT.BYTE = counter_write_val.rmincnt;
    RTC.RHRCNT.BYTE = counter_write_val.rhrcnt;
    RTC.RWKCNT.BYTE = counter_write_val.rwkcnt;
    RTC.RDAYCNT.BYTE = counter_write_val.rdaycnt;
    RTC.RMONCNT.BYTE = counter_write_val.rmoncnt;
    RTC.RYRCNT.WORD = counter_write_val.ryrcnt;

    /* Perform 4 read operations after writing */
    for (rw_count = 0U; rw_count < _04_FOUR_READ_COUNT; rw_count++)
    {
        dummy = RTC.RSECCNT.BYTE;
        dummy = RTC.RMINCNT.BYTE;
        dummy = RTC.RHRCNT.BYTE;
        dummy = RTC.RWKCNT.BYTE;
        dummy = RTC.RDAYCNT.BYTE;
        dummy = RTC.RMONCNT.BYTE;
        dummy = RTC.RYRCNT.WORD;
    }

    /* Enable ALM interrupt */
    IEN(RTC, ALM) = 1U;

    /* Set the START bit to 1 */
    RTC.RCR2.BIT.START = 1U;
    while (RTC.RCR2.BIT.START != 1U)
    {
        /* Wait for the register modification to complete */
    }
}

/***********************************************************************************************************************
* Function Name: R_Config_RTC_Get_CalendarCounterValue
* Description  : This function get RTC calendar counter value
* Arguments    : counter_read_val -
*                    counter read pointer
* Return Value : None
***********************************************************************************************************************/

void R_Config_RTC_Get_CalendarCounterValue(rtc_calendarcounter_value_t * const counter_read_val)
{
    /* Enable RTC CUP interrupt */
    RTC.RCR1.BYTE |= _02_RTC_CARRY_INT_ENABLE;

    do
    {
        /* Clear IR flag of CUP interrupt */
        IR(RTC, CUP) = 0U;

        /* Read counter registers */
        counter_read_val->rseccnt = RTC.RSECCNT.BYTE;
        counter_read_val->rmincnt = RTC.RMINCNT.BYTE;
        /* PM bit value is also returned with 'rhrcnt', please mask it out if it is not needed */
        counter_read_val->rhrcnt = RTC.RHRCNT.BYTE;
        counter_read_val->rwkcnt = RTC.RWKCNT.BYTE;
        counter_read_val->rdaycnt = RTC.RDAYCNT.BYTE;
        counter_read_val->rmoncnt = RTC.RMONCNT.BYTE;
        counter_read_val->ryrcnt = RTC.RYRCNT.WORD;
    } while (IR(RTC, CUP) == 1U);

    /* Disable RTC CUP interrupt */
    RTC.RCR1.BYTE &= (~_02_RTC_CARRY_INT_ENABLE);
}

/***********************************************************************************************************************
* Function Name: R_Config_RTC_Set_CalendarCounterValue
* Description  : This function get RTC calendar counter value
* Arguments    : counter_write_val -
*                    counter write value
* Return Value : None
***********************************************************************************************************************/

void R_Config_RTC_Set_CalendarCounterValue(rtc_calendarcounter_value_t counter_write_val)
{
    uint32_t rw_count;
    volatile uint32_t dummy;

    /* Stop all counters */
    RTC.RCR2.BIT.START = 0U;
    while (RTC.RCR2.BIT.START != 0U)
    {
        /* Wait for the register modification to complete */
    }

    /* Execute RTC software reset */
    RTC.RCR2.BIT.RESET = 1U;
    while (RTC.RCR2.BIT.RESET != 0U)
    {
        /* Wait for the register modification to complete */
    }

    /* Set counter values */
    RTC.RSECCNT.BYTE = counter_write_val.rseccnt;
    RTC.RMINCNT.BYTE = counter_write_val.rmincnt;
    RTC.RHRCNT.BYTE = counter_write_val.rhrcnt;
    RTC.RWKCNT.BYTE = counter_write_val.rwkcnt;
    RTC.RDAYCNT.BYTE = counter_write_val.rdaycnt;
    RTC.RMONCNT.BYTE = counter_write_val.rmoncnt;
    RTC.RYRCNT.WORD = counter_write_val.ryrcnt;

    /* Perform 4 read operations after writing */
    for (rw_count = 0U; rw_count < _04_FOUR_READ_COUNT; rw_count++)
    {
        dummy = RTC.RSECCNT.BYTE;
        dummy = RTC.RMINCNT.BYTE;
        dummy = RTC.RHRCNT.BYTE;
        dummy = RTC.RWKCNT.BYTE;
        dummy = RTC.RDAYCNT.BYTE;
        dummy = RTC.RMONCNT.BYTE;
        dummy = RTC.RYRCNT.WORD;
    }

    /* Set control registers */
    RTC.RCR2.BYTE |= (_00_RTC_RTCOUT_OUTPUT_DISABLE | _00_RTC_AUTO_ADJUSTMENT_DISABLE | _00_RTC_HOUR_MODE_12);

    /* Perform 4 read operations after writing */
    for (rw_count = 0U; rw_count < _04_FOUR_READ_COUNT; rw_count++)
    {
        dummy = RTC.RCR2.BYTE;
    }
}

/***********************************************************************************************************************
* Function Name: R_Config_RTC_Set_CalendarAlarm
* Description  : This function set RTC calendar alarm enable
* Arguments    : alarm_enable -
*                    set RTC calendar alarm enable bits
*                alarm_val -
*                    structure containing new alarm value
* Return Value : None
***********************************************************************************************************************/

void R_Config_RTC_Set_CalendarAlarm(rtc_calendar_alarm_enable_t alarm_enable, rtc_calendar_alarm_value_t alarm_val)
{
    uint32_t w_count;
    volatile uint32_t dummy;

    /* Start RTC counter */
    RTC.RCR2.BIT.START = 1U;
    while (RTC.RCR2.BIT.START != 1U)
    {
        /* Wait for the register modification to complete */
    }

    /* Disable ICU ALARM interrupt */
    IEN(RTC, ALM) = 0U;

    if (RTC.RCR1.BIT.AIE == 1U)
    {
        /* Disable RTC ALARM interrupt */
        RTC.RCR1.BIT.AIE = 0U;
        while (RTC.RCR1.BIT.AIE != 0U)
        {
            /* Wait for the register modification to complete */
        }

        /* Clear IR flag of ICU ALARM interrupt */
        IR(RTC, ALM) = 0U;
    }

    /* Set calendar alarm value */
    RTC.RSECAR.BYTE = (uint8_t)((alarm_enable.sec_enb & 0x80U) | (alarm_val.rsecar & 0x7FU));
    RTC.RMINAR.BYTE = (uint8_t)((alarm_enable.min_enb & 0x80U) | (alarm_val.rminar & 0x7FU));
    RTC.RHRAR.BYTE = (uint8_t)((alarm_enable.hr_enb & 0x80U) | (alarm_val.rhrar & 0x7FU));
    RTC.RDAYAR.BYTE = (uint8_t)((alarm_enable.day_enb & 0x80U) | (alarm_val.rdayar & 0x3FU));
    RTC.RWKAR.BYTE = (uint8_t)((alarm_enable.wk_enb & 0x80U) | (alarm_val.rwkar & 0x07U));
    RTC.RMONAR.BYTE = (uint8_t)((alarm_enable.mon_enb & 0x80U) | (alarm_val.rmonar & 0x1F));
    RTC.RYRAR.WORD = (uint16_t)(alarm_val.ryrar & 0x00FFU);
    RTC.RYRAREN.BYTE = (uint8_t)(alarm_enable.yr_enb & 0x80U);

    /* Perform 4 read operations after writing */
    for (w_count = 0U; w_count < _04_FOUR_READ_COUNT; w_count++)
    {
        dummy = RTC.RSECAR.BYTE;
        dummy = RTC.RMINAR.BYTE;
        dummy = RTC.RHRAR.BYTE;
        dummy = RTC.RWKAR.BYTE;
        dummy = RTC.RDAYAR.BYTE;
        dummy = RTC.RMONAR.BYTE;
        dummy = RTC.RYRAR.WORD;
    }

    /* Enable RTC ALARM interrupt */
    RTC.RCR1.BIT.AIE = 1U;
    while (RTC.RCR1.BIT.AIE != 1U)
    {
        /* Wait for the register modification to complete */
    }

    /* Wait for completion of alarm setting time (until two periodic interrupts are generated) */
    for (w_count = 0U; w_count <= _000124F9_RTC_2_PERIODIC_INTERRUPTS_CYCLE; w_count++)
    {
        nop();
    }

    /* Clear IR flag of ICU ALARM interrupt */
    IR(RTC, ALM) = 0U;

    /* Enable ICU ALARM interrupt */
    IEN(RTC, ALM) = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_RTC_Enable_Alarm_Interrupt
* Description  : This function enable the alarm interrupt request
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_RTC_Enable_Alarm_Interrupt(void)
{
    /* Enable RTC ALARM interrupt */
    RTC.RCR1.BIT.AIE = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_RTC_Disable_Alarm_Interrupt
* Description  : This function disable the alarm interrupt request
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_RTC_Disable_Alarm_Interrupt(void)
{
    if (RTC.RCR1.BIT.AIE == 1U)
    {
        /* Disable ICU ALARM interrupt */
        IEN(RTC,ALM) = 0U;

        /* Disable RTC ALARM interrupt */
        RTC.RCR1.BIT.AIE = 0U;

        while (RTC.RCR1.BIT.AIE != 0U)
        {
            /* Wait for the register modification to complete */
        }

        /* Clear IR flag of ICU ALARM interrupt */
        IR(RTC, ALM) = 0U;
    }
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
