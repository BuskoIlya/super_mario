#include "ship.hpp"

using biv::Ship;

Ship::Ship(const Coord& top_left, const int width, const int height) {
	this->top_left = top_left;
	this->width = width;
	this->height = height;
}

void Ship::move_map_left() noexcept {
	top_left.x -= MapMovable::MAP_STEP;
}

void Ship::move_map_right() noexcept {
	top_left.x += MapMovable::MAP_STEP;
}
