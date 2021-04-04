#pragma once

#include <iostream>
#include "IInputStore.h"
#include <Windows.h>

class IInputKeyHandler {
public:
	virtual int parseKeyInput(std::unique_ptr<IInputStore> &InStore, INPUT_RECORD &event, int &leftCount) = 0;
};