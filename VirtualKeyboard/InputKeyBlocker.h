#pragma once

#include "IInputKeyHandler.h"

class InputKeyBlocker : public IInputKeyHandler {
public:
	int parseKeyInput(std::unique_ptr<IInputStore> &InStore, INPUT_RECORD &event, int &leftCount);

};