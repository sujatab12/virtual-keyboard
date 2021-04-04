#include "pch.h"
#include "InputKeyParser.h"

int InputKeyParser::parseKeyInput(std::unique_ptr<IInputStore> &InStore, INPUT_RECORD &event, int &leftCount) {

	if ((event.EventType == KEY_EVENT) && !event.Event.KeyEvent.bKeyDown) {

		switch (event.Event.KeyEvent.wVirtualKeyCode)
		{
		case VK_SHIFT:
		case VK_CAPITAL:
		case VK_END:
		case VK_HOME:
		case VK_UP:
		case VK_DOWN:
		case VK_CONTROL:
		case VK_ESCAPE:
			break;

		case VK_LEFT:
			leftCount++;
			break;

		case VK_RIGHT:
			if (leftCount)		leftCount--;
			break;

		case VK_RETURN:
			return 1;
			break;

		case 0x51:
			if (GetKeyState(VK_CONTROL) & 0x8000) {
				return 0;
			}
		default:
			if (leftCount)
				InStore->insert(leftCount, event.Event.KeyEvent.uChar.AsciiChar);
			else
				InStore->append(event.Event.KeyEvent.uChar.AsciiChar);
		}

	}
	return 2;
}