#include "console_mario.hpp"

#include <cmath>

using biv::ConsoleMario;

ConsoleMario::ConsoleMario(const Coord& top_left, const int width, const int height) 
	: Mario(top_left, width, height) {}

int ConsoleMario::get_bottom() const noexcept {
	return std::round(top_left.y + height);
}

char ConsoleMario::get_brush() const noexcept {
	return '@';
}

int ConsoleMario::get_height() const noexcept {
	return height;
}

int ConsoleMario::get_left() const noexcept {
	return std::round(top_left.x);
}

int ConsoleMario::get_right() const noexcept {
	return std::round(top_left.x + width);
}

int ConsoleMario::get_top() const noexcept {
	return std::round(top_left.y);
}


