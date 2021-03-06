/**
* @file button.hpp
* @brief Purpose: Contains the Button class declaration.
*
* MIT License
* Copyright (c) 2017 MindScape
*
* https://github.com/TecProg2017-2/mindscape/blob/master/LICENSE.md
*/
#ifndef BUTTON_H
#define BUTTON_H

#include "../engine/include/game_object.hpp"
#include "../engine/include/image.hpp"
#include "../engine/include/game.hpp"
#include "../engine/include/keyboard_event.hpp"
#include "action.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

namespace mindscape {
    /**
    * @brief A Button class.
    *
    * A class responsible to ensure button handling.
    *
    */
    class Button : public engine::GameObject {
        private:
            Action *action;
            std::string param;
      
        public:
            Button( std::string p_name,
                    std::pair<int, int> position,
                    int priority)
                
                    :engine::GameObject(
                    p_name,
                    position,
                    priority,
                    {}
                    ){};

            ~Button() {};
      
            void set_action(Action *, std::string param);
            void on_event(GameEvent game_event);
    };
}

#endif
