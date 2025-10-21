#include "console_ship.hpp"

#include <cmath>

using biv::ConsoleShip;

ConsoleShip::ConsoleShip(const Coord& top_left, const int width, const int height) 
	: Ship(top_left, width, height) {}

int ConsoleShip::get_bottom() const noexcept {
	return Rect::get_bottom();
}

char ConsoleShip::get_brush() const noexcept {
	return '#';
}

int ConsoleShip::get_height() const noexcept {
	return Rect::get_height();
}

int ConsoleShip::get_left() const noexcept {
	return Rect::get_left();
}

int ConsoleShip::get_right() const noexcept {
	return Rect::get_right();
}

int ConsoleShip::get_top() const noexcept {
	return Rect::get_top();
}
