
#include <Adafruit_SSD1306.h>
#include "BatteryL.h"

int battery1Level;
int battery2Level;

BatteryL::BatteryL(int b1,int b2){
    battery1Level = b1;
    battery2Level = b2;
}

void BatteryL::BatteryInit(Adafruit_SSD1306 *d) {
    display = *d;
}

void BatteryL::UpdateDisplay() {
  Serial.println("Item 2 Selected");
    display.clearDisplay();

    // Draw battery 1
    display.setCursor(0, 0);
    display.println("B1:");
    display.drawRect(40, 0, 30, 16, SSD1306_WHITE); // Draw battery outline
    display.fillRect(42, 2, 26 * battery1Level / 100, 12, SSD1306_WHITE); // Draw battery level

    // Draw battery 2
    display.setCursor(0, 40);
    display.println("B2:");
    display.drawRect(40, 40, 30, 16, SSD1306_WHITE); // Draw battery outline
    display.fillRect(42, 42, 26 * battery2Level / 100, 12, SSD1306_WHITE); // Draw battery level
    
    display.display();
    

  
  display.clearDisplay();
}

int BatteryL::getBattery1Level(){
  return battery1Level;
}
int BatteryL::getBattery2Level(){
  return battery2Level;
}
void BatteryL::setBattery1Level(int level){
  battery1Level = level;
}

void BatteryL::setBattery2Level(int level){
  battery2Level = level;
}   
