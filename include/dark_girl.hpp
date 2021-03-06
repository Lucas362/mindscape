/**
 * @file dark_girl.hpp
 * @brief Purpose: Contains dark girl methods and attributes
 *
 * MIT License
 * Copyright (c) 2017 MindScape
 *
 * https://github.com/TecProg2017-2/mindscape/blob/master/LICENSE.md
 *
 */
#ifndef DARK_GIRL_H
#define DARK_GIRL_H

#include "../engine/include/game_object.hpp"
#include "../engine/include/keyboard_event.hpp"
#include "../engine/include/animation.hpp"
#include "../engine/include/hitbox.hpp"
#include "../engine/include/physics.hpp"
#include "spider.hpp"
#include "fighter.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

namespace mindscape {
    /**
     * @brief Girl class
     *
     * this class is responsible for implementing the main character
     * of the game, the girl.
     */
    class DarkGirl : public engine::GameObject, public mindscape::Fighter {
    private:
        static DarkGirl* instance;

        int running_right_animation_count = 0; /**< Interger. Variable to save
        * number of running animations while the Dark Girl is looking right */

        int running_left_animation_count = 0;/**< Interger. Variable to save
        * number of running animations while the Dark Girl is looking left */

        int jumping_animation_count = 0;/**< Interger. Variable to save
        * number of jumping  animations while the Dark Girl is jumping*/

        int attacking_right_animation = 0;/**< Interger. Variable to save
        * number of attacking animations while the Dark Girl is looking right */

        int attacking_left_animation = 0;/**< Interger. Variable to save
        * number of attacking animations while the Dark Girl is looking left */

        void initialize_state_map();
        void initialize_hitbox();
        void initialize_footer_hitbox();
        void initialize_running_animation();
        void initialize_idle_animation();
        void initialize_jumping_animation();
        void initialize_attacking_animation();
        void initialize_dying_animation();
        void initialize_audio_effects();
        void initialize_as_physicable();
        void jump(std::string);
        void move_right(std::string,std::string);
        void move_left(std::string,std::string);
        void attack();
		void update_state_get_position();
		void update_state_attacking();
		void update_state_idle();
		void update_state_on_ground();
        void on_attack(engine::GameObject *);
        void die(engine::GameObject*);
        engine::Animation *create_animation(
                std::string path,
                int sprite_lines,
                int sprite_columns,
                double duration,
                std::string direction
        );

		void on_collision_platform(engine::GameObject*, engine::Hitbox*, engine::Hitbox*);
		void on_collision_scorpion(engine::GameObject*, engine::Hitbox*, engine::Hitbox*);
		void on_collision_spider(engine::GameObject*, engine::Hitbox*, engine::Hitbox*);
		void on_collision_goop(engine::GameObject*, engine::Hitbox*, engine::Hitbox*);

    public:
        DarkGirl(std::string name, std::pair<int, int> position, int priority);
        ~DarkGirl(){};

        void on_event(GameEvent);
		void on_collision(engine::GameObject*, engine::Hitbox*, engine::Hitbox*);

        void update_state();
    };
}
#endif
