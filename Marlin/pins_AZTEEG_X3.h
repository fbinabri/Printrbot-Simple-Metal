/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * AZTEEG_X3 Arduino Mega with RAMPS v1.4 pin assignments
 */

#ifndef __AVR_ATmega2560__
  #error "Oops! Make sure you have 'Arduino Mega 2560' selected from the 'Tools -> Boards' menu."
#endif

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "Azteeg X3 supports up to 2 hotends / E-steppers. Comment out this line to continue."
#endif

#if ENABLED(CASE_LIGHT_ENABLE) && !PIN_EXISTS(CASE_LIGHT)
  #define CASE_LIGHT_PIN    6   // Define before RAMPS pins include
#endif
#define BOARD_NAME "Azteeg X3"

//
// Servos
//
#define SERVO0_PIN         -1   // SERVO1 port
#define SERVO1_PIN         -1   // SERVO2 port

//
// Limit Switches
//
#define X_MIN_PIN           3
#ifndef X_MAX_PIN
  #define X_MAX_PIN         2
#endif
#define Y_MIN_PIN          14
#ifndef Y_MAX_PIN
  #define Y_MAX_PIN        15
#endif
#define Z_MIN_PIN          18
#ifndef Z_MAX_PIN
  #define Z_MAX_PIN        19
#endif

//
// Z-Probe
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN  32
#endif

//
// Steppers
//
#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#ifndef X_CS_PIN
  #define X_CS_PIN         42
#endif

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#ifndef Y_CS_PIN
  #define Y_CS_PIN         43
#endif

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#ifndef Z_CS_PIN
  #define Z_CS_PIN         40
#endif

#define E0_STEP_PIN        26
#define E0_DIR_PIN         28
#define E0_ENABLE_PIN      24
#ifndef E0_CS_PIN
  #define E0_CS_PIN        41
#endif

#define E1_STEP_PIN        36
#define E1_DIR_PIN         34
#define E1_ENABLE_PIN      30
#ifndef E1_CS_PIN
  #define E1_CS_PIN        37
#endif

//
// Default pins for TMC software SPI
//
//#if ENABLED(TMC_USE_SW_SPI)
//  #ifndef TMC_SW_MOSI
//    #define TMC_SW_MOSI    66
//  #endif
//  #ifndef TMC_SW_MISO
//    #define TMC_SW_MISO    44
//  #endif
//  #ifndef TMC_SW_SCK
//    #define TMC_SW_SCK     64
//  #endif
//#endif

//
// TMC2208 Driver
//
#if HAS_DRIVER(TMC2208)
  /**
   * TMC2208 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   */
  //#define X_HARDWARE_SERIAL  Serial1
  //#define X2_HARDWARE_SERIAL Serial1
  //#define Y_HARDWARE_SERIAL  Serial1
  //#define Y2_HARDWARE_SERIAL Serial1
  //#define Z_HARDWARE_SERIAL  Serial1
  //#define Z2_HARDWARE_SERIAL Serial1
  //#define E0_HARDWARE_SERIAL Serial1
  //#define E1_HARDWARE_SERIAL Serial1
  //#define E2_HARDWARE_SERIAL Serial1
  //#define E3_HARDWARE_SERIAL Serial1
  //#define E4_HARDWARE_SERIAL Serial1

  /**
   * Software serial
   */
  #define X_SERIAL_TX_PIN    40
  #define X_SERIAL_RX_PIN    63
  #define X2_SERIAL_TX_PIN   -1
  #define X2_SERIAL_RX_PIN   -1

  #define Y_SERIAL_TX_PIN    59
  #define Y_SERIAL_RX_PIN    64
  #define Y2_SERIAL_TX_PIN   -1
  #define Y2_SERIAL_RX_PIN   -1

  #define Z_SERIAL_TX_PIN    42
  #define Z_SERIAL_RX_PIN    65
  #define Z2_SERIAL_TX_PIN   -1
  #define Z2_SERIAL_RX_PIN   -1

  #define E0_SERIAL_TX_PIN   44
  #define E0_SERIAL_RX_PIN   66
  #define E1_SERIAL_TX_PIN   -1
  #define E1_SERIAL_RX_PIN   -1
  #define E2_SERIAL_TX_PIN   -1
  #define E2_SERIAL_RX_PIN   -1
  #define E3_SERIAL_TX_PIN   -1
  #define E3_SERIAL_RX_PIN   -1
  #define E4_SERIAL_TX_PIN   -1
  #define E4_SERIAL_RX_PIN   -1
#endif

//
// Temperature Sensors
//
#define TEMP_0_PIN         13   // Analog Input
#define TEMP_1_PIN         14   // Analog Input
#define TEMP_BED_PIN       5   // Analog Input

// SPI for Max6675 or Max31855 Thermocouple
#if DISABLED(SDSUPPORT)
  #define MAX6675_SS       66   // Do not use pin 53 if there is even the remote possibility of using Display/SD card
#else
  #define MAX6675_SS       66   // Do not use pin 49 as this is tied to the switch inside the SD card socket to detect if there is an SD card present
#endif

//
// Heaters / Fans
//
#define HEATER_0_PIN	  	10
#define HEATER_1_PIN		  9
#define HEATER_BED_PIN		8
#define FAN_PIN			4
#define FAN1_PIN		44

//
// LCD Controller
//
#if ENABLED(VIKI2) || ENABLED(miniVIKI)

  #define DOGLCD_A0         31
  #define DOGLCD_CS         32
  
  #define BTN_ENC           39
  #define BTN_EN1           7
  #define BTN_EN2           22

  #define STAT_LED_RED_PIN  6
  #define STAT_LED_BLUE_PIN 11
  
  #define SD_DETECT_PIN     49
  #define KILL_PIN          -1

#else
// MKS MiniPanel
  #define DOGLCD_A0         31
  #define DOGLCD_CS         32
  
  #define BTN_ENC           39
  #define BTN_EN1           7
  #define BTN_EN2           22

  #define STAT_LED_RED_PIN  6
  #define STAT_LED_BLUE_PIN 11
  
  #define SD_DETECT_PIN     49
  #define KILL_PIN          -1

  #define LCD_BACKLIGHT_PIN 65 // backlight LED on A11/D65

#endif

//
// Misc Functions
//
#define BEEPER_PIN          6
#define SDSS                53
#define SDPOWER		          -1
#define LED_PIN             5

#ifndef FILWIDTH_PIN
  #define FILWIDTH_PIN      5   // Analog Input on AUX2
#endif

#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN    2
#endif

#ifndef PS_ON_PIN
  #define PS_ON_PIN        12
#endif

#if ENABLED(CASE_LIGHT_ENABLE)  && PIN_EXISTS(CASE_LIGHT) && PIN_EXISTS(STAT_LED_RED) && STAT_LED_RED_PIN == CASE_LIGHT_PIN
  #undef STAT_LED_RED_PIN
#endif

//
// M3/M4/M5 - Spindle/Laser Control
//
#if ENABLED(SPINDLE_LASER_ENABLE)
  #if SERVO0_PIN == 7
    #undef SERVO0_PIN
    #define SERVO0_PIN     11
  #endif
  #define SPINDLE_LASER_PWM_PIN     7   // MUST BE HARDWARE PWM
  #define SPINDLE_LASER_ENABLE_PIN 20   // Pin should have a pullup!
  #define SPINDLE_DIR_PIN          21
#endif
