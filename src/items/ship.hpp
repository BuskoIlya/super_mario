#pragma once

#include "rect.hpp"
#include "uiobject.hpp"

namespace biv {
	class Ship : public UIObject {
		public:
			Ship(const Rect& rect);
			
			char get_brush() const noexcept override;
	};
}
