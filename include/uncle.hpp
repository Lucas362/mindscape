/**
 * @file uncle.hpp
 * @brief Purpose: Contains methods to Uncle's management.
 *
 * MIT License
 * Copyright (c) 2017 MindScape
 *
 * https://github.com/TecProg2017-2/mindscape/blob/master/LICENSE.md
 */

#ifndef UNCLE_H
#define UNCLE_H

#include "../engine/include/game_object.hpp"
#include "../engine/include/keyboard_event.hpp"
#include "../engine/include/image.hpp"
#include "../engine/include/game.hpp"
#include "../engine/include/hitbox.hpp"
#include "../engine/include/observable.hpp"
#include "../engine/include/animation.hpp"
#include "enemy.hpp"
#include "arm.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>

namespace mindscape {

    /**
     * @brief Uncle enemy class.
     *
     * This class is responsible to build all Uncle's structure, inheriting of
     * Enemy classes.
     */

    class Uncle : public Enemy {
        private:
        
            void initialize_state_map();
            void initialize_hitboxes();
            void initialize_animations();
            void initialize_audio_effects();

            void on_attack(engine::GameObject *);
            void attack(engine::GameObject*);
            void basic_attack();
            void serial_attack();
            void on_attack();
            
            void die(engine::GameObject*);
        
            GameObject* create_goop();
        
            engine::Animation *create_animation(
                std::string path,
                int sprite_lines,
                int sprite_columns,
                double duration,
                std::string direction
            );
        
            std::vector<engine::GameObject*> clown_goops;
            GameObject* right_arm = nullptr; 
            GameObject* left_arm = nullptr;

        public:
            Uncle(
                std::string name,
                std::pair<int, int> position,
                int priority
            );
            ~Uncle(){
            };

            void on_event(GameEvent);

            void on_collision(
                engine::GameObject*,
                engine::Hitbox*,
                engine::Hitbox*
            );

            void notify(engine::Observable *);
    };
}

#endif