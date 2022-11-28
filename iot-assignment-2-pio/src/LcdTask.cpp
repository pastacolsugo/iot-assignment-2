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
    lcd->print(" mm");
}

void LcdTask::printValve(){
    lcd->setCursor(0, 2);
    lcd->print("Valve: ");
    lcd->print(status->getValvePosition());
}

void LcdTask::printControl(){
        lcd->print( status->getValveControl() == Control::AUTO ? " - AUTO" : " - MANUALE" );
}

void LcdTask::run(){

    lcd->clear();
    lcd->setCursor(0, 0); // Set the cursor on the third column and first row.
    
    switch (status->getState())
    {
    case ALARM:
      lcd->print("ALARM");
      lcd->setCursor(5, 0); printControl();
      printWater();
      break;

    case PREALARM:
      lcd->print("PREALARM");
      lcd->setCursor(8, 0); printControl();
      printWater();
      break;

    default:
      lcd->print("NORMAL");
      lcd->setCursor(6, 0); printControl();
  }


  if(status->getState() == State::ALARM || status->getValveControl() == Control::MANUAL){
      printValve();
  }
}