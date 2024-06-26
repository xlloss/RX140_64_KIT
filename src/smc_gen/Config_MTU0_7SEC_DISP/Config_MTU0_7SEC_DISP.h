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
* File Name        : Config_MTU0_7SEC_DISP.h
* Component Version: 1.12.0
* Device(s)        : R5F51403AxFM
* Description      : This file implements device driver for Config_MTU0_7SEC_DISP.
***********************************************************************************************************************/

#ifndef CFG_Config_MTU0_7SEC_DISP_H
#define CFG_Config_MTU0_7SEC_DISP_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_mtu2.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define MTU0_PCLK_COUNTER_DIVISION      (64)
#define _DBB9_TGRA0_VALUE               (0xDBB9U) /* TGRA0 value */
#define _DBB9_TGRB0_VALUE               (0xDBB9U) /* TGRB0 value */
#define _DBB9_TGRC0_VALUE               (0xDBB9U) /* TGRC0 value */
#define _DBB9_TGRD0_VALUE               (0xDBB9U) /* TGRD0 value */
#define _DBB9_TGRE0_VALUE               (0xDBB9U) /* TGRE0 value */
#define _0037_TGRF0_VALUE               (0x0037U) /* TGRF0 value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_MTU0_7SEC_DISP_Create(void);
void R_Config_MTU0_7SEC_DISP_Create_UserInit(void);
void R_Config_MTU0_7SEC_DISP_Start(void);
void R_Config_MTU0_7SEC_DISP_Stop(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
