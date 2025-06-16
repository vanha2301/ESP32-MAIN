#include <SPI.h>
#include <SD.h>
#include <WiFi.h>

#define SD_CS 5

// define wifi ssid and password
const char* ssid = "vanha2301";
const char* password = "123456789";

void setup() {
  Serial.begin(112500);
  
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

void loop() {}
