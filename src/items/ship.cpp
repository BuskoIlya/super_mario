#include "ship.hpp"

using biv::Ship;

Ship::Ship(const Rect& rect) : UIObject(rect) {}

char Ship::get_brush() const noexcept {
	return '#';
}

void Ship::move_map_left() noexcept {
	top_left.x -= MapMovable::MAP_STEP;
}

void Ship::move_map_right() noexcept {
	top_left.x += MapMovable::MAP_STEP;
}
