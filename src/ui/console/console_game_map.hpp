#pragma once

#include <vector>

#include "game_map.hpp"
#include "console_ui_obj.hpp"

namespace biv {
	class ConsoleGameMap : public GameMap {
		private:
			const int height;
			const int width;
	
			char** map;
			
			std::vector<ConsoleUIObject*> items;
			
		public:
			ConsoleGameMap(const int height, const int width);
			~ConsoleGameMap();
			
			void add_item(ConsoleUIObject*);
			
			void clear() noexcept override;
			void refresh() noexcept override;
			void remove_items() override;
			void show() const noexcept override;
			
		private:
			bool is_on_map(const int x, const int y) const noexcept;
	};
}
