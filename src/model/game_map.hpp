#pragma once

namespace biv {
	class GameMap {
		public:
			virtual void clear() noexcept = 0;
			virtual void refresh() noexcept = 0;
			virtual void remove_objs() = 0;
			virtual void show() const noexcept = 0;
	};
}
