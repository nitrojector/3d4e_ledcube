#include "panel.hpp"
#include "util.hpp"

void setup() {
	CPanel::init();
	Serial.begin(115200);
	Serial.println("Done");
	CPanel::test();
}

void loop() {
}