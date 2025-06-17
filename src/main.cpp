#include <SPI.h>
#include <SD.h>
#include <WiFi.h>
#include <time.h>

#define SD_CS 5

//define time NTP
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 25200;  // GMT+7
const int   daylightOffset_sec = 0;

// Variable get time
String currentTimeString;

// define wifi ssid and password
const char* ssid = "vanha2301";
const char* password = "123456789";

void getFormattedTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Không lấy được thời gian");
    currentTimeString = "Lỗi thời gian";
    return;
  }

  char timeStr[30];
  strftime(timeStr, sizeof(timeStr), "%A, %d/%m/%Y %H:%M:%S", &timeinfo);
  currentTimeString = String(timeStr);
}

void setup() {
  Serial.begin(115200);

  // connect wifi 
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Setup NTP
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  // delay 
  delay(1000);

  getFormattedTime();
  Serial.println(currentTimeString);

  // connect wifi end.

  // create SD card
  if (!SD.begin(SD_CS)) {
    Serial.println("Không thể khởi động thẻ SD!");
    return;
  }
  Serial.println("Đã kết nối thẻ SD thành công.");

  File file = SD.open("/test.txt");
  if (file) {
    Serial.println("Đang đọc file test.txt:");
    while (file.available()) {
      Serial.write(file.read());
    }
    file.close();
  } else {
    Serial.println("Không mở được file.");
  }

}

void loop() {

}
