#include "movable.hpp"

using biv::Movable;

Movable::Movable(
	const Coord& top_left, 
	const int width, const int height, 
	const float vspeed, const float hspeed
	) : Rect(top_left, width, height), vspeed(vspeed), hspeed(hspeed) {}

float Movable::get_vspeed() const noexcept {
	return vspeed;
}

void Movable::jump() noexcept {
	if (vspeed == 0) {
		vspeed = JUMP_SPEED;
	}
}

void Movable::move_horizontally() noexcept {
	top_left.x += hspeed;
}

void Movable::move_vertically() noexcept {
	if (vspeed < MAX_V_SPEED) {
		vspeed += V_ACCELERATION;
	}
	top_left.y += vspeed;
}
