#pragma once

namespace biv {
	class GameMap {
		private:
			static const int width = 200;
			static const int height = 30;
			
			char map[height][width + 1];
			
		public:
			GameMap();
			
			void clear() noexcept;
			void refresh() noexcept;
			void show() const noexcept;
			
		private:
			bool is_on_map(const int x, const int y) const noexcept;
	};
}
