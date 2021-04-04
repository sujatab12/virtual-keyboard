// VirtualKeyboard.cpp : This file contains the 'main' function. Program execution begins and ends there.
// C++ implementation for virtual keyboard functionality.
// Input text is captured by parsing the keystroke events.
// Implementation is Windows specific and uses windows events/msgs to identify the key strokes.
// Function keys are not handled.
// Press Ctrl q to exit the application
//

#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include "IInputStore.h"
#include "IInputKeyHandler.h"
#include "InMemInputStore.h"
#include "InputParserFactory.h"
#include "InputKeyParser.h"


int main()
{
	std::unique_ptr<IInputStore> InputStore(new InMemInputStore());
	std::unique_ptr<IInputKeyHandler> InputParser(InputParserFactory::GetParser<InputKeyParser>());

	std::cout << "Virtual Keyboard session start..." << std::endl;

	while (1) {
		DWORD        mode;
		INPUT_RECORD event;
		BOOL con = TRUE;
		DWORD count;

		// Get the console input handle 
		HANDLE hStdInput1 = GetStdHandle(STD_INPUT_HANDLE);

		// Preserve the original console mode
		GetConsoleMode(hStdInput1, &mode);

		// Set to no line-buffering, no echo
		SetConsoleMode(hStdInput1, 0);

		int leftCount = 0;
		// read and parse the key strokes till enter is pressed
		while (con) {
			ReadConsoleInput(hStdInput1, &event, 1, &count);
			int k = InputParser->parseKeyInput(InputStore, event, leftCount);
			if (k == 0)	return 0;
			else if (k == 1) con = FALSE;
		}

		//Set console mode to original
		SetConsoleMode(hStdInput1, mode);

		//print the input text
		std::cout << InputStore->getValue() << std::endl;

		InputStore->clear();
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
