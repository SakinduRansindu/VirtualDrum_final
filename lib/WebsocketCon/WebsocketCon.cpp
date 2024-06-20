#include <Arduino.h>
#include <WiFiClientSecure.h>
#include <WebSocketsClient.h>
#include <WiFi.h>
#include <WebSockets.h>
#include "WebsocketCon.h"
#include "WiFi_Pass.h"


#define RECALIBRATE_BTN 12

unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
WebSocketsClient  webSocket;

WebSocketCon::WebSocketCon() {
  // constructor
}


void WebSocketCon::setup_websocket() {
    webSocket.begin(server_ip, server_port, "/");
    // event handler
    webSocket.onEvent(webSocketEvent);
    // use HTTP Basic Authorization this is optional remove if not needed
    // webSocket.setAuthorization("user", "Password");
    webSocket.setReconnectInterval(1000);
}

void WebSocketCon::setup()
{
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  setup_websocket();

  
}



/* websocket functions */
void WebSocketCon::hexdump(const void *mem, uint32_t len, uint8_t cols) {
	const uint8_t* src = (const uint8_t*) mem;
	Serial.printf("\n[HEXDUMP] Address: 0x%08X len: 0x%X (%d)", (ptrdiff_t)src, len, len);
	for(uint32_t i = 0; i < len; i++) {
		if(i % cols == 0) {
			Serial.printf("\n[0x%08X] 0x%08X: ", (ptrdiff_t)src, i);
		}
		Serial.printf("%02X ", *src);
		src++;
	}
	Serial.printf("\n");
}

void WebSocketCon::webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
	switch(type) {
		case WStype_DISCONNECTED:
			Serial.printf("[WSc] Disconnected!\n");
			break;
		case WStype_CONNECTED:
			Serial.printf("[WSc] Connected to url: %s\n", payload);
			// send message to server when Connected
			webSocket.sendTXT("Connected:RightGlove");
			break;
		case WStype_TEXT:
			Serial.printf("[WSc] get text: %s\n", payload);

      // when we get msgs?

			// send message to server
			// webSocket.sendTXT("message here");
			break;
		case WStype_BIN:
			Serial.printf("[WSc] get binary length: %u\n", length);
			hexdump(payload, length);

			// send data to server
			// webSocket.sendBIN(payload, length);
			break;
		case WStype_ERROR:			
		case WStype_FRAGMENT_TEXT_START:
		case WStype_FRAGMENT_BIN_START:
		case WStype_FRAGMENT:
		case WStype_FRAGMENT_FIN:
			break;
	}

}

void WebSocketCon::sendMsg(String msg) {
  // send message to server
  webSocket.sendTXT(msg);
}

void WebSocketCon::loop()
{
      Serial.println("checkpoint0 in ws loop");
  webSocket.loop();
      Serial.println("checkpoint1 in ws loop");

  if (webSocket.isConnected()) {  //   

    currentMillis = millis();
    if (currentMillis - startMillis >=  5000) {
      
      Serial.println("checkpoint2 in ws loop");
      webSocket.sendTXT("play:drum2:10000");

      startMillis = currentMillis; 

    }
  }


      // Send message based on selected instrument
      // if (currentMillis - startMillis >= auto_play_drum_period_for_testing)  //test whether the period has elapsed, no need if flex trigger is used
      // {
      
      // // for recieving data from the server
      // if (client.available() > 0) {
        
      //   // for now print
      //   Serial.println(client.readStringUntil('\n'));
      // }

}