#include "user_key_input.hpp"

#include <windows.h>

using biv::os::UserKeyInput;

UserKeyInput biv::os::get_user_key_input() {
	if (GetKeyState('A') < 0) {
		return UserKeyInput::MAP_RIGHT;
	} else if (GetKeyState('D') < 0) {
		return UserKeyInput::MAP_LEFT;
	} else if (GetKeyState(VK_ESCAPE) < 0) {
		return UserKeyInput::EXIT;
	} else {
		return UserKeyInput::NO_INPUT;
	}
}
