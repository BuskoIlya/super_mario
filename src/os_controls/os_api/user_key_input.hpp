#pragma once

namespace biv {
	namespace os {
		enum class UserKeyInput {
			EXIT,
			MAP_LEFT,
			MAP_RIGHT,
			MARIO_JUMP,
			NO_INPUT
		};
	
		UserKeyInput get_user_key_input();
	}
}
