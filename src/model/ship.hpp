#pragma once

#include "map_movable.hpp"
#include "rect.hpp"

namespace biv {
	class Ship : public Rect, public MapMovable {
		public:
			Ship(const Coord& top_left, const int width, const int height);
			
			void move_map_left() noexcept override;
			void move_map_right() noexcept override;
	};
}
