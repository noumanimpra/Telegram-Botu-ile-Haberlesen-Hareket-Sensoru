#include <deneyap.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <WiFi.h>

// Bağlanacağınız WiFi bilgileri. 
const char* ssid = "WIFI ADI";
const char* password = "WIFI SIFRE";
const int led = D10;
const int pir = D9;

int hareket;

// Telegram BOT bilgileri. 
#define BOTtoken "00000000000000000000000000000000000000" // Telegram uygulaması üzerinden Botfather ile öğreneceğiz. Burayı değiştirmeyi unutmayın.
#define CHAT_ID "00000000000" // idbot ile telegram ID'sini öğrenerek buraya yazacağız.Burayı değiştirmeyi unutmayın.

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
  
  Serial.begin(115200);
  
  client.setInsecure();
  Serial.print("İnternete bağlanıyor: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi bağlandı");
  Serial.print("IP adresi: ");
  Serial.println(WiFi.localIP());
  bot.sendMessage(CHAT_ID, "Cihaz aktif oldu.", "");
}
void loop() {
hareket = digitalRead(pir);
  if(hareket == HIGH){
    digitalWrite(led, HIGH);
    Serial.print("1");
    bot.sendMessage(CHAT_ID, "hareket algilandi");
  }
  else{
    digitalWrite(led, LOW);
    Serial.print("0");
}
Serial.println("G");
//delay(1000); 
}
