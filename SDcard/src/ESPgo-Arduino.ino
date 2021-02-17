#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "BluetoothSerial.h"

const char* ssid = "yourSSID"; // WiFi network name
const char* password = "yourPASSWORD"; // WiFi password

void yourSetup(){
  // runs very much like the normal setup function, just keeps things separate from firmware
}

void yourLoop(){
  // runs very much like the normal loop function, just keeps things separate from firmware
}

///////////////////////////////////////////////////////////////////////////////
/////////////////// ESPgo-Infinity's firmware resides below ///////////////////
// DO NOT MODIFY ANYTHING BELOW THIS LINE UNLESS YOU KNOW WHAT YOU'RE DOING  //
///////////////////////////////////////////////////////////////////////////////

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

bool get_ssid;
bool get_pass;
uint16_t port;
uint8_t conn_count = 0;

void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param){
  if(event == ESP_SPP_SRV_OPEN_EVT){
    if(digitalRead(0) == HIGH){
      SerialBT.println("****************************************");
      SerialBT.println("Welcome to ESPgo-Infinity for Arduino");
      SerialBT.println("        A Product of Defiance Digital        ");
      SerialBT.println("****************************************");
      SerialBT.print("WiFi OTA Mode: ");
      if(WiFi.status() == WL_CONNECTED){
        SerialBT.println("Online");
        SerialBT.print("WiFi OTA IP: "); SerialBT.println(WiFi.localIP());
        SerialBT.print("WiFi OTA Port: "); SerialBT.println(port);
      } else {
        SerialBT.println("Offline");
        SerialBT.print("Enter "); SerialBT.print("'"); SerialBT.print("~"); SerialBT.print("'"); SerialBT.println(" at any time for one-time OTA");
      }
    }
    Serial.println("Client Connected");
    pinMode(18, OUTPUT);
    digitalWrite(18, LOW);
    delay(50);
    pinMode(18, INPUT_PULLUP);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(0, INPUT_PULLUP);
  SerialBT.begin("Infinity-BT");
  SerialBT.register_callback(callback); 
  WiFi.mode(WIFI_STA);
  WiFi.onEvent(WiFiConnected, SYSTEM_EVENT_STA_CONNECTED);
  WiFi.onEvent(WiFiDisconnected, SYSTEM_EVENT_STA_DISCONNECTED);
  WiFi.begin(ssid, password);
  yourSetup();
}

void loop() {
  if(digitalRead(0) == LOW){
    while(digitalRead(0) == LOW){
      if (Serial.available()) {
        SerialBT.write(Serial.read());
      }
      if (SerialBT.available()) {
        Serial.write(SerialBT.read());
      }
    }
  } else {
    if (Serial.available()) {
      SerialBT.write(Serial.read());
    }
    if(SerialBT.available()) {
      if(SerialBT.peek() == '~'){
        SerialBT.read();
        if(SerialBT.available()){
          if(SerialBT.peek() == '\r'){
           oneTimeOTA();
          } else
          if(SerialBT.peek() == '\n'){
            oneTimeOTA();
          } else {
            Serial.write("~");
            while(SerialBT.available()){
              Serial.write(SerialBT.read());
            }
          }
        } else {
          oneTimeOTA();
        }
      } else {
        Serial.write(SerialBT.read());
      }
    }
    ArduinoOTA.handle();
    yourLoop();
  }
}

void startOTA(){
  // Port defaults to 3232
  port = 3232;
  ArduinoOTA.setPort(port);

  // Hostname defaults to esp3232-[MAC]
  ArduinoOTA.setHostname("ESPgo-Infinity");

  // No authentication by default
  // ArduinoOTA.setPassword("admin");
  ArduinoOTA
      .onStart([]() {
        String type;
        if (ArduinoOTA.getCommand() == U_FLASH)
          type = "sketch";
        else // U_SPIFFS
          type = "filesystem";

        // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
        SerialBT.println("OTA Update Started");
      })
      .onEnd([]() {
        SerialBT.println("OTA Update Complete");
        delay(500);
        SerialBT.println("Resetting...");
      })
      .onProgress([](unsigned int progress, unsigned int total) {
        SerialBT.printf("OTA Update Progress: %u%%\r", (progress / (total / 100)));
        SerialBT.println();
      })
      .onError([](ota_error_t error) {
        SerialBT.printf("Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR) SerialBT.println("OTA Auth Failed");
        else if (error == OTA_BEGIN_ERROR) SerialBT.println("OTA Begin Failed");
        else if (error == OTA_CONNECT_ERROR) SerialBT.println("OTA Connect Failed");
        else if (error == OTA_RECEIVE_ERROR) SerialBT.println("OTA Receive Failed");
        else if (error == OTA_END_ERROR) SerialBT.println("OTA Update Failed");
      });
  ArduinoOTA.begin();
  while(WiFi.localIP().toString() == "0.0.0.0"){}
  SerialBT.println("WiFi OTA Mode: Online");
  SerialBT.print("WiFi OTA IP: "); SerialBT.println(WiFi.localIP());
  SerialBT.print("WiFi OTA Port: "); SerialBT.println(port);
}

void WiFiConnected(WiFiEvent_t event, WiFiEventInfo_t info){
  if(digitalRead(0) == HIGH){
    SerialBT.print("Connected to ");
    for(int i=0; i<info.connected.ssid_len; i++){
      SerialBT.print((char) info.connected.ssid[i]);
    }
    SerialBT.println();
    conn_count = 0;
    startOTA();
  }  
}

void WiFiDisconnected(WiFiEvent_t event, WiFiEventInfo_t info){
  if(digitalRead(0) == HIGH){
    if(conn_count == 0){
      SerialBT.print("Connection to ");
      for(int i=0; i<info.connected.ssid_len; i++){
        SerialBT.print((char) info.connected.ssid[i]);
      }
      SerialBT.println(" was lost!");
      SerialBT.println("WiFi OTA Mode: Offline");
      SerialBT.println("Attempting to re-establish connection...");
      WiFi.begin(ssid, password);
      conn_count = 1;
    }
  }
}

void oneTimeOTA(){
  while(SerialBT.available()){
    SerialBT.read(); // Clear it
  }
  get_ssid = true;
  get_pass = true;
  String ssid_string;
  String password_string;
  SerialBT.println("Enter WiFi SSID (network name)");
  while(get_ssid == true){
    if (SerialBT.available()){
      ssid_string = SerialBT.readStringUntil('\n');
      if(ssid_string.charAt(ssid_string.length()-1) == '\r'){
        ssid_string = ssid_string.substring(0,(ssid_string.length()-1));
      }
      get_ssid = false;
    }
  }
  SerialBT.println("Enter WiFi Password");
  while(get_pass == true){
    if (SerialBT.available()){
      password_string = SerialBT.readStringUntil('\n');
      if(password_string.charAt(password_string.length()-1) == '\r'){
        password_string = password_string.substring(0,(password_string.length()-1)); 
      }
      get_pass = false;
    }
  }
  WiFi.begin(ssid_string.c_str(), password_string.c_str());
  SerialBT.println("Attempting Temporary Connection...");
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    if(WiFi.status() != WL_CONNECTED){
      SerialBT.println("Failed to connect");
      SerialBT.print("Reply with "); SerialBT.print('"'); SerialBT.print("~"); SerialBT.print('"'); SerialBT.println(" to try again");
      return;
    }
  }
}
