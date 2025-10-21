#include "game.hpp"

#include <algorithm>

using biv::Game;

Game::Game() {}

void Game::add_collisionable(Collisionable* obj) {
	collisionable_objs.push_back(obj);
}

void Game::add_map_movable(MapMovable* obj) {
	map_movable_objs.push_back(obj);
}

void Game::add_mario(Mario* obj) {
	mario = obj;
}

void Game::add_movable(Movable* obj) {
	movable_objs.push_back(obj);
}

void Game::add_static_obj(Rect* obj) {
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
	if (mario->has_collision(static_objs[static_objs.size() - 1])) {
		is_level_end_ = true;
	}
	
	for (Collisionable* obj: collisionable_objs) {
		for (Rect* ship: static_objs) {
			if (obj->has_collision(ship)) {
				obj->process_vertical_static_collision(ship);
				break;
			}
		}
	}
}

void Game::finish() noexcept {
	is_finished_ = true;
}

bool Game::is_finished() const noexcept {
	return is_finished_;
}

bool Game::is_level_end() const noexcept {
	return is_level_end_;
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

void Game::remove_collisionable(Collisionable* obj) {
	collisionable_objs.erase(
		std::remove(
			collisionable_objs.begin(), collisionable_objs.end(), obj
		), 
		collisionable_objs.end()
	);
}

void Game::remove_map_movable(MapMovable* obj) {
	map_movable_objs.erase(
		std::remove(
			map_movable_objs.begin(), map_movable_objs.end(), obj
		), 
		map_movable_objs.end()
	);
}

void Game::remove_mario() noexcept {
	mario = nullptr;
}

void Game::remove_movable(Movable* obj) {
	movable_objs.erase(
		std::remove(
			movable_objs.begin(), movable_objs.end(), obj
		), 
		movable_objs.end()
	);
}

void Game::remove_objs() {
	collisionable_objs.clear();
	map_movable_objs.clear();
	movable_objs.clear();
	static_objs.clear();
	remove_mario();
}

void Game::remove_static_obj(Rect* obj) {
	static_objs.erase(
		std::remove(
			static_objs.begin(), static_objs.end(), obj
		), 
		static_objs.end()
	);
}

void Game::start_level() noexcept {
	is_level_end_ = false;
}
