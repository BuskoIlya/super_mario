#pragma once

#include "console_game_map.hpp"
#include "console_mario.hpp"
#include "console_ship.hpp"
#include "ui_factory.hpp"

namespace biv {
	class ConsoleUIFactory : public UIFactory {
		private:
			ConsoleGameMap* game_map = nullptr;
			std::vector<ConsoleShip*> ships;
			ConsoleMario* mario = nullptr;

		public:
			ConsoleUIFactory(Game* game);
			
			void clear_data() override;
			void create_mario(
				const Coord& top_left, const int width, const int height
			) override;
			void create_ship(
				const Coord& top_left, const int width, const int height
			) override;
			GameMap* get_game_map() override;
			Mario* get_mario() override;
			
		private:
			virtual void create_game_map() override;
	};
}
