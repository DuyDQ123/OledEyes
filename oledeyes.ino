#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Kích thước mắt
int eyeWidth = 20;
int eyeHeight = 20;

// Tọa độ mắt
int leftEyeX = 30;
int rightEyeX = 78;
int eyeY = 22;

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 không khởi động được!"));
    while (true);
  }

  display.clearDisplay();
  display.display();
}

void loop() {
  display.clearDisplay();

  // Màu mặt cười: Mình fillRect 2 hình vuông bo góc
  display.fillRoundRect(leftEyeX, eyeY, eyeWidth, eyeHeight, 5, SSD1306_WHITE);
  display.fillRoundRect(rightEyeX, eyeY, eyeWidth, eyeHeight, 5, SSD1306_WHITE);

  display.display();

  delay(1000); // giữ nguyên 1 giây

  // Biểu cảm khác: Ví dụ "buồn" - mắt thu nhỏ lại
  display.clearDisplay();
  display.fillRoundRect(leftEyeX, eyeY + 5, eyeWidth, eyeHeight / 2, 5, SSD1306_WHITE);
  display.fillRoundRect(rightEyeX, eyeY + 5, eyeWidth, eyeHeight / 2, 5, SSD1306_WHITE);

  display.display();

  delay(1000); // giữ nguyên 1 giây

  // Biểu cảm khác: Ví dụ "hạnh phúc" - mắt mở to
  display.clearDisplay();
  display.fillRoundRect(leftEyeX, eyeY - 2, eyeWidth, eyeHeight + 5, 5, SSD1306_WHITE);
  display.fillRoundRect(rightEyeX, eyeY - 2, eyeWidth, eyeHeight + 5, 5, SSD1306_WHITE);

  display.display();

  delay(1000); // giữ nguyên 1 giây
}
