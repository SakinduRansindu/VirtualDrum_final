#ifndef PIEZO
#define PIEZO

#define SENSOR_COUNT 4

#define PIEZO1_PIN 34
#define PIEZO2_PIN 35
#define PIEZO3_PIN 36
#define PIEZO4_PIN 39

class Piezo{

    private:
        long LastTriggeredTime[SENSOR_COUNT];
        int LastReadValue[SENSOR_COUNT];
        int triggerLevel;
        void SendSerialTrigerSignal(int sensorId, int reading);

    public:
        Piezo();
        int ReadPiezoInput(short c);
        void loop();


};

#endif