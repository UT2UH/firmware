// For K46 peripherial
#define I2C_SDA 21
#define I2C_SCL 22

// GPS
#define HAS_GPS 0
#undef GPS_RX_PIN
#undef GPS_TX_PIN
#define GPS_UBLOX
#define PIN_GPS_EN 32

// PCF8563 RTC Module
#include "pcf8563.h"
#define HAS_RTC 1
#define PCF8563_RTC 0x51
//#define HAS_32768HZ

#define BUTTON_PIN 13 // or 33 or 4
#define BUTTON_NEED_PULLUP // if set we need to turn on the internal CPU pullup during sleep
#undef  EXT_NOTIFY_OUT // Default pin to use for Ext Notify Plugin.
//#define LED_PIN 19     // not status LED but BTN_BL
#define PIN_BUZZER 18

#define RF95_SCK 5
#define RF95_MISO 16
#define RF95_MOSI 2
#define RF95_NSS 25
#define LORA_GPIO00 0
#define LORA_GPIO36 36
#define LORA_GPIO39 39
#define LORA_CS     25
#define LORA_RESET  RADIOLIB_NC

// Only one permitted for the module installed
//#define USE_RF95
//#define USE_LLCC68
//#define USE_SX1262
//#define USE_SX1268
//#define USE_LORA127XF30
//#define USE_LORA126XF30
#define USE_R68837DHAV2

#if defined (USE_RF95)
  #define LORA_DIO0   LORA_GPIO36
  #define LORA_DIO1   RADIOLIB_NC
  #define LORA_DIO2   LORA_GPIO39
  #define LORA_DIO3   RADIOLIB_NC
  #define RF95_IRQ    LORA_DIO0
#elif defined (USE_LORA127XF30)
  #define USE_RF95
  #define LORA_DIO0   LORA_GPIO36
  #define LORA_DIO1   RADIOLIB_NC
  #define LORA_DIO2   LORA_GPIO39
  #define LORA_DIO3   RADIOLIB_NC
  #define RF95_IRQ    LORA_DIO0
#elif defined (USE_LLCC68)
  #define SX126X_CS   LORA_CS
  #define SX126X_RESET LORA_RESET
  #define SX126X_DIO1 LORA_GPIO36
  #define SX126X_BUSY LORA_GPIO39
  #define SX126X_MAX_POWER 22
#elif defined (USE_SX1262) || defined (USE_SX1268)
  #define SX126X_CS   LORA_CS
  #define SX126X_RESET LORA_RESET
  #define SX126X_DIO1 LORA_GPIO36
  #define SX126X_BUSY LORA_GPIO39
  #define SX126X_MAX_POWER 22
#elif defined (USE_LORA126XF30)
  #define USE_SX1268
  #define SX126X_POWER_EN 12
  #define SX126X_CS LORA_CS
  #define SX126X_RESET LORA_RESET
  #define SX126X_DIO1 LORA_GPIO39
  #define SX126X_BUSY LORA_GPIO36
  #define SX126X_MAX_POWER 13 // Set lora.tx_power to 13 due to PA
#elif defined (USE_R68837DHAV2)
  #define USE_SX1268
  #define SX126X_R6822DH
  #define SX126X_POWER_EN 12
  #define SX126X_CS LORA_CS
  #define SX126X_RESET LORA_RESET
  #define SX126X_DIO1 LORA_GPIO39
  #define SX126X_BUSY LORA_GPIO36
  #define SX126X_RXEN LORA_GPIO00
  #define SX126X_TXEN RADIOLIB_NC
  #define E22_TXEN_CONNECTED_TO_DIO2 1
  #define SX126X_MAX_POWER 13 // Set lora.tx_power to 13 due to PA
//#define SX126X_E22 // use DIO2 as RF switch
#endif

// Define if screen should be mirrored left to right
#define SCREEN_ROTATE
// LCD screens are slow, so slowdown the wipe so it looks better
#define SCREEN_TRANSITION_FRAMERATE 1 // fps
