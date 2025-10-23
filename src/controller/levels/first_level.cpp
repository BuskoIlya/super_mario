#include "first_level.hpp"

#include "second_level.hpp"

using biv::FirstLevel;

FirstLevel::FirstLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

biv::GameLevel* FirstLevel::get_next() {
	if (!next) {
		clear_data();
		next = new biv::SecondLevel(ui_factory);
	}
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void FirstLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);
	
	ui_factory->create_ship({20, 25}, 40, 2);
	
	ui_factory->create_shelf({30, 15}, 5, 3);
	ui_factory->create_shelf({50, 15}, 5, 3);
	
	ui_factory->create_ship({60, 20}, 40, 7);
	
	ui_factory->create_shelf({60, 10}, 10, 3);
	ui_factory->create_shelf({70, 10}, 5, 3);
	ui_factory->create_shelf({75, 10}, 5, 3);
	ui_factory->create_shelf({80, 10}, 5, 3);
	ui_factory->create_shelf({85, 10}, 10, 3);
	
	ui_factory->create_ship({100, 25}, 20, 2);
	ui_factory->create_ship({120, 20}, 10, 7);
	ui_factory->create_ship({150, 25}, 40, 2);
	ui_factory->create_ship({210, 20}, 15, 7);
	
	ui_factory->create_enemy({25, 10}, 3, 2);
	ui_factory->create_enemy({80, 10}, 3, 2);
}
