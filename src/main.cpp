/**
	Игровой цикл - это обощённое представление потока событий, происходящих в игре.

	Игровой цикл:
		1. Установка параметров игры
		2. Получение пользовательского ввода
		3. Обновление внутреннего состояния игры
		4. Обновление изображения на экране
		5. Проверка того, не окончена ли игра

		*** Если игра не окончена, то возвращаемся в пункт № 2.

		6. Завершение
*/
#include <thread>
#include <windows.h>

#include "cursor.hpp"
#include "game_map.hpp"
#include "rect.hpp"
#include "ship.hpp"

int main() {
	// 1. Установка параметров игры
	using namespace std::chrono_literals;
	biv::hide_cursor();
	biv::GameMap game_map;
	
	biv::Ship* ship = new biv::Ship(biv::Rect({20, 25}, 40, 2));
	game_map.add_item(ship);
	
	do {
		// 2. Получение пользовательского ввода
		if (GetKeyState(VK_ESCAPE) < 0) break;
		
		// 3. Обновление внутреннего состояния игры
		
		// 4. Обновление изображения на экране
		game_map.refresh();
		biv::set_cursor_position(0, 0);
		game_map.show();
		
	} while (/* 5. Проверка того, не окончена ли игра */ true);
	
	// 6. Завершение
	
}
