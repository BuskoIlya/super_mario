#pragma once

#include <vector>

#include "uiobject.hpp"

namespace biv {
	class GameMap {
		private:
			const int height;
			const int width;
	
			char** map;
			
			std::vector<UIObject*> items;
			
		public:
			GameMap(const int height, const int width);
			~GameMap();
			
			void add_item(UIObject*);
			void clear() noexcept;
			void refresh() noexcept;
			void remove_items();
			void show() const noexcept;
			
		private:
			bool is_on_map(const int x, const int y) const noexcept;
	};
}
