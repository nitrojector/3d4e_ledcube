#pragma once

#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

#define R1_PIN 4
#define G1_PIN 5
#define B1_PIN 6
#define R2_PIN 7
#define G2_PIN 15
#define B2_PIN 16
#define A_PIN 18
#define B_PIN 8
#define C_PIN 3
#define D_PIN 42
#define E_PIN 17
#define LAT_PIN 40
#define OE_PIN 2
#define CLK_PIN 41

#define PANEL_RES_X 64 // Number of pixels wide of each INDIVIDUAL panel module.
#define PANEL_RES_Y 32 // Number of pixels tall of each INDIVIDUAL panel module.
#define PANEL_CHAIN 1  // Total number of panels chained one to another

class CPanel {
  public:
	static void init();
	static void test();

	static MatrixPanel_I2S_DMA* display;
};