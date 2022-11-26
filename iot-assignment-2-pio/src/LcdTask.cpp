#include "LcdTask.h"

LcdTask::LcdTask(Status* st){
    this->lcd = new LiquidCrystal_I2C(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);
    this->status = st;
    lcd->init();
    lcd->backlight();
}

void LcdTask::printWater(){
    lcd->setCursor(0, 1);
    lcd->print("Water: ");
    lcd->print(status->getWater());
}

void LcdTask::printValve(){
        lcd->setCursor(0, 2);
        lcd->print("Valve: ");
        lcd->print(status->getValvePosition());
}

void LcdTask::printControl(){
        lcd->setCursor(5, 0);
        lcd->print( status->getValveControl() == Control::AUTO ? " - AUTOMATICO" : " - MANUALE" );
}

void LcdTask::run(){

    lcd->clear();
    lcd->setCursor(0, 0); // Set the cursor on the third column and first row.
    
    switch (status->getState())
    {
    case ALARM:
      lcd->print("ALARM");
      printControl();
      printWater();
      //printValve();   decomment when chek ValveTask
      break;

    case PREALARM:
      lcd->print("PREALARM ");
      printWater();
      break;

    default:
      lcd->print("NORMAL");
  }
}