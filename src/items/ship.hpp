#pragma once

#include "map_movable.hpp"
#include "rect.hpp"
#include "uiobject.hpp"

namespace biv {
	class Ship : public UIObject, public MapMovable {
		public:
			Ship(const Rect& rect);
			
			char get_brush() const noexcept override;
			void move_map_left() noexcept override;
			void move_map_right() noexcept override;
	};
}
