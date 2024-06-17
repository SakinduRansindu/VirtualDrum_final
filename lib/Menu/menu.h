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
  static void DebugData();

  public:
Menu();
void MenuInit(Adafruit_SSD1306 *display);  
static void MenuUp();
static void MenuDown();
static void MenuSelect();
static void MenuBack();
void UpdateMenu();
int getSelectedIndex();
void MenuSetItem(char* displayName , void (*callback)(void) , int index =-1);

};

#endif