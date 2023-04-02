
#pragma once

#ifndef TARGET_STM32F4
  #error "Oops! Select an STM32F4 board in 'Tools > Board.'"
#elif HOTENDS > 3 || E_STEPPERS > 3
  #error "BIGTREE SKR Pro V1.1 supports up to 3 hotends / E-steppers."
#endif

#define BOARD_INFO_NAME "BIGTREE SKR Pro 1.1" // redefined?

#define SERVO0_PIN         PA1

//
// Limit Switches
//
#define X_MIN_PIN          PB10
//#define X_MAX_PIN          PE15
#define Y_MIN_PIN          PE12
//#define Y_MAX_PIN          PE10 33  utilisé pour filament runout sensor
#define Z_MIN_PIN          PG8
#define Z_MAX_PIN          PG5

//
// Z Probe must be this pins
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN  PA2
#endif

//
// filament sensor
//
#define FIL_RUNOUT_PIN PE10
///dan #define FIL_RUNOUT2_PIN PE15

//
// Main Relais sensor BTT v1.2
//
#define PS_ON_PIN  PD0

//
// Steppers
//
#define X_STEP_PIN         PE9
#define X_DIR_PIN          PF1
#define X_ENABLE_PIN       PF2
#ifndef X_CS_PIN
  #define X_CS_PIN         PA15
#endif

#define Y_STEP_PIN         PE11
#define Y_DIR_PIN          PE8
#define Y_ENABLE_PIN       PD7
 #ifndef Y_CS_PIN
  #define Y_CS_PIN         PB8
#endif

#define Z_STEP_PIN         PE13
#define Z_DIR_PIN          PC2
#define Z_ENABLE_PIN       PC0
#ifndef Z_CS_PIN
  #define Z_CS_PIN         PB9
#endif

#define E0_STEP_PIN        PE14
#define E0_DIR_PIN         PA0
#define E0_ENABLE_PIN      PC3
#ifndef E0_CS_PIN
  #define E0_CS_PIN        PB3
#endif

#define E1_STEP_PIN        PD15
#define E1_DIR_PIN         PE7
#define E1_ENABLE_PIN      PA3
#ifndef E1_CS_PIN
  #define E1_CS_PIN        PG15
#endif

#define Z2_STEP_PIN        PD13
#define Z2_DIR_PIN         PG9
#define Z2_ENABLE_PIN      PF0
 
#ifndef Z2_CS_PIN
  #define Z2_CS_PIN        PG12
#endif

//
// Software SPI pins for TMC2130 stepper drivers
//
#if ENABLED(TMC_USE_SW_SPI)
  #ifndef TMC_SW_MOSI
    #define TMC_SW_MOSI    PC12
  #endif
  #ifndef TMC_SW_MISO
    #define TMC_SW_MISO    PC11
  #endif
  #ifndef TMC_SW_SCK
    #define TMC_SW_SCK     PC10
  #endif
#endif

#if HAS_TMC220x
  
  //
  // Software serial
  //
  #define X_SERIAL_TX_PIN  PC13
  #define X_SERIAL_RX_PIN  PC13

  #define Y_SERIAL_TX_PIN  PE3
  #define Y_SERIAL_RX_PIN  PE3

  #define Z_SERIAL_TX_PIN  PE1
  #define Z_SERIAL_RX_PIN  PE1

  #define E0_SERIAL_TX_PIN PD4
  #define E0_SERIAL_RX_PIN PD4

  #define E1_SERIAL_TX_PIN PD1
  #define E1_SERIAL_RX_PIN PD1

  #define Z2_SERIAL_TX_PIN PD6
  #define Z2_SERIAL_RX_PIN PD6

  // Reduce baud rate to improve software serial reliability
  #define TMC_BAUD_RATE 19200
#endif

//
// Temperature Sensors
//
#define TEMP_0_PIN         PF4  // T1 <-> E0
#define TEMP_1_PIN         PF5  // T2 <-> E1
#define TEMP_CHAMBER_PIN   PF6  // T3 <-> E2
#define TEMP_BED_PIN       PF3  // T0 <-> Bed

//
// Heaters 
//
#define HEATER_0_PIN       PB1  // Heater0
#define HEATER_1_PIN       PD14 // Heater1
#define HEATER_2_PIN       PB0  // Heater1
#define HEATER_BED_PIN     PD12 // Hotbed

// Fans
#define FAN_PIN            PE5  ///dan inverse avec // Fan1 Turbine
#define FAN1_PIN           PC8  ///dan inverse avec Fan // Fan hotend 1
#define FAN2_PIN           PE6  // Fan hotend 2

//
// Misc. Functions
//

#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION LCD
#endif

//
// Onboard SD card
//   NOT compatible with LCD
//
#if SDCARD_CONNECTION == ONBOARD && !defined(HAS_SPI_LCD)
  #define SOFTWARE_SPI            // Use soft SPI for onboard SD
  #define SDSS             PA4
  #define SCK_PIN          PA5
  #define MISO_PIN         PA6
  #define MOSI_PIN         PB5
#else
  #define SDSS             PB12
#endif

#if HAS_SPI_LCD
  #define BEEPER_PIN       PG4
  #define BTN_ENC          PA8

  #if ENABLED(CR10_STOCKDISPLAY)
    #define LCD_PINS_RS    PG6

    #define BTN_EN1        PD11
    #define BTN_EN2        PG2

    #define LCD_PINS_ENABLE PG7
    #define LCD_PINS_D4    PG3

    // CR10_Stock Display needs a different delay setting on SKR PRO v1.1, so undef it here.
    // It will be defined again at the #HAS_GRAPHICAL_LCD section below.
    #undef ST7920_DELAY_1
    #undef ST7920_DELAY_2
    #undef ST7920_DELAY_3


  #else

    #define LCD_PINS_RS    PD10

    #define BTN_EN1        PG10
    #define BTN_EN2        PF11
    #define SD_DETECT_PIN  PF12

    #define LCD_SDSS       PB12

    #define LCD_PINS_ENABLE PD11
    #define LCD_PINS_D4    PG2

    #if ENABLED(FYSETC_MINI_12864)
      #define DOGLCD_CS    PD11
      #define DOGLCD_A0    PD10
      //#define LCD_BACKLIGHT_PIN -1
      #define LCD_RESET_PIN PG2   // Must be high or open for LCD to operate normally.
      #if EITHER(FYSETC_MINI_12864_1_2, FYSETC_MINI_12864_2_0)
        #ifndef RGB_LED_R_PIN
          #define RGB_LED_R_PIN PG3
        #endif
        #ifndef RGB_LED_G_PIN
          #define RGB_LED_G_PIN PG6
        #endif
        #ifndef RGB_LED_B_PIN
          #define RGB_LED_B_PIN PG7
        #endif
      #elif ENABLED(FYSETC_MINI_12864_2_1)
        #define NEOPIXEL_PIN    PG3
      #endif
    #endif // !FYSETC_MINI_12864

    #if ENABLED(ULTIPANEL)
      #define LCD_PINS_D5  PG3
      #define LCD_PINS_D6  PG6
      #define LCD_PINS_D7  PG7
    #endif

  #endif

  // Alter timing for graphical display
  #if HAS_GRAPHICAL_LCD
    #define BOARD_ST7920_DELAY_1 DELAY_NS(96)
    #define BOARD_ST7920_DELAY_2 DELAY_NS(48)
    #define BOARD_ST7920_DELAY_3 DELAY_NS(600)
  #endif

#endif // HAS_SPI_LCD
