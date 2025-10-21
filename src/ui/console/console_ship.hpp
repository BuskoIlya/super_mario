#pragma once

#include "console_ui_obj.hpp"
#include "ship.hpp"

namespace biv {
	class ConsoleShip : public Ship, public ConsoleUIObject {
		public:
			ConsoleShip(const Coord& top_left, const int width, const int height);
			
			int get_bottom() const noexcept override;
			char get_brush() const noexcept override;
			int get_height() const noexcept override;
			int get_left() const noexcept override;
			int get_right() const noexcept override;
			int get_top() const noexcept override;
	};
}
