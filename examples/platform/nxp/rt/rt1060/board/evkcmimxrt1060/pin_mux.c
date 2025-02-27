/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v14.0
processor: MIMXRT1062xxxxB
package_id: MIMXRT1062DVL6B
mcu_data: ksdk2_0
processor_version: 14.0.1
board: MIMXRT1060-EVKC
pin_labels:
- {pin_num: M12, pin_signal: GPIO_AD_B1_03, label: 'SPDIF_IN/U15[4]/WL_RST#/J8[56]/SD_PWREN/Q5[1]/J16[8]', identifier:
SPDIF_IN;WL_RST;SD_PWREN}
- {pin_num: H13, pin_signal: GPIO_AD_B1_08, label: 'AUD_INT/J34[5]/U25[15]/WIFI_RST_B/U9[3]/CSI_D9/J46[13]/J16[4]', identifier:
CSI_D9;SDIO_RST}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "pin_mux.h"
#include "fsl_common.h"
#include "fsl_gpio.h"
#include "fsl_iomuxc.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
    BOARD_InitDEBUG_UARTPins();
    BOARD_InitUSDHCPins();
    BOARD_InitBLEUARTPins();
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void) {}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitDEBUG_UARTPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: K14, peripheral: LPUART1, signal: TX, pin_signal: GPIO_AD_B0_12, software_input_on: Disable, hysteresis_enable:
Disable, pull_up_down_config: Pull_Down_100K_Ohm, pull_keeper_select: Keeper, pull_keeper_enable: Enable, open_drain: Disable,
speed: MHZ_100, drive_strength: R0_6, slew_rate: Slow}
  - {pin_num: L14, peripheral: LPUART1, signal: RX, pin_signal: GPIO_AD_B0_13, software_input_on: Disable, hysteresis_enable:
Disable, pull_up_down_config: Pull_Down_100K_Ohm, pull_keeper_select: Keeper, pull_keeper_enable: Enable, open_drain: Disable,
speed: MHZ_100, drive_strength: R0_6, slew_rate: Slow}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitDEBUG_UARTPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitDEBUG_UARTPins(void)
{
    CLOCK_EnableClock(kCLOCK_Iomuxc);

    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_12_LPUART1_TX, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_13_LPUART1_RX, 0U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_12_LPUART1_TX, 0x10B0U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_13_LPUART1_RX, 0x10B0U);
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitUSDHCPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: J2, peripheral: USDHC1, signal: 'usdhc_data, 3', pin_signal: GPIO_SD_B0_05, hysteresis_enable: Disable,
pull_up_down_config: Pull_Up_100K_Ohm, pull_keeper_select: Pull, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_100,
drive_strength: R0_7, slew_rate: Fast}
  - {pin_num: H2, peripheral: USDHC1, signal: 'usdhc_data, 2', pin_signal: GPIO_SD_B0_04, hysteresis_enable: Disable,
pull_up_down_config: Pull_Up_100K_Ohm, pull_keeper_select: Pull, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_100,
drive_strength: R0_7, slew_rate: Fast}
  - {pin_num: K1, peripheral: USDHC1, signal: 'usdhc_data, 1', pin_signal: GPIO_SD_B0_03, hysteresis_enable: Disable,
pull_up_down_config: Pull_Up_100K_Ohm, pull_keeper_select: Pull, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_100,
drive_strength: R0_7, slew_rate: Fast}
  - {pin_num: J1, peripheral: USDHC1, signal: 'usdhc_data, 0', pin_signal: GPIO_SD_B0_02, hysteresis_enable: Disable,
pull_up_down_config: Pull_Up_100K_Ohm, pull_keeper_select: Pull, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_100,
drive_strength: R0_7, slew_rate: Fast}
  - {pin_num: J4, peripheral: USDHC1, signal: usdhc_cmd, pin_signal: GPIO_SD_B0_00, hysteresis_enable: Disable, pull_up_down_config:
Pull_Up_100K_Ohm, pull_keeper_select: Pull, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_100, drive_strength: R0_7,
slew_rate: Fast}
  - {pin_num: J3, peripheral: USDHC1, signal: usdhc_clk, pin_signal: GPIO_SD_B0_01, hysteresis_enable: Disable, pull_up_down_config:
Pull_Up_100K_Ohm, pull_keeper_select: Keeper, pull_keeper_enable: Disable, open_drain: Disable, speed: MHZ_100, drive_strength:
R0_7, slew_rate: Fast}
  - {pin_num: C14, peripheral: USDHC1, signal: usdhc_vselect, pin_signal: GPIO_B1_14, hysteresis_enable: Disable,
pull_up_down_config: Pull_Up_100K_Ohm, pull_keeper_select: Pull, drive_strength: R0_7, slew_rate: Fast}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitUSDHCPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitUSDHCPins(void)
{
    CLOCK_EnableClock(kCLOCK_Iomuxc);

    IOMUXC_SetPinMux(IOMUXC_GPIO_B1_14_USDHC1_VSELECT, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_00_USDHC1_CMD, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_01_USDHC1_CLK, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_02_USDHC1_DATA0, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_03_USDHC1_DATA1, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_04_USDHC1_DATA2, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_05_USDHC1_DATA3, 0U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_B1_14_USDHC1_VSELECT, 0xB0B9U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B0_00_USDHC1_CMD, 0xB0B9U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B0_01_USDHC1_CLK, 0x80B9U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B0_02_USDHC1_DATA0, 0xB0B9U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B0_03_USDHC1_DATA1, 0xB0B9U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B0_04_USDHC1_DATA2, 0xB0B9U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B0_05_USDHC1_DATA3, 0xB0B9U);
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitBLEUARTPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: J12, peripheral: LPUART3, signal: TX, pin_signal: GPIO_AD_B1_06, software_input_on: no_init, hysteresis_enable:
no_init, pull_up_down_config: Pull_Down_100K_Ohm, pull_keeper_select: Keeper, pull_keeper_enable: Enable, open_drain: Disable,
speed: MHZ_100, drive_strength: R0_3}
  - {pin_num: K12, peripheral: LPUART3, signal: RTS_B, pin_signal: GPIO_AD_B1_05, hysteresis_enable: Disable, pull_up_down_config:
Pull_Down_100K_Ohm, pull_keeper_select: Keeper, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_100}
  - {pin_num: L12, peripheral: LPUART3, signal: CTS_B, pin_signal: GPIO_AD_B1_04, hysteresis_enable: Disable, pull_up_down_config:
Pull_Down_100K_Ohm, pull_keeper_select: Keeper, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_100}
  - {pin_num: K10, peripheral: LPUART3, signal: RX, pin_signal: GPIO_AD_B1_07, pull_up_down_config: Pull_Down_100K_Ohm,
pull_keeper_select: Keeper, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_100}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBLEUARTPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBLEUARTPins(void)
{
    CLOCK_EnableClock(kCLOCK_Iomuxc);

    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_04_LPUART3_CTS_B, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_05_LPUART3_RTS_B, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_06_LPUART3_TX, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_07_LPUART3_RX, 0U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_04_LPUART3_CTS_B, 0x10B0U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_05_LPUART3_RTS_B, 0x10B0U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_06_LPUART3_TX, 0x1098U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_07_LPUART3_RX, 0x10B0U);
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPinsM2:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: M12, peripheral: GPIO1, signal: 'gpio_io, 19', pin_signal: GPIO_AD_B1_03, identifier: WL_RST, direction: OUTPUT,
gpio_init_state: 'false', slew_rate: Slow}
  - {pin_num: H13, peripheral: GPIO1, signal: 'gpio_io, 24', pin_signal: GPIO_AD_B1_08, identifier: SDIO_RST, direction: OUTPUT,
gpio_init_state: 'false', slew_rate: Slow}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPinsM2
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPinsM2(void)
{
    CLOCK_EnableClock(kCLOCK_Iomuxc);

    /* GPIO configuration of WL_RST on GPIO_AD_B1_03 (pin M12) */
    gpio_pin_config_t WL_RST_config = { .direction = kGPIO_DigitalOutput, .outputLogic = 0U, .interruptMode = kGPIO_NoIntmode };
    /* Initialize GPIO functionality on GPIO_AD_B1_03 (pin M12) */
    GPIO_PinInit(GPIO1, 19U, &WL_RST_config);

    /* GPIO configuration of SDIO_RST on GPIO_AD_B1_08 (pin H13) */
    gpio_pin_config_t SDIO_RST_config = { .direction = kGPIO_DigitalOutput, .outputLogic = 0U, .interruptMode = kGPIO_NoIntmode };
    /* Initialize GPIO functionality on GPIO_AD_B1_08 (pin H13) */
    GPIO_PinInit(GPIO1, 24U, &SDIO_RST_config);

    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_03_GPIO1_IO19, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_08_GPIO1_IO24, 0U);
    IOMUXC_GPR->GPR26 = ((IOMUXC_GPR->GPR26 & (~(BOARD_INITPINSM2_IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL_MASK))) |
                         IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL(0x00U));
    IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_03_GPIO1_IO19, 0x10B0U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_08_GPIO1_IO24, 0x10B0U);
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitM2SPIPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true', fullInit: 'true'}
- pin_list:
  - {pin_num: E8, peripheral: LPSPI4, signal: SDO, pin_signal: GPIO_B0_02, direction: INPUT, software_input_on: Disable,
hysteresis_enable: Disable, pull_up_down_config: Pull_Down_100K_Ohm, pull_keeper_select: Keeper, pull_keeper_enable: Enable,
open_drain: Disable, speed: MHZ_100, drive_strength: R0_6, slew_rate: Slow}
  - {pin_num: D8, peripheral: LPSPI4, signal: SCK, pin_signal: GPIO_B0_03, direction: INPUT, software_input_on: Disable,
hysteresis_enable: Disable, pull_up_down_config: Pull_Down_100K_Ohm, pull_keeper_select: Keeper, pull_keeper_enable: Enable,
open_drain: Disable, speed: MHZ_100, drive_strength: R0_6, slew_rate: Slow}
  - {pin_num: D7, peripheral: LPSPI4, signal: PCS0, pin_signal: GPIO_B0_00, direction: INPUT, software_input_on: Disable,
hysteresis_enable: Disable, pull_up_down_config: Pull_Down_100K_Ohm, pull_keeper_select: Keeper, pull_keeper_enable: Enable,
open_drain: Disable, speed: MHZ_100, drive_strength: R0_6, slew_rate: Slow}
  - {pin_num: E7, peripheral: LPSPI4, signal: SDI, pin_signal: GPIO_B0_01, direction: INPUT, software_input_on: Disable,
hysteresis_enable: Disable, pull_up_down_config: Pull_Down_100K_Ohm, pull_keeper_select: Keeper, pull_keeper_enable: Enable,
open_drain: Disable, speed: MHZ_100, drive_strength: R0_6, slew_rate: Slow}
  - {pin_num: C8, peripheral: GPIO2, signal: 'gpio_io, 04', pin_signal: GPIO_B0_04, direction: INPUT, gpio_interrupt:
kGPIO_NoIntmode, software_input_on: Disable, hysteresis_enable: Disable, pull_up_down_config: Pull_Down_100K_Ohm,
pull_keeper_select: Keeper, pull_keeper_enable: Enable, open_drain: Disable, speed: MHZ_100, drive_strength: R0_6, slew_rate: Slow}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitM2SPIPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitM2SPIPins(void)
{
    CLOCK_EnableClock(kCLOCK_Iomuxc);

    /* GPIO configuration of LCDIF_D0 on GPIO_B0_04 (pin C8) */
    gpio_pin_config_t LCDIF_D0_config = { .direction = kGPIO_DigitalInput, .outputLogic = 0U, .interruptMode = kGPIO_NoIntmode };
    /* Initialize GPIO functionality on GPIO_B0_04 (pin C8) */
    GPIO_PinInit(GPIO2, 4U, &LCDIF_D0_config);

    IOMUXC_SetPinMux(IOMUXC_GPIO_B0_00_LPSPI4_PCS0, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_B0_01_LPSPI4_SDI, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_B0_02_LPSPI4_SDO, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_B0_03_LPSPI4_SCK, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_B0_04_GPIO2_IO04, 0U);
    IOMUXC_GPR->GPR27 = ((IOMUXC_GPR->GPR27 & (~(BOARD_INITM2SPIPINS_IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL_MASK))) |
                         IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL(0x00U));
    IOMUXC_SetPinConfig(IOMUXC_GPIO_B0_00_LPSPI4_PCS0, 0x10B0U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_B0_01_LPSPI4_SDI, 0x10B0U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_B0_02_LPSPI4_SDO, 0x10B0U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_B0_03_LPSPI4_SCK, 0x10B0U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_B0_04_GPIO2_IO04, 0x10B0U);
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitOTWPins:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: L13, peripheral: GPIO1, signal: 'gpio_io, 26', pin_signal: GPIO_AD_B1_10, direction: OUTPUT,
gpio_init_state: 'true'}
  - {pin_num: M11, peripheral: GPIO1, signal: 'gpio_io, 27', pin_signal: GPIO_AD_B1_11, direction: OUTPUT,
gpio_init_state: 'true'}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitOTWPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitOTWPins(void)
{
    CLOCK_EnableClock(kCLOCK_Iomuxc);

    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_02_LPUART2_TX, 0U);
    IOMUXC_GPR->GPR26 = ((IOMUXC_GPR->GPR26 & (~(BOARD_INITPINS_IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL_MASK))) |
                         IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL(0x04U));

    /* This is GPIO pin used for K32W0x1 RCP ISP Entry/DIO5 pin */
    /* GPIO configuration on GPIO_AD_B1_10 (pin L13) */
    gpio_pin_config_t gpio1_pinL13_config = { .direction     = kGPIO_DigitalOutput,
                                              .outputLogic   = 1U,
                                              .interruptMode = kGPIO_NoIntmode };
    /* Initialize GPIO functionality on GPIO_AD_B1_10 (pin L13) */
    GPIO_PinInit(GPIO1, 26U, &gpio1_pinL13_config);

    /* This is GPIO pin used for K32W0x1 RCP Reset */
    /* GPIO configuration on GPIO_AD_B1_11 (pin J13) */
    gpio_pin_config_t gpio1_pinJ13_config = { .direction     = kGPIO_DigitalOutput,
                                              .outputLogic   = 1U,
                                              .interruptMode = kGPIO_NoIntmode };
    /* Initialize GPIO functionality on GPIO_AD_B1_11 (pin J13) */
    GPIO_PinInit(GPIO1, 27U, &gpio1_pinJ13_config);

    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_10_GPIO1_IO26, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_11_GPIO1_IO27, 0U);
    IOMUXC_GPR->GPR26 = ((IOMUXC_GPR->GPR26 & (~(BOARD_INITPINS_IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL_MASK))) |
                         IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL(0x00U));
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitM2I2CPins:
- options: {createDeInit: 'true', callFromInitBoot: 'true', coreID: core0, enableClock: 'true', customDeInitName:
BOARD_DeinitM2I2CPins, fullInit: 'true'}
- pin_list:
  - {pin_num: J11, peripheral: LPI2C1, signal: SCL, pin_signal: GPIO_AD_B1_00, software_input_on: Disable, hysteresis_enable:
Disable, pull_up_down_config: Pull_Down_100K_Ohm, pull_keeper_select: Keeper, pull_keeper_enable: Enable, open_drain: Disable,
speed: MHZ_100, drive_strength: R0_6, slew_rate: Slow}
  - {pin_num: K11, peripheral: LPI2C1, signal: SDA, pin_signal: GPIO_AD_B1_01, software_input_on: Disable, hysteresis_enable:
Disable, pull_up_down_config: Pull_Down_100K_Ohm, pull_keeper_select: Keeper, pull_keeper_enable: Enable, open_drain: Disable,
speed: MHZ_100, drive_strength: R0_6, slew_rate: Slow}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitM2I2CPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitM2I2CPins(void)
{
    CLOCK_EnableClock(kCLOCK_Iomuxc);

    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_00_LPI2C1_SCL, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_01_LPI2C1_SDA, 0U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_00_LPI2C1_SCL, 0x10B0U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_01_LPI2C1_SDA, 0x10B0U);
}

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_DeinitM2I2CPins
 * Description   : This is a de-initialization function for 'BOARD_InitM2I2CPins' function.
 * It sets all pins features (routing, direction and electrical) to their after-reset state.
 * It also tries to route the previous peripheral signals to their default pins.
 *
 * END ****************************************************************************************************************/
void BOARD_DeinitM2I2CPins(void)
{
    CLOCK_EnableClock(kCLOCK_Iomuxc);

    /* GPIO configuration on GPIO_AD_B1_00 (pin J11) */
    gpio_pin_config_t gpio1_pinJ11_config = { .direction     = kGPIO_DigitalInput,
                                              .outputLogic   = 0U,
                                              .interruptMode = kGPIO_NoIntmode };
    /* Initialize GPIO functionality on GPIO_AD_B1_00 (pin J11) */
    GPIO_PinInit(GPIO1, 16U, &gpio1_pinJ11_config);

    /* GPIO configuration on GPIO_AD_B1_01 (pin K11) */
    gpio_pin_config_t gpio1_pinK11_config = { .direction     = kGPIO_DigitalInput,
                                              .outputLogic   = 0U,
                                              .interruptMode = kGPIO_NoIntmode };
    /* Initialize GPIO functionality on GPIO_AD_B1_01 (pin K11) */
    GPIO_PinInit(GPIO1, 17U, &gpio1_pinK11_config);

    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_00_GPIO1_IO16, 0U);
    IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_01_GPIO1_IO17, 0U);
    IOMUXC_GPR->GPR26 = ((IOMUXC_GPR->GPR26 & (~(BOARD_DEINITM2I2CPINS_IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL_MASK))) |
                         IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL(0x00U));
    IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_00_GPIO1_IO16, 0x10B0U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_01_GPIO1_IO17, 0x10B0U);
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/