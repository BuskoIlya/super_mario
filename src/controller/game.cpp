#include "game.hpp"

using biv::Game;

Game::Game() {}

void Game::add_collisionable(Collisionable* obj) {
	collisionable_objs.push_back(obj);
}

void Game::add_map_movable(MapMovable* obj) {
	map_movable_objs.push_back(obj);
}

void Game::add_movable(Movable* obj) {
	movable_objs.push_back(obj);
}

void Game::add_ship(Rect* obj) {
	ships.push_back(obj);
}

void Game::check_ships_collisions() noexcept {
	for (Collisionable* obj: collisionable_objs) {
		for (Rect* ship: ships) {
			if (obj->has_collision(ship)) {
				obj->process_vertical_static_collision(ship);
				break;
			}
		}
	}
}

void Game::move_map_left() noexcept {
	for (MapMovable* obj: map_movable_objs) {
		obj->move_map_left();
	}
}

void Game::move_map_right() noexcept {
	for (MapMovable* obj: map_movable_objs) {
		obj->move_map_right();
	}
}

void Game::move_objs_vertically() noexcept {
	for (Movable* obj: movable_objs) {
		obj->move_vertically();
	}
}
