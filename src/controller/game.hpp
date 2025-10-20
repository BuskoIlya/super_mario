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
			std::vector<Rect*> static_objs;
			
		public:
			Game();
			
			void add_collisionable(Collisionable*);
			void add_map_movable(MapMovable*);
			void add_movable(Movable*);
			void add_ship(Rect*);
			
			void check_horizontally_static_collisions() noexcept;
			void check_vertically_static_collisions() noexcept;
			bool check_static_collisions(Collisionable* obj) const noexcept;
			
			void move_map_left() noexcept;
			void move_map_right() noexcept;
			void move_objs_horizontally() noexcept;
			void move_objs_vertically() noexcept;
	};
}
