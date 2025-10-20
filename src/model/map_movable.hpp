#pragma once

namespace biv {
	class MapMovable {
		protected: 
			static const int MAP_STEP = 1;

		public:
			virtual void move_map_left() noexcept = 0;
			virtual void move_map_right() noexcept = 0;
	};
}
