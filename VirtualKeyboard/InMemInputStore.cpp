#include "pch.h"
#include "InMemInputStore.h"

	void InMemInputStore::append(char a) {
		str += a;
	}

	void InMemInputStore::clear() {
		str.clear();
	}

	void InMemInputStore::insert(int pos, char a) {
		auto it = str.end();
		for (int i = 0; i < pos; i++) {
			it--;
		}
		str.insert(it, a);
	}

	std::string InMemInputStore::getValue() {
		return str;
	}
