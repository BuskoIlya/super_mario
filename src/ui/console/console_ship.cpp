#include "console_ship.hpp"

#include <cmath>

using biv::ConsoleShip;

ConsoleShip::ConsoleShip(const Coord& top_left, const int width, const int height) 
	: Ship(top_left, width, height) {}

int ConsoleShip::get_bottom() const noexcept {
	return std::round(top_left.y + height);
}

char ConsoleShip::get_brush() const noexcept {
	return '#';
}

int ConsoleShip::get_height() const noexcept {
	return height;
}

int ConsoleShip::get_left() const noexcept {
	return std::round(top_left.x);
}

int ConsoleShip::get_right() const noexcept {
	return std::round(top_left.x + width);
}

int ConsoleShip::get_top() const noexcept {
	return std::round(top_left.y);
}


