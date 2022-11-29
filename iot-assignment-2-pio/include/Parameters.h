#ifndef __PARAMETERS__
#define __PARAMETERS__

#define SCHDULER_PERIOD 100

#define LAMP_TASK_PERIOD 200
#define VALVE_TASK_PERIOD 500 //best value
#define SONAR_TASK_PERIOD_NORMAL 300
#define SONAR_TASK_PERIOD_PREALARM 200
#define SONAR_TASK_PERIOD_ALARM 100
#define STOPLIGHT_TASK_PERIOD 500
#define LCD_TASK_PERIOD 200
#define SERIAL_TASK_PERIOD 500

// Used into LampTask.cpp
#define LIGHT_THRESHOLD__LEVEL 150
#define LAMP_TIMEOUT 3000

// Used into StoplightTask.cpp
#define TOGGLE_PERIOD 2000

// Used into ValveTask.cpp and SonarTask.cpp
#define WATER_LEVEL_1 600
#define WATER_LEVEL_2 750
#define WATER_LEVEL_MAX 1000

// Used into LcdTask.cpp
/* I2C address of the LCD: 0x27 */
#define LCD_ADDRESS 0x27
/* Number of columns: 20 rows: 4 */
#define LCD_COLUMNS 20
#define LCD_ROWS 4

// Used into SerialTask.cpp
#define SERIAL_BAUD 115200
#define MAX_MESSAGE_LENGTH 16

#endif