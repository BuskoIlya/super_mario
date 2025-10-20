#pragma once

#include <vector>

#include "collisionable.hpp"
#include "map_movable.hpp"
#include "movable.hpp"
#include "rect.hpp"

namespace biv {
	class Game {
		private:
			std::vector<Collisionable*> collisionable_objs;
			std::vector<MapMovable*> map_movable_objs;
			std::vector<Movable*> movable_objs;
			std::vector<Rect*> ships;
			
		public:
			Game();
			
			void add_collisionable(Collisionable*);
			void add_map_movable(MapMovable*);
			void add_movable(Movable*);
			void add_ship(Rect*);
			
			void check_ships_collisions() noexcept;
			
			void move_map_left() noexcept;
			void move_map_right() noexcept;
			void move_objs_vertically() noexcept;
	};
}
