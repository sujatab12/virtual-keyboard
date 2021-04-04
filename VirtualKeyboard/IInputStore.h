#pragma once
#include <iostream>

class IInputStore {
public:
	virtual void clear() = 0;
	virtual void append(char a) = 0;
	virtual void insert(int pos, char a) = 0;
	virtual std::string getValue() = 0;
};
