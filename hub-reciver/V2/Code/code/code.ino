#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9488.h>

// Display Pins
#define TFT_CS   5
#define TFT_DC   6
#define TFT_RST  7

Adafruit_ILI9488 tft(TFT_CS, TFT_DC, TFT_RST);

// Define some colors
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0
#define WHITE    0xFFFF
#define ORANGE   0xFD20
#define PURPLE   0x8010
#define PINK     0xFE19
#define GRAY     0x8410
#define LIME     0x07E0
#define TEAL     0x0410
#define NAVY     0x000F
#define MAROON   0x7800
#define OLIVE    0x7BE0
#define AQUA     0x5D1C
#define SILVER   0xC618
#define GOLD     0xFEA0
#define BEIGE    0xF7BB
#define LAVENDER 0xE73F
#define TAN      0xD5B1
#define LIGHTBLUE 0x7D7C
#define DARKGREEN 0x03E0
#define BROWN    0x9C00
#define DARKGRAY 0x7BEF
#define LIGHTGRAY 0xC618
#define LIGHTGREEN 0x87F0
#define DARKRED  0x8800
#define DARKCYAN 0x03EF
#define LIGHTPURPLE 0xE5FF
#define DARKORANGE 0xFC00

// Array for colors for the grid
uint16_t colors[30] = {
  RED, GREEN, BLUE, YELLOW, MAGENTA,
  CYAN, ORANGE, PURPLE, PINK, GRAY,
  LIME, TEAL, NAVY, MAROON, OLIVE,
  AQUA, SILVER, GOLD, BEIGE, LAVENDER,
  TAN, LIGHTBLUE, DARKGREEN, BROWN, DARKGRAY,
  LIGHTGRAY, LIGHTGREEN, DARKRED, DARKCYAN, LIGHTPURPLE
};

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(3); // rotation as needed
  tft.fillScreen(BLACK);

  int cellWidth = tft.width() / 5;
  int cellHeight = tft.height() / 6;

  for (int row = 0; row < 6; row++) {
    for (int col = 0; col < 5; col++) {
      int index = row * 5 + col;
      tft.fillRect(col * cellWidth, row * cellHeight, cellWidth, cellHeight, colors[index]);
    }
  }
}

void loop() {
  // static display doesnt need to loop anything
}
