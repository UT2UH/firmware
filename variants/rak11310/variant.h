// #define RADIOLIB_CUSTOM_ARDUINO 1
// #define RADIOLIB_TONE_UNSUPPORTED 1
// #define RADIOLIB_SOFTWARE_SERIAL_UNSUPPORTED 1

#define ARDUINO_ARCH_AVR

#undef CBC
#define CBC 0
#undef CTR
#define CTR 1
#undef ECB
#define ECB 0

#undef GPS_SERIAL_NUM

// #define I2C_SDA 20
// #define I2C_SCL 21

#define PIN_LED1 23
#define PIN_LED2 24

#undef PIN_LED
#define PIN_LED PIN_LED1
#define LED_CONN PIN_LED2

#define BUTTON_PIN 9
#define BUTTON_NEED_PULLUP
// #define EXT_NOTIFY_OUT 4

#define BATTERY_PIN 26
// ratio of voltage divider = 3.0 (R17=200k, R18=100k)
#define ADC_MULTIPLIER 3.1 // 3.0 + a bit for being optimistic

#define USE_SX1262

#undef RF95_SCK
#undef RF95_MISO
#undef RF95_MOSI
#undef RF95_NSS

#define RF95_SCK 10
#define RF95_MISO 12
#define RF95_MOSI 11
#define RF95_NSS 13

#define LORA_DIO0 RADIOLIB_NC
#define LORA_RESET 14
#define LORA_DIO1 29
#define LORA_DIO2 15
#define LORA_DIO3 RADIOLIB_NC

#ifdef USE_SX1262
#define SX126X_CS RF95_NSS
#define SX126X_DIO1 LORA_DIO1
#define SX126X_BUSY LORA_DIO2
#define SX126X_RESET LORA_RESET
#define SX126X_POWER_EN 25
#define SX126X_E22 // DIO2 controlls an antenna switch and the TCXO voltage is controlled by DIO3
#endif

#include <Adafruit_TinyUSB.h>