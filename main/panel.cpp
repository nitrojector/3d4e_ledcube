#include "panel.hpp"

MatrixPanel_I2S_DMA* CPanel::display = nullptr;

void CPanel::init() {
	HUB75_I2S_CFG::i2s_pins _pins = {R1_PIN,
									 G1_PIN,
									 B1_PIN,
									 R2_PIN,
									 G2_PIN,
									 B2_PIN,
									 A_PIN,
									 B_PIN,
									 C_PIN,
									 D_PIN,
									 E_PIN,
									 LAT_PIN,
									 OE_PIN,
									 CLK_PIN};

	HUB75_I2S_CFG mxconfig(PANEL_RES_X, // module width
						   PANEL_RES_Y, // module height
						   PANEL_CHAIN, // Chain length
						   _pins		// Pin mapping
	);

	mxconfig.clkphase = false;

	mxconfig.latch_blanking = 4;
	mxconfig.i2sspeed = HUB75_I2S_CFG::HZ_10M;

	display = new MatrixPanel_I2S_DMA(mxconfig);

	display->begin();
	display->setBrightness8(120); // 0-255
	display->clearScreen();
}

void CPanel::test() {
	const char* msg0 = "3D";
	const char* msg1 = "4E";
	uint16_t bg = display->color565(50, 192, 203);
	uint16_t myColor = display->color565(255, 40, 0);
	display->fillScreen(bg);

	display->setTextSize(2);
	display->setTextWrap(false);

	display->setTextColor(myColor);
	display->setCursor(10, 1);
	display->print(msg0);
	display->setCursor(10, 17);
	display->print(msg1);

	display->drawFastVLine(61, 0, 32, myColor);
	display->drawFastVLine(60, 0, 32, myColor);
}
