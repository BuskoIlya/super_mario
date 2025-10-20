#pragma once

#include "console_game_map.hpp"
#include "console_mario.hpp"
#include "console_ship.hpp"
#include "game.hpp"
#include "game_map.hpp"
#include "mario.hpp"
#include "ui_factory.hpp"

namespace biv {
	class ConsoleUIFactory : public UIFactory {
		private:
			Game* game = nullptr;

			ConsoleGameMap* game_map = nullptr;
			std::vector<ConsoleShip*> ships;
			ConsoleMario* mario;

		public:
			void create_game_data(Game* game) override;
			GameMap* get_game_map() override;
			Mario* get_mario() override;
	};
}
