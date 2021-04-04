#include "pch.h"
#include "InputKeyBlocker.h"

int InputKeyBlocker::parseKeyInput(std::unique_ptr<IInputStore> &InStore, INPUT_RECORD &event, int &leftCount) {
	std::cout << "Virtual Key Blocker Session..." << std::endl;
	std::cout << "Some handling to block certain keys/key combinations" << std::endl;
	return 0;
}