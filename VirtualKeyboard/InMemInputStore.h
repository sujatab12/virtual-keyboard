#pragma once
#include <iostream>
#include "IInputStore.h"
class InMemInputStore : public IInputStore {

	std::string str;

public:
	InMemInputStore() :str("") {}

	void append(char a);

	void clear();

	void insert(int pos, char a);

	std::string getValue();

};