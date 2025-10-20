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

#include "console_ui_factory.hpp"
#include "game.hpp"
#include "game_map.hpp"
#include "mario.hpp"
#include "os_control_settings.hpp"
#include "ui_factory.hpp"
#include "user_key_input.hpp"

int main() {
	// 1. Установка параметров игры
	using namespace std::chrono_literals;
	biv::os::init_settings();
	
	biv::Game game;
	biv::UIFactory* ui_factory = new biv::ConsoleUIFactory();
	ui_factory->create_game_data(&game);
	biv::GameMap* game_map = ui_factory->get_game_map();
	biv::Mario* mario = ui_factory->get_mario();
	
	biv::os::UserKeyInput user_input;
	do {
		// 2. Получение пользовательского ввода	
		user_input = biv::os::get_user_key_input();
		switch (user_input) {
			case biv::os::UserKeyInput::MAP_LEFT:
				game.move_map_left();
				break;
			case biv::os::UserKeyInput::MAP_RIGHT:
				game.move_map_right();
				break;
			case biv::os::UserKeyInput::MARIO_JUMP:
				mario->jump();
				break;
		}
		
		// 3. Обновление внутреннего состояния игры
		game.move_objs_vertically();
		game.check_ships_collisions();
		
		// 4. Обновление изображения на экране
		game_map->refresh();
		biv::os::set_cursor_start_position();
		game_map->show();
		std::this_thread::sleep_for(10ms);
	} while (
		/* 5. Проверка того, не окончена ли игра */ 
		user_input != biv::os::UserKeyInput::EXIT
	);
	
	// 6. Завершение
	
}
