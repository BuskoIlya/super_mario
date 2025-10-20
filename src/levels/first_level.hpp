#pragma once

#include "game.hpp"
#include "game_level.hpp"
#include "game_map.hpp"

namespace biv {
	class FirstLevel : public GameLevel {
		public:
			FirstLevel(Game* game, GameMap* game_map);
			
			GameLevel* get_next() override;
			
		private:
			void init_data() override;
	};
}
