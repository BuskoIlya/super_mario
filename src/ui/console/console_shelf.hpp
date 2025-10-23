#pragma once

#include "console_ui_obj_rect_adapter.hpp"
#include "shelf.hpp"

namespace biv {
	class ConsoleShelf : public Shelf, public ConsoleUIObjectRectAdapter {
		public:
			ConsoleShelf(const Coord& top_left, const int width, const int height);
			
			char get_brush() const noexcept override;
	};
}
