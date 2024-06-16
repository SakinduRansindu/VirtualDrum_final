#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "metronome.h"

// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//int timer = 0;           // The higher the number, the slower the timing.
//int bpm = 0;


int ledState = LOW; // Tracks the state of the LED
unsigned long previousMillis = 0; // Stores the last time LED was updated
float interval = 0; // Interval between LED toggles based on BPM

int bpm = 120; // Initial BPM
int ledOnrate=50;

bool lastIncButtonState = LOW; // Variable to store the previous state of the increase button
bool lastDecButtonState = LOW; // Variable to store the previous state of the decrease button
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
// unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers


Metronome::Metronome(){
 
}

void Metronome::MetronomeInit(Adafruit_SSD1306 *d) {
   display = *d;
// Serial.begin(9600);
  // use a for loop to initialize each pin as an output:
  // display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
}

bool isRunning = false;
bool isOpened = false;
void Metronome::Start(){
  isRunning = true;
}
void Metronome::Stop(){
  isRunning = false;
}

void Metronome::Open(){
  isOpened = true;
}

void Metronome::UpdateMetronome() {
  if(isOpened){
  interval = 60000000 / bpm;
  // Check if it's time to toggle the LED
  unsigned long currentMillis = micros();
  if (currentMillis - previousMillis >= interval) {
    // Save the last time the LED was toggled
    previousMillis += interval;
    // Toggle the LED state
    ledState = !ledState;
    // Update the LED
    digitalWrite(LED_PIN, ledState);
  }
  
 //Serial.println(bpm);
 UpdateDisplay();
  }
 
}

void Metronome::UpdateDisplay(){
    display.clearDisplay();   
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(35,5);
    display.println("BPM:");
    display.setCursor(15,40);
    display.println(bpm);
    display.setTextSize(2);
    display.setCursor(73,45);
    display.println("/min");
    display.display();
}


void Metronome::MetronomeUp(){
      if (bpm < MAX_BPM) {
        bpm++;
        Serial.println(bpm);
      }
}

void Metronome::MetronomeDown(){
      if (bpm > MIN_BPM) {
        bpm--;
        Serial.println(bpm);
      }
}
