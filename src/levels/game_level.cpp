#include "game_level.hpp"

using biv::GameLevel;

GameLevel::GameLevel(GameMap* game_map) {
	this->game_map = game_map;
}

GameLevel::~GameLevel() {
	if (parent) {
		delete parent;
		next = nullptr;
	}
	clear_data();
}

void GameLevel::restart() {
	clear_data();
	init_data();
}

bool GameLevel::is_final() const noexcept {
	return false;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void GameLevel::clear_data() {
	for (UIObject* item: ships) {
		delete item;
	}
	ships.clear();
}
