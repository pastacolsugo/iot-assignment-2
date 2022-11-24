#include "LcdTask.h"

void LcdTask::printWater(){
    lcd->setCursor(0, 1);
    lcd->print("Water: ");
    lcd->print(status->getWater());
}

void LcdTask::printValve(){
        lcd->setCursor(10, 1);
        lcd->print("Valve: ");
        lcd->print(status->getValveDegree());
}

LcdTask::LcdTask(Status* st){
    this->lcd = new LiquidCrystal_I2C(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);
    this->status = st;
}

void LcdTask::init(){
    lcd->init();
    lcd->backlight();
}


void LcdTask::run(){

    lcd->clear();
    lcd->setCursor(0, 0); // Set the cursor on the third column and first row.
    
    switch (status->getState())
    {
    case ALARM:
        lcd->print("ALARM");
        printWater();
        printValve();
        break;

    case PREALARM:
        lcd->print("PREALARM ");
        break;
    
    default:
        lcd->print("NORMAL");
        break;
    }
}