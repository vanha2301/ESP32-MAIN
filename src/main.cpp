#include <SPI.h>
#include <SD.h>

#define SD_CS 5

void setup() {
  Serial.begin(112500);
  
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
//hocbus
