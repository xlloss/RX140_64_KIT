/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
* this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* https://www.renesas.com/disclaimer
*
* Copyright (C) 2023 Renesas Electronics Corporation.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : qe_touch_define.h
* Description  : This file includes definitions.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History      : MM/DD/YYYY Version Description
*              : 04/24/2021 1.00    First Release
*              : 06/01/2021 1.01    Fixing a Little
*              : 07/15/2021 1.10    Adding Diagnosis Supporting
*              : 11/17/2021 1.20    Adding information for Initial Offset Tuning
*              : 03/01/2022 1.30    Adding Auto Correction and Multiple Electrode Connection Supporting
*              : 03/23/2023 1.40    Adding 3 Frequency Judgement Supporting
*              : 03/31/2023 1.41    Improving Traceability
***********************************************************************************************************************/
/***********************************************************************************************************************
* Touch I/F Configuration File  : RX140_64_KIT.tifcfg
* Tuning Log File               : RX140_64_KIT_log_tuning20240617182721.log
***********************************************************************************************************************/

#ifndef QE_TOUCH_DEFINE_H
#define QE_TOUCH_DEFINE_H


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define CTSU_CFG_NUM_SELF_ELEMENTS   (2)

#define CTSU_CFG_NUM_MUTUAL_ELEMENTS (0)

#define TOUCH_CFG_MONITOR_ENABLE (1)
#define TOUCH_CFG_NUM_BUTTONS    (2)
#define TOUCH_CFG_NUM_SLIDERS    (0)
#define TOUCH_CFG_NUM_WHEELS     (0)
#define TOUCH_CFG_PAD_ENABLE     (0)

#define QE_TOUCH_MACRO_CTSU_IP_KIND (2)

#define CTSU_CFG_VCC_MV           (3300)
#define CTSU_CFG_LOW_VOLTAGE_MODE (0)

#define CTSU_CFG_PCLK_DIVISION (0)

#define CTSU_CFG_TSCAP_PORT (0x0C04)

#define CTSU_CFG_NUM_SUMULTI   (3)
#define CTSU_CFG_SUMULTI0      (0x3F)
#define CTSU_CFG_SUMULTI1      (0x36)
#define CTSU_CFG_SUMULTI2      (0x48)

#define CTSU_CFG_CALIB_RTRIM_SUPPORT       (0)
#define CTSU_CFG_TEMP_CORRECTION_SUPPORT   (0)
#define CTSU_CFG_TEMP_CORRECTION_TS        (0)
#define CTSU_CFG_TEMP_CORRECTION_TIME      (0)



#define CTSU_CFG_TARGET_VALUE_QE_SUPPORT (1)




#define CTSU_CFG_TOUCH_3FREQ_JUDGE_TYPE  (0)
#define TOUCH_CFG_3FREQ_JUDGMENT_NUM     (2)

/***********************************************************************************************************************
Button State Mask for each configuration.
***********************************************************************************************************************/
#define CONFIG01_INDEX_B1     (0)
#define CONFIG01_MASK_B1      (1ULL << CONFIG01_INDEX_B1)
#define CONFIG01_INDEX_B3     (1)
#define CONFIG01_MASK_B3      (1ULL << CONFIG01_INDEX_B3)

#endif /* QE_TOUCH_DEFINE_H */
