#include <ESP8266WiFi.h>
#define WIFI_SSID "SSID"
#define WIFI_PASS "PASSWORD"
#define BOT_TOKEN "TOKEN"
#define ID "ID"

#include <FastBot.h>
FastBot bot(BOT_TOKEN);

void setup() {
  pinMode(16, INPUT);
  pinMode(5, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
}

void loop() {
  int dry = digitalRead(16);
  delay(1000);
  if (WiFi.status() != WL_CONNECTED) {
    if (dry == 0) {
      tone (5,  500,  1000);
      delay(5000);
    }
  }
  else {
    if (dry == 0) {
    tone (5,  500,  1000);
    bot.sendMessage("Где-то протечка", ID);
    delay(100000);
  }
  
  }
}
