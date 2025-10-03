#pragma once

#include "rect.hpp"

namespace biv {
	class UIObject : public Rect {
		protected:
			UIObject(const Rect& rect) : Rect(rect) {}

		public:
			virtual char get_brush() const noexcept = 0;
	};
}
