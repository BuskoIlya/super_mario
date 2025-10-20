#include "game_map.hpp"

#include <cstdio>
#include <iostream>

using biv::GameMap;

GameMap::GameMap() {
	clear();
}

void GameMap::add_item(UIObject* item) {
	items.push_back(item);
}

void GameMap::clear() noexcept {
	// Воздух
	for (int i = 0; i < width; i++) {
		map[0][i] = ' ';
	}
	map[0][width] = '\0';
	
	for (int i = 1; i < height - 3; i++) {
		std::sprintf(map[i], map[0]);
	}
	
	// Вода
	for (int i = 0; i < width; i++) {
		map[height - 3][i] = '~';
	}
	map[height - 3][width] = '\0';
	
	for (int i = height - 2; i < height; i++) {
		std::sprintf(map[i], map[height - 3]);
	}
}

void GameMap::refresh() noexcept {
	clear();
	
	for (UIObject* item: items) {
		int left = item->get_left();
		int top = item->get_top();
		int right = item->get_right();
		int bottom = item->get_bottom();
		
		char brush = item->get_brush();
		
		for (int i = left; i < right; i++) {
			for (int j = top; j < bottom; j++) {
				if (is_on_map(i, j)) {
					map[j][i] = brush;
				}
			}
		}
	}
}

void GameMap::remove_items() {
	items.clear();
}

void GameMap::show() const noexcept {
	for (int i = 0; i < height; i++) {
		std::cout << map[i];
	}
}

// ----------------------------------------------------------------------------
// 									PRIVATE
// ----------------------------------------------------------------------------
bool GameMap::is_on_map(const int x, const int y) const noexcept {
	return x >=0 && x < width && y >= 0 && y < height;
}
