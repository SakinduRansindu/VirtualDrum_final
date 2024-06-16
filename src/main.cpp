#include <Battery.h>
#include <Adafruit_SSD1306.h>
#include "menu.h"
#include "metronome.h"
#include "Handler.h"



#define SENSE_PIN 32
#define ACTIVATION_PIN 33
#define ADC_RESOLUTION 12

#define WINDOW_MENU 0
#define WINDOW_METRONOME 1

short currentWindow = WINDOW_MENU;

String command;
Battery batt = Battery(3300, 4200, SENSE_PIN, ADC_RESOLUTION);
Menu menu = Menu();
Metronome metronome = Metronome();
Handler handler = Handler();
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

  void item1Action();
  void item2Action();
  void item3Action();
  void item4Action();
 void serialDebuger();
 void test();

void setup() {

  Serial.begin(115200);
  
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(22,10);
  display.println("Group27");
  display.setCursor(30,40);
  display.println("Drum");
  display.display();
  delay(2000);

  Serial.print("max volt: ");
  Serial.println(batt.level(4200));
  Serial.print("min volt: ");
  Serial.println(batt.level(3300));
  analogReadResolution(ADC_RESOLUTION);
  batt.onDemand(ACTIVATION_PIN, HIGH);
  batt.begin(5000, 1, &asigmoidal);

  menu.MenuInit(&display);
  menu.MenuSetItem("Metronome",&metronome.Open);
  menu.MenuSetItem("Battery",&item2Action);
  menu.MenuSetItem("Reset",&item3Action);
  menu.MenuSetItem("Exit",&item4Action);

  // Handler handler = Handler(test,test,test,test);
  handler.setFucnctions(menu.MenuUp,menu.MenuDown,menu.MenuSelect, menu.MenuBack);


  metronome.MetronomeInit(&display);

}

void loop(){
    serialDebuger();
    metronome.UpdateMetronome();
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
  bool isExecuted = true;
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
    // menu.MenuUp();
    // menu.UpdateMenu();
    handler.Up();
  }
    else if (command == "d")
  {
    // menu.MenuDown();
    // menu.UpdateMenu();
    handler.Down();
  }
      else if (command == "s")
  {
    // menu.MenuSelect();
    // menu.UpdateMenu();
    handler.Select();
  }
    else if (command == "refresh")
  {
    menu.UpdateMenu();
  }
  else
  {
    isExecuted = false;
  }
  if (isExecuted)
  {
    if(currentWindow == WINDOW_MENU){
      menu.UpdateMenu();
    }
    
  }
  
  command = "";
}