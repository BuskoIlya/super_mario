#pragma once

/**
	Вопрос № ххх 
	
	На какую структуру данных похож класс GameLevel?
	В чём это выражается?
	
	Можно ли создавать экземпляры класса GameLevel и почему?
	
	В чём недостатки конструкции GameLevel?
*/

#include <cstddef>
#include <vector>

#include "game_map.hpp"
#include "uiobject.hpp"

namespace biv {
	class GameLevel {
		protected:
			GameMap* game_map = nullptr;
			
			std::vector<UIObject*> ships;
			
			GameLevel* parent = nullptr;
			GameLevel* next = nullptr;

		protected:
			GameLevel(GameMap* game_map);

		public:
			virtual ~GameLevel();

			virtual void restart();
			virtual bool is_final() const noexcept;

			virtual GameLevel* get_next() = 0;

		protected:
			void clear_data();

			virtual void init_data() = 0;
	};
}
