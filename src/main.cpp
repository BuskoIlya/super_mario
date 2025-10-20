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
#include <windows.h>

#include "console_ui_factory.hpp"
#include "cursor.hpp"
#include "game.hpp"
#include "game_map.hpp"
#include "ui_factory.hpp"

int main() {
	// 1. Установка параметров игры
	biv::hide_cursor();
	
	biv::Game game;
	biv::UIFactory* ui_factory = new biv::ConsoleUIFactory();
	ui_factory->create_game_data(&game);
	biv::GameMap* game_map = ui_factory->get_game_map();
	
	do {
		// 2. Получение пользовательского ввода	
		if (GetKeyState('A') < 0) {
			game.move_map_right();
		}
		if (GetKeyState('D') < 0) {
			game.move_map_left();
		}
		
		// 3. Обновление внутреннего состояния игры
		
		// 4. Обновление изображения на экране
		game_map->refresh();
		biv::set_cursor_position(0, 0);
		game_map->show();
	} while (/* 5. Проверка того, не окончена ли игра */ GetKeyState(VK_ESCAPE) >= 0);
	
	// 6. Завершение
	
}
