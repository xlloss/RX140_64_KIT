/***********************************************************************
*
* FILE : qe_sample_main.c
* DATE : 2022-03-09
* DESCRIPTION : Main Program for RX
*
* NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "qe_touch_config.h"
#if ((TOUCH_CFG_UART_MONITOR_SUPPORT == 1) || (TOUCH_CFG_UART_TUNING_SUPPORT == 1))
#include "r_sci_rx_pinset.h"
#endif
#include "r_cg_userdefine.h"
#include "Config_RTC.h"
#include "max7219.h"
#define TOUCH_SCAN_INTERVAL_EXAMPLE (20)    /* milliseconds */

void R_CTSU_PinSetInit(void);
void qe_touch_main(void);



#if ((TOUCH_CFG_UART_MONITOR_SUPPORT == 1) || (TOUCH_CFG_UART_TUNING_SUPPORT == 1))
#if (TOUCH_CFG_UART_NUMBER == 0)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI0
#elif (TOUCH_CFG_UART_NUMBER == 1)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI1
#elif (TOUCH_CFG_UART_NUMBER == 2)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI2
#elif (TOUCH_CFG_UART_NUMBER == 3)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI3
#elif (TOUCH_CFG_UART_NUMBER == 4)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI4
#elif (TOUCH_CFG_UART_NUMBER == 5)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI5
#elif (TOUCH_CFG_UART_NUMBER == 6)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI6
#elif (TOUCH_CFG_UART_NUMBER == 7)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI7
#elif (TOUCH_CFG_UART_NUMBER == 8)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI8
#elif (TOUCH_CFG_UART_NUMBER == 9)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI9
#elif (TOUCH_CFG_UART_NUMBER == 10)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI10
#elif (TOUCH_CFG_UART_NUMBER == 11)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI11
#elif (TOUCH_CFG_UART_NUMBER == 12)
#define QE_SCI_PIN_SET R_SCI_PinSet_SCI12
#endif
#endif

uint64_t button_status;
#if (TOUCH_CFG_NUM_SLIDERS != 0)
uint16_t slider_position[TOUCH_CFG_NUM_SLIDERS];
#endif
#if (TOUCH_CFG_NUM_WHEELS != 0)
uint16_t wheel_position[TOUCH_CFG_NUM_WHEELS];
#endif





void delay_us(unsigned int val)
{
	R_BSP_SoftwareDelay(val, BSP_DELAY_MICROSECS);
}

uint32_t loop_num_key1 = 0;
uint32_t loop_num_key2 = 0;
uint8_t fun_key1[10] = {0}, fun_key2[10] = {0};
uint8_t index = 0, fun_key1_push_up_check = 0, fun_key2_push_up_check = 0;
rtc_calendarcounter_value_t rtc_read_val;

void qe_touch_main(void)
{
    fsp_err_t err;
    rtc_calendarcounter_value_t rtv_write_val = {
        .rseccnt =  0,
        .rmincnt =  24,
        .rhrcnt  =  14,
        .rdaycnt =  18,
        .rwkcnt  =  0,
        .rmoncnt =  6,
        .ryrcnt  =  23,

    };

    /* Initialize pins (function created by Smart Configurator) */
    R_CTSU_PinSetInit();

#if ((TOUCH_CFG_UART_MONITOR_SUPPORT == 1) || (TOUCH_CFG_UART_TUNING_SUPPORT == 1))
    /* Setup pins for SCI (function created by Smart Configurator) */
    QE_SCI_PIN_SET();
#endif



    R_Config_RTC_Set_CalendarCounterValue(rtv_write_val);
    rtc_sec_notice_rigster(&rtc_read_val);
    R_Config_RTC_Start();

    /* Open Touch middleware */
    err = RM_TOUCH_Open (g_qe_touch_instance_config01.p_ctrl, g_qe_touch_instance_config01.p_cfg);
    if (FSP_SUCCESS != err)
    {
        while (true) {}
    }

    max7219_init(serial_write,
                 delay_us,
                 CTL_DOUT,
                 CTL_CLK,
                 CTL_LOAD,
                 0xFF,
                 INTENSITY_15,
                 SCAN_LIMIT_8);

    rtc_display(rtc_read_val.rhrcnt, rtc_read_val.rmincnt, rtc_read_val.rseccnt);

    /* Main loop */
    while (true) {

        /* for [CONFIG01] configuration */
        err = RM_TOUCH_ScanStart (g_qe_touch_instance_config01.p_ctrl);
        if (FSP_SUCCESS != err) {
            while (true) {}
        }
        while (0 == g_qe_touch_flag) {}
        g_qe_touch_flag = 0;

        err = RM_TOUCH_DataGet (g_qe_touch_instance_config01.p_ctrl, &button_status, NULL, NULL);
        if (FSP_SUCCESS == err) {
            /* TODO: Add your own code here. */
        }

        if (button_status & CONFIG01_MASK_B1) {
            led(LED1, LED_ON);
        } else if (button_status & CONFIG01_MASK_B3) {
            led(LED2, LED_ON);
        } else {
            led(LED1, LED_OFF);
            led(LED2, LED_OFF);
        }

        fun_key1[9] = fun_key1[8];
        fun_key1[8] = fun_key1[7];
        fun_key1[7] = fun_key1[6];
        fun_key1[6] = fun_key1[5];
        fun_key1[5] = fun_key1[4];
        fun_key1[4] = fun_key1[3];
        fun_key1[3] = fun_key1[2];
        fun_key1[2] = fun_key1[1];
        fun_key1[1] = fun_key1[0];
        fun_key1[0] = (button_status & CONFIG01_MASK_B1) >> CONFIG01_INDEX_B1;

        fun_key2[9] = fun_key2[8];
        fun_key2[8] = fun_key2[7];
        fun_key2[7] = fun_key2[6];
        fun_key2[6] = fun_key2[5];
        fun_key2[5] = fun_key2[4];
        fun_key2[4] = fun_key2[3];
        fun_key2[3] = fun_key2[2];
        fun_key2[2] = fun_key2[1];
        fun_key2[1] = fun_key2[0];
        fun_key2[0] = (button_status & CONFIG01_MASK_B3) >> CONFIG01_INDEX_B3;

        for (index = 1; index < 5; index++) {
            if (fun_key1[index] == 1)
                fun_key1_push_up_check++;
            else {
                index = 5;
                fun_key1_push_up_check = 0;
            }

            if (fun_key2[index] == 1)
                fun_key2_push_up_check++;
            else {
                index = 5;
                fun_key2_push_up_check = 0;
            }
        }

        if (fun_key1_push_up_check == 8 && fun_key1[0] == 1) {
            loop_num_key1++;
        } else if (fun_key2_push_up_check == 8 && fun_key2[0] == 1) {
            loop_num_key2++;
        }

        if (read_rtc_flag)
            rtc_display(rtc_read_val.rhrcnt, rtc_read_val.rmincnt, rtc_read_val.rseccnt);

        /* FIXME: Since this is a temporary process, so re-create a waiting process yourself. */
        R_BSP_SoftwareDelay (TOUCH_SCAN_INTERVAL_EXAMPLE, BSP_DELAY_MILLISECS);
    }
}


