#ifndef __PARAMETERS__
#define __PARAMETERS__

#define SCHDULER_PERIOD 50
#define LAMP_TASK_PERIOD 50
#define VALVE_TASK_PERIOD 50
#define SONAR_TASK_PERIOD_NORMAL 50
#define SONAR_TASK_PERIOD_PREALARM 30
#define SONAR_TASK_PERIOD_ALARM 10
#define STOPLIGHT_TASK_PERIOD 1000
#define LCD_TASK_PERIOD 50

// Used into LampTask.cpp
#define LIGHT_THRESHOLD__LEVEL 10
#define LAMP_TIMEOUT 1000

// Used into ValveTask.cpp and SonarTask.cpp
#define WATER_LEVEL_1 100
#define WATER_LEVEL_2 300
#define WATER_LEVEL_MAX 1000

// Used into LcdTask.cpp
/* I2C address of the LCD: 0x27 */
#define LCD_ADDRESS 0x27
/* Number of columns: 20 rows: 4 */
#define LCD_COLUMNS 20
#define LCD_ROWS 4

#endif