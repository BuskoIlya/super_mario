#include "first_level.hpp"

#include "rect.hpp"
#include "ship.hpp"
#include "uiobject.hpp"

using biv::FirstLevel;

FirstLevel::FirstLevel(GameMap* game_map) : GameLevel(game_map) {
	init_data();
}

biv::GameLevel* FirstLevel::get_next() {
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void FirstLevel::init_data() {
	ships.push_back(new Ship(Rect({20, 25}, 40, 2)));
	ships.push_back(new Ship(Rect({60, 20}, 40, 7)));
	ships.push_back(new Ship(Rect({100, 25}, 20, 2)));
	ships.push_back(new Ship(Rect({120, 20}, 10, 7)));
	ships.push_back(new Ship(Rect({150, 25}, 40, 2)));
	ships.push_back(new Ship(Rect({210, 20}, 15, 7)));

	for (biv::UIObject* ship: ships) {
		game_map->add_item(ship);
	}
}
