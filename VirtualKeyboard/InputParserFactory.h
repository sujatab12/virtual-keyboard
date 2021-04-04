#pragma once
#include "IInputKeyHandler.h"

class InputParserFactory {
public:
	template <class T = IInputKeyHandler>
	static IInputKeyHandler * GetParser() {
		return new T();
	}
};