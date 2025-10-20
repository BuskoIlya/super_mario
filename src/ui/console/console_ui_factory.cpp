#include "console_ui_factory.hpp"

using biv::ConsoleUIFactory;

void ConsoleUIFactory::create_game_data(Game* game) {
	game = game;
	game_map = new ConsoleGameMap(30, 200);
	
	ships.push_back(new ConsoleShip({20, 25}, 40, 2));
	ships.push_back(new ConsoleShip({60, 20}, 40, 7));
	ships.push_back(new ConsoleShip({100, 25}, 20, 2));
	ships.push_back(new ConsoleShip({120, 20}, 10, 7));
	ships.push_back(new ConsoleShip({150, 25}, 40, 2));
	ships.push_back(new ConsoleShip({210, 20}, 15, 7));

	for (biv::ConsoleShip* ship: ships) {
		game->add_map_movable(ship);
	}
	
	for (biv::ConsoleShip* ship: ships) {
		game_map->add_item(ship);
	}
}

biv::GameMap* ConsoleUIFactory::get_game_map() {
	return game_map;
}
