#ifndef WEBSOCKETCON
#define WEBSOCKETCON

class WebSocketCon{

    WiFiClient wiFiClient;
    WebSocketsClient  webSocket;

    private:
        void setup_websocket();
        void hexdump(const void *mem, uint32_t len, uint8_t cols = 16);
        void webSocketEvent(WStype_t type, uint8_t * payload, size_t length);

    public:
        void setup();
        void loop();
        void sendMsg(String msg);
};

#endif