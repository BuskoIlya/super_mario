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
	static_objs.push_back(obj);
}

bool Game::check_static_collisions(Collisionable* obj) const noexcept {
	for (Rect* ship: static_objs) {
		if (obj->has_collision(ship)) {
			return true;
		}
	}
	return false;
}

void Game::check_horizontally_static_collisions() noexcept {
	for (Collisionable* obj: collisionable_objs) {
		for (Rect* ship: static_objs) {
			if (obj->has_collision(ship)) {
				obj->process_horizontal_static_collision(ship);
				break;
			}
		}
	}
}

void Game::check_vertically_static_collisions() noexcept {
	for (Collisionable* obj: collisionable_objs) {
		for (Rect* ship: static_objs) {
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

void Game::move_objs_horizontally() noexcept {
	for (Movable* obj: movable_objs) {
		obj->move_horizontally();
	}
}

void Game::move_objs_vertically() noexcept {
	for (Movable* obj: movable_objs) {
		obj->move_vertically();
	}
}
