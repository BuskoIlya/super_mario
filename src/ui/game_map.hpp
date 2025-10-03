#pragma once

#include <vector>

#include "uiobject.hpp"

namespace biv {
	class GameMap {
		private:
			static const int width = 200;
			static const int height = 30;
			
			char map[height][width + 1];
			
			std::vector<UIObject*> items;
			
		public:
			GameMap();
			
			void add_item(UIObject*);
			void clear() noexcept;
			void refresh() noexcept;
			void show() const noexcept;
			
		private:
			bool is_on_map(const int x, const int y) const noexcept;
	};
}
