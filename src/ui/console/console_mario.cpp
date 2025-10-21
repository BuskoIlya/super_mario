#include "console_mario.hpp"

#include <cmath>

using biv::ConsoleMario;

ConsoleMario::ConsoleMario(const Coord& top_left, const int width, const int height) 
	: Mario(top_left, width, height) {}

int ConsoleMario::get_bottom() const noexcept {
	return Rect::get_bottom();
}

char ConsoleMario::get_brush() const noexcept {
	return '@';
}

int ConsoleMario::get_height() const noexcept {
	return Rect::get_height();
}

int ConsoleMario::get_left() const noexcept {
	return Rect::get_left();
}

int ConsoleMario::get_right() const noexcept {
	return Rect::get_right();
}

int ConsoleMario::get_top() const noexcept {
	return Rect::get_top();
}


