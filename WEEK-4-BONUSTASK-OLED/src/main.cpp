#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for (;;);
  }
  display.clearDisplay();

  // Heart shape using circles + triangle
  display.fillCircle(54, 25, 6, SSD1306_WHITE);
  display.fillCircle(74, 25, 6, SSD1306_WHITE);
  display.fillTriangle(48, 28, 80, 28, 64, 55, SSD1306_WHITE);

  // Text below
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(45, 58);
  display.println("My Heart <3");

  display.display();
}

void loop() {}