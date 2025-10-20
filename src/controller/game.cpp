#include "game.hpp"

using biv::Game;

Game::Game() {}

void Game::add_map_movable(MapMovable* item) {
	map_movable_objs.push_back(item);
}

void Game::move_map_left() noexcept {
	for (MapMovable* item: map_movable_objs) {
		item->move_map_left();
	}
}

void Game::move_map_right() noexcept {
	for (MapMovable* item: map_movable_objs) {
		item->move_map_right();
	}
}
