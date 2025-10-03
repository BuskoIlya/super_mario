#include "ship.hpp"

using biv::Ship;

Ship::Ship(const Rect& rect) : UIObject(rect) {}

char Ship::get_brush() const noexcept {
	return '#';
}
