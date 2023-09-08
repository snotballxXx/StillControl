#ifndef __CONSTANTS__H__
#define __CONSTANTS__H__

#define WEB_PORT        8080
#define HEATER_OUTPUT   D7
#define OK_BUTTON       D3
#define LEFT_BUTTON     D0
#define RIGHT_BUTTON    D8
#define DEBOUNCE_TIME   50

#define THERMO_DO       D4
#define THERMO_CS       D5
#define THERMO_CLK      D6

#define WIFI_SSID "TheMadHouse24"
#define WIFI_PASS "masonlewissuck!"

#define DISPLAY_STATE                0
#define LOWER_THRESHOLD_STATE        1
#define UPPER_THRESHOLD_STATE        2
#define MARK_TIME_STATE              3
#define SPACE_TIME_STATE             4
#define STATE_COUNT         (SPACE_TIME_STATE + 1)     

#define MIN_LOWER_THRESHOLD             10
#define MIN_UPPER_THRESHOLD             MIN_LOWER_THRESHOLD + 10
#define MAX_UPPER_THRESHOLD             105
#define MARKSPACE_TIME_INCREMENT        50
#define DISPLAY_UPDATE_EVERY_X_MILLI    500

#define MAGIC_NUMBER                    115
#define MAGIC_NUMBER_ADDR               0
#define LOWER_THRESHOLD_ADDR            1
#define UPPER_THRESHOLD_ADDR            3
#define MARK_TIME_ADDR                  5
#define SPACE_TIME_ADDR                 7

#define DEFAULT_VALUE_LOWER_THRESHOLD   78
#define DEFAULT_VALUE_UPPER_THRESHOLD   82
#define DEFAULT_VALUE_MARK_TIME         500
#define DEFAULT_VALUE_SPACE_TIME        1000
#define THERMO_READ_TIME_INTERVAL       500
#endif  //!__CONSTANTS__H__