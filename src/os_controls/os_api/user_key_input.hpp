#pragma once

namespace biv {
	namespace os {
		enum class UserKeyInput {
			MAP_LEFT,
			MAP_RIGHT,
			EXIT,
			NO_INPUT
		};
	
		UserKeyInput get_user_key_input();
	}
}
