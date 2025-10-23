#include "console_shelf.hpp"

using biv::ConsoleShelf;

ConsoleShelf::ConsoleShelf(const Coord& top_left, const int width, const int height) 
	: Shelf(top_left, width, height) {}

char ConsoleShelf::get_brush() const noexcept {
	return '-';
}
