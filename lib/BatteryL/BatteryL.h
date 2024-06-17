#ifndef BATTERYL
#define BATTERYL

class BatteryL{

private:
    Adafruit_SSD1306 display;
    int battery1Level;
    int battery2Level;

public:
    BatteryL(int b1Level, int b2Level);
    void BatteryInit(Adafruit_SSD1306 *d);
    void UpdateDisplay();
    void setBattery1Level(int level);
    void setBattery2Level(int level);
    int getBattery1Level();
    int getBattery2Level();

};


#endif