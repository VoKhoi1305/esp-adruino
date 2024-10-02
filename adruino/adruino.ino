#include <DHT.h>

#define DHTPIN 2      // Chân D2 kết nối với DATA của DHT21
#define DHTTYPE DHT11 // Loại cảm biến DHT21

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // Khởi tạo Serial giao tiếp với ESP32 qua UART
  dht.begin();        // Khởi tạo cảm biến DHT
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Kiểm tra lỗi khi đọc dữ liệu từ cảm biến
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Gửi dữ liệu qua UART tới ESP32
  Serial.print("T:");
  Serial.print(temperature);
  Serial.print(",H:");
  Serial.println(humidity);

  delay(2000); // Đọc dữ liệu mỗi 2 giây
}
