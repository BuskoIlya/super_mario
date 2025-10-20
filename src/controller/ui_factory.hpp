#pragma once

#include "game.hpp"
#include "game_map.hpp"
#include "mario.hpp"

namespace biv {
	class UIFactory {
		public:
			virtual void create_game_data(Game* game) = 0;
			virtual GameMap* get_game_map() = 0;
			virtual Mario* get_mario() = 0;
	};
}
