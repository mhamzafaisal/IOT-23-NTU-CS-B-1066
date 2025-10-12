#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Wire.begin(21, 22); // SDA=21, SCL=22 for ESP32

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    for (;;); // Stop if display not found
  }

  display.clearDisplay();

  // ---- Text and Box ----
  display.setTextSize(1);              
  display.setTextColor(SSD1306_WHITE);

  // Draw rectangle first (centered box)
  display.drawRect(10, 10, 108, 44, SSD1306_WHITE);

  // Place text neatly inside the box
  display.setCursor(25, 22);
  display.println("M. HAMZA");
  display.setCursor(25, 34);  // Manual control of next line
  display.println("23-NTU-CS-1066");

  // Display all on OLED
  display.display();
}

void loop() {
  // Nothing here
}
