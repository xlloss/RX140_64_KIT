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
* File Name        : r_cg_port.h
* Version          : 1.0.30
* Device(s)        : R5F51403AxFM
* Description      : General header file for PORT peripheral.
***********************************************************************************************************************/

#ifndef PORT_H
#define PORT_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Port Mode Register (PMR)
*/
/* Pmn Pin Mode Control (B7 - B0) */
#define _00_Pm0_PIN_GPIO        (0x00U) /* Pm0 as general I/O pin */
#define _00_Pm1_PIN_GPIO        (0x00U) /* Pm1 as general I/O pin */
#define _00_Pm2_PIN_GPIO        (0x00U) /* Pm2 as general I/O pin */
#define _00_Pm3_PIN_GPIO        (0x00U) /* Pm3 as general I/O pin */
#define _00_Pm4_PIN_GPIO        (0x00U) /* Pm4 as general I/O pin */
#define _00_Pm5_PIN_GPIO        (0x00U) /* Pm5 as general I/O pin */
#define _00_Pm6_PIN_GPIO        (0x00U) /* Pm6 as general I/O pin */
#define _00_Pm7_PIN_GPIO        (0x00U) /* Pm7 as general I/O pin */

/*
    Port Direction Register (PDR)
*/
/* Pmn Direction Control (B7 - B0) */
#define _00_Pm0_MODE_INPUT      (0x00U) /* Pm0 as input */
#define _01_Pm0_MODE_OUTPUT     (0x01U) /* Pm0 as output */
#define _00_Pm1_MODE_INPUT      (0x00U) /* Pm1 as input */
#define _02_Pm1_MODE_OUTPUT     (0x02U) /* Pm1 as output */
#define _00_Pm2_MODE_INPUT      (0x00U) /* Pm2 as input */
#define _04_Pm2_MODE_OUTPUT     (0x04U) /* Pm2 as output */
#define _00_Pm3_MODE_INPUT      (0x00U) /* Pm3 as input */
#define _08_Pm3_MODE_OUTPUT     (0x08U) /* Pm3 as output */
#define _00_Pm4_MODE_INPUT      (0x00U) /* Pm4 as input */
#define _10_Pm4_MODE_OUTPUT     (0x10U) /* Pm4 as output */
#define _00_Pm5_MODE_INPUT      (0x00U) /* Pm5 as input */
#define _20_Pm5_MODE_OUTPUT     (0x20U) /* Pm5 as output */
#define _00_Pm6_MODE_INPUT      (0x00U) /* Pm6 as input */
#define _40_Pm6_MODE_OUTPUT     (0x40U) /* Pm6 as output */
#define _00_Pm7_MODE_INPUT      (0x00U) /* Pm7 as input */
#define _80_Pm7_MODE_OUTPUT     (0x80U) /* Pm7 as output */
#define _D7_PDR0_DEFAULT        (0xD7U) /* PDR0 default value */
#define _0F_PDR1_DEFAULT        (0x0FU) /* PDR1 default value */
#define _3F_PDR2_DEFAULT        (0x3FU) /* PDR2 default value */
#define _18_PDR3_DEFAULT        (0x18U) /* PDR3 default value */
#define _CF_PDR5_DEFAULT        (0xCFU) /* PDR5 default value */
#define _A4_PDRA_DEFAULT        (0xA4U) /* PDRA default value */
#define _14_PDRB_DEFAULT        (0x14U) /* PDRB default value */
#define _03_PDRC_DEFAULT        (0x03U) /* PDRC default value */
#define _FF_PDRD_DEFAULT        (0xFFU) /* PDRD default value */
#define _C0_PDRE_DEFAULT        (0xC0U) /* PDRE default value */
#define _7F_PDRG_DEFAULT        (0x7FU) /* PDRG default value */
#define _F0_PDRH_DEFAULT        (0xF0U) /* PDRH default value */
#define _3F_PDRJ_DEFAULT        (0x3FU) /* PDRJ default value */

/*
    Port Output Data Register (PODR)
*/
/* Pmn Output Data Store (B7 - B0) */
#define _00_Pm0_OUTPUT_0        (0x00U) /* output low at B0 */
#define _01_Pm0_OUTPUT_1        (0x01U) /* output high at B0 */
#define _00_Pm1_OUTPUT_0        (0x00U) /* output low at B1 */
#define _02_Pm1_OUTPUT_1        (0x02U) /* output high at B1 */
#define _00_Pm2_OUTPUT_0        (0x00U) /* output low at B2 */
#define _04_Pm2_OUTPUT_1        (0x04U) /* output high at B2 */
#define _00_Pm3_OUTPUT_0        (0x00U) /* output low at B3 */
#define _08_Pm3_OUTPUT_1        (0x08U) /* output high at B3 */
#define _00_Pm4_OUTPUT_0        (0x00U) /* output low at B4 */
#define _10_Pm4_OUTPUT_1        (0x10U) /* output high at B4 */
#define _00_Pm5_OUTPUT_0        (0x00U) /* output low at B5 */
#define _20_Pm5_OUTPUT_1        (0x20U) /* output high at B5 */
#define _00_Pm6_OUTPUT_0        (0x00U) /* output low at B6 */
#define _40_Pm6_OUTPUT_1        (0x40U) /* output high at B6 */
#define _00_Pm7_OUTPUT_0        (0x00U) /* output low at B7 */
#define _80_Pm7_OUTPUT_1        (0x80U) /* output high at B7 */

/*
    Open Drain Control Register 0 (ODR0)
*/
/* Pmn Output Type Select (Pm0 to Pm3) */
#define _00_Pm0_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _01_Pm0_NCH_OPEN_DRAIN  (0x01U) /* N-channel open-drain output */
#define _00_Pm1_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _04_Pm1_NCH_OPEN_DRAIN  (0x04U) /* N-channel open-drain output */
#define _08_Pm1_PCH_OPEN_DRAIN  (0x08U) /* P-channel open-drain output, for PE1 only */
#define _0C_Pm1_HIZ             (0x0CU) /* Hi-Z, for PE1 only */
#define _00_Pm2_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _10_Pm2_NCH_OPEN_DRAIN  (0x10U) /* N-channel open-drain output */
#define _00_Pm3_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _40_Pm3_NCH_OPEN_DRAIN  (0x40U) /* N-channel open-drain output */

/*
    Open Drain Control Register 1 (ODR1)
*/
/* Pmn Output Type Select (Pm4 to Pm7) */
#define _00_Pm4_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _01_Pm4_NCH_OPEN_DRAIN  (0x01U) /* N-channel open-drain output */
#define _00_Pm5_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _04_Pm5_NCH_OPEN_DRAIN  (0x04U) /* N-channel open-drain output */
#define _00_Pm6_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _10_Pm6_NCH_OPEN_DRAIN  (0x10U) /* N-channel open-drain output */
#define _00_Pm7_CMOS_OUTPUT     (0x00U) /* CMOS output */
#define _40_Pm7_NCH_OPEN_DRAIN  (0x40U) /* N-channel open-drain output */

/*
    Pull-Up Control Register (PCR)
*/
/* Pmn Input Pull-Up Resistor Control (B7 - B0) */
#define _00_Pm0_PULLUP_OFF      (0x00U) /* Pm0 pull-up resistor not connected */
#define _01_Pm0_PULLUP_ON       (0x01U) /* Pm0 pull-up resistor connected */
#define _00_Pm1_PULLUP_OFF      (0x00U) /* Pm1 pull-up resistor not connected */
#define _02_Pm1_PULLUP_ON       (0x02U) /* Pm1 pull-up resistor connected */
#define _00_Pm2_PULLUP_OFF      (0x00U) /* Pm2 Pull-up resistor not connected */
#define _04_Pm2_PULLUP_ON       (0x04U) /* Pm2 pull-up resistor connected */
#define _00_Pm3_PULLUP_OFF      (0x00U) /* Pm3 pull-up resistor not connected */
#define _08_Pm3_PULLUP_ON       (0x08U) /* Pm3 pull-up resistor connected */
#define _00_Pm4_PULLUP_OFF      (0x00U) /* Pm4 pull-up resistor not connected */
#define _10_Pm4_PULLUP_ON       (0x10U) /* Pm4 pull-up resistor connected */
#define _00_Pm5_PULLUP_OFF      (0x00U) /* Pm5 pull-up resistor not connected */
#define _20_Pm5_PULLUP_ON       (0x20U) /* Pm5 pull-up resistor connected */
#define _00_Pm6_PULLUP_OFF      (0x00U) /* Pm6 pull-up resistor not connected */
#define _40_Pm6_PULLUP_ON       (0x40U) /* Pm6 pull-up resistor connected */
#define _00_Pm7_PULLUP_OFF      (0x00U) /* Pm7 pull-up resistor not connected */
#define _80_Pm7_PULLUP_ON       (0x80U) /* Pm7 pull-up resistor connected */

/*
    Port Switching Register A (PSRA)
*/
/* PB6/PC0 Switching (PSEL6) */
#define _00_PORT_PSEL6_PB6      (0x00U) /* PB6 general I/O port function is selected */
#define _40_PORT_PSEL6_PC0      (0x40U) /* PC0 general I/O port function is selected */
/* PB7/PC1 Switching (PSEL7) */
#define _00_PORT_PSEL7_PB7      (0x00U) /* PB7 general I/O port function is selected */
#define _80_PORT_PSEL7_PC1      (0x80U) /* PC1 general I/O port function is selected */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
