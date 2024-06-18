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
* Copyright (C) 2024 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_ctsu_qe_pinset.c
* Version      : 1.0.2
* Device(s)    : R5F51403AxFM
* Tool-Chain   : RXC toolchain
* Description  : Setting of port and mpc registers
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_ctsu_qe_pinset.h"
#include "platform.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/***********************************************************************************************************************
* Function Name: R_CTSU_PinSetInit
* Description  : This function initializes pins for r_ctsu_qe module
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_CTSU_PinSetInit()
{
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);

    /* Set TSCAP pin */
    MPC.PC4PFS.BYTE = 0x19U;
    PORTC.PMR.BIT.B4 = 1U;

    /* Set TS15 pin */
    MPC.PC5PFS.BYTE = 0x19U;
    PORTC.PMR.BIT.B5 = 1U;

    /* Set TS28 pin */
    MPC.PA4PFS.BYTE = 0x19U;
    PORTA.PMR.BIT.B4 = 1U;

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}

/***********************************************************************************************************************
* Function Name: R_Set_CTSU_TSCAP_Discharge
* Description  : This function discharges TSCAP pin
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_Set_CTSU_TSCAP_Discharge()
{
    /* Set TSCAP pin */
    PORTC.PMR.BIT.B4 = 0U;
    PORTC.PODR.BIT.B4 = 0U;
    PORTC.PDR.BIT.B4 = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Set_CTSU_TSCAP_Charge
* Description  : This function charges TSCAP pin
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_Set_CTSU_TSCAP_Charge()
{
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);

    /* Set TSCAP pin */
    MPC.PC4PFS.BYTE = 0x19U;
    PORTC.PMR.BIT.B4 = 1U;

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}

