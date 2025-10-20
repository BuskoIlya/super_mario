#include "collisionable.hpp"

using biv::Collisionable;

bool Collisionable::has_collision(Rect* obj) const noexcept {
	Rect myself = get_rect();
	return (
		myself.get_right() > obj->get_left() &&
		myself.get_left() < obj->get_right() && 
		myself.get_bottom() > obj->get_top() && 
		myself.get_top() < obj->get_bottom()
	);
}

bool Collisionable::is_alive() const noexcept {
	return alive;
}

void Collisionable::kill() noexcept {
	alive = false;
}
