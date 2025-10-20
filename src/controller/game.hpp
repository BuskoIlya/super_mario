#pragma once

#include <vector>

#include "map_movable.hpp"

namespace biv {
	class Game {
		private:
			std::vector<MapMovable*> map_movable_objs;
			
		public:
			Game();
			
			void add_map_movable(MapMovable*);
			void move_map_left() noexcept;
			void move_map_right() noexcept;
	};
}
