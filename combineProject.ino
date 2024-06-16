#include <Battery.h>
#include <Adafruit_SSD1306.h>
#include "menu.h"
#include "metronome.h"



#define SENSE_PIN 32
#define ACTIVATION_PIN 33
#define ADC_RESOLUTION 12

 static void item1Action();
 static void item2Action();
  void item3Action();
 static void item4Action();
 
String command;
Battery batt = Battery(3300, 4200, SENSE_PIN, ADC_RESOLUTION);
Menu menu = Menu();
Metronome metronome = Metronome();
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {

  Serial.begin(115200);
  
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);



  Serial.print("max volt: ");
  Serial.println(batt.level(4200));
  Serial.print("min volt: ");
  Serial.println(batt.level(3300));
  analogReadResolution(ADC_RESOLUTION);
  batt.onDemand(ACTIVATION_PIN, HIGH);
  batt.begin(5000, 1, &asigmoidal);

  menu.MenuInit(&display);
  menu.MenuSetItem("Metronome",&item1Action);
  menu.MenuSetItem("Battery",&item2Action);
  menu.MenuSetItem("Reset",&item3Action);
  menu.MenuSetItem("Exit",&item4Action);

}

void loop(){
    serialDebuger();
}




void test(){
  Serial.println("function invoked");
}
 
void item1Action() {
  Serial.println("Item 1 Selected");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Item 1 Action");
  display.display();
  delay(2000); // Pause to simulate task
  display.clearDisplay();
}

void item2Action() {
  Serial.println("Item 2 Selected");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Item 2 Action");
  display.display();
  delay(2000); // Pause to simulate task
  display.clearDisplay();
}

void item3Action() {
  Serial.println("Item 3 Selected");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Item 3 Action");
  display.display();
  delay(2000); // Pause to simulate task
  display.clearDisplay();
}

void item4Action() {
  Serial.println("Item 4 Selected");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Item 4 Action");
  display.display();
  delay(2000); // Pause to simulate task
  display.clearDisplay();
}


void showBatteryLevel(){
  delay(1000);
  Serial.print("current battery level: ");
  Serial.println(batt.level());
}

void serialDebuger(){
  if (Serial.available())
  {
    command = Serial.readStringUntil('\n');
  }
  if (command == "test")
  {
    Serial.println("test pass");
  }
  else if (command == "u")
  {
    menu.MenuUp();
    menu.UpdateMenu();
  }
    else if (command == "d")
  {
    menu.MenuDown();
    menu.UpdateMenu();
  }
      else if (command == "s")
  {
    menu.MenuSelect();
    menu.UpdateMenu();
  }
      else if (command == "refresh")
  {
    menu.UpdateMenu();
  }
  command = "";
}