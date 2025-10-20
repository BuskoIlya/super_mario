#pragma once

#include "console_ui_obj.hpp"
#include "mario.hpp"

namespace biv {
	class ConsoleMario : public Mario, public ConsoleUIObject {
		public:
			ConsoleMario(const Coord& top_left, const int width, const int height);
			
			virtual int get_bottom() const noexcept override;
			virtual char get_brush() const noexcept override;
			virtual int get_height() const noexcept override;
			virtual int get_left() const noexcept override;
			virtual int get_right() const noexcept override;
			virtual int get_top() const noexcept override;
	};
}
