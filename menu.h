#ifndef MENU
#define MENU



#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

// Define button pins
#define buttonUp 18;
#define buttonDown 5;
#define buttonSelect 4;

class Menu{
  private:
  Adafruit_SSD1306 display;
  void item1Action();
  void item2Action();
  void item3Action();
  void item4Action();
  static void test();

  public:
Menu();
void MenuInit(Adafruit_SSD1306 *display);  
void MenuUp();
void MenuDown();
void MenuSelect();
void UpdateMenu();
void MenuSetItem(char* displayName , void (*callback)(void) , int index =-1);

};

#endif