#include "game_object_factory.hpp"


using namespace mindscape;

engine::GameObject* GameObjectFactory::fabricate(
  GameObjectFactory::Options option,
  std::pair<int, int> coordinates,
  int priority){

  switch(option){
    case(GameObjectFactory::LITTLE_GIRL):
      return fabricate_little_girl();
    case(GameObjectFactory::FOOTER):
      return fabricate_footer();
    case(GameObjectFactory::FOX):
      return fabricate_fox();
    case(GameObjectFactory::PLATFORM):
      return fabricate_platform();
    case(GameObjectFactory::BUTTON):
      return fabricate_button();
    case(GameObjectFactory::BACKGROUND):
      return fabricate_background();
    case(GameObjectFactory::SELECT_ARROW):
      return fabricate_select_arrow();
    default:
      return NULL;
  }
}

engine::GameObject* GameObjectFactory::fabricate_footer(){
  std::cout << "NOT IMPLEMENTED YET" << std::endl;
  return NULL;
}

engine::GameObject* GameObjectFactory::fabricate_platform(){
  std::cout << "NOT IMPLEMENTED YET" << std::endl;
  return NULL;
}

engine::GameObject* GameObjectFactory::fabricate_background(){
  std::cout << "NOT IMPLEMENTED YET" << std::endl;
  return NULL;
}

engine::GameObject* GameObjectFactory::fabricate_button(){
  std::cout << "NOT IMPLEMENTED YET" << std::endl;
  return NULL;
}

engine::GameObject* GameObjectFactory::fabricate_select_arrow(){
  std::cout << "NOT IMPLEMENTED YET" << std::endl;
  return NULL;
}

engine::GameObject* GameObjectFactory::fabricate_fox(){
  std::cout << "NOT IMPLEMENTED YET" << std::endl;
  return NULL;
}

engine::GameObject* GameObjectFactory::fabricate_little_girl(){
  engine::Game& game = engine::Game::get_instance();

  std::pair<int, int> place (416, -500);


  //Creating running right animation
  engine::Animation* running_right_animation = new engine::Animation(
    game.get_renderer(),
    "../assets/images/sprites/little_girl/little_girl_running_right.png",
    false,
    std::make_pair(0, 0),
    1,1,9,0.9,true,"RIGHT"
  );
  running_right_animation->set_values(
    std::make_pair(192, 192),
    std::make_pair(192, 192),
    std::make_pair(0, 0)
  );

  //Creating running right animation
  engine::Animation* running_left_animation = new engine::Animation(
    game.get_renderer(),
    "../assets/images/sprites/little_girl/little_girl_running_left.png",
    false,
    std::make_pair(0, 0),
    1,1,9,0.9,true,"LEFT"
  );
  running_left_animation->set_values(
    std::make_pair(192, 192),
    std::make_pair(192, 192),
    std::make_pair(0, 0)
  );


  //Creating idle right animation
  engine::Animation* idle_right_animation = new engine::Animation(
    game.get_renderer(),
    "../assets/images/sprites/little_girl/little_girl_idle_right.png",
    true,
    std::make_pair(0, 0),
    1,1,10,1.5,"RIGHT"
  );
  idle_right_animation->set_values(
    std::make_pair(192, 192),
    std::make_pair(192, 192),
    std::make_pair(0, 0)
  );

  //Creating idle left animation
  engine::Animation* idle_left_animation = new engine::Animation(
    game.get_renderer(),
    "../assets/images/sprites/little_girl/little_girl_idle_left.png",
    false,
    std::make_pair(0, 0),
    1,1,10,1.5,true,"LEFT"
  );
  idle_left_animation->set_values(
    std::make_pair(192, 192),
    std::make_pair(192, 192),
    std::make_pair(0, 0)
  );

  //Creating jumping right animation
  engine::Animation* jumping_right_animation = new engine::Animation(
    game.get_renderer(),
    "../assets/images/sprites/little_girl/little_girl_jumping_right.png",
    false,
    std::make_pair(0, 0),
    1,1,5,1.5,true,"RIGHT"
  );
  jumping_right_animation->set_values(
    std::make_pair(192, 192),
    std::make_pair(192, 192),
    std::make_pair(0, 0)
  );

  //Creating jumping left animation
  engine::Animation* jumping_left_animation = new engine::Animation(
    game.get_renderer(),
    "../assets/images/sprites/little_girl/little_girl_jumping_left.png",
    false,
    std::make_pair(0, 0),
    1,1,5,1.5,true,"LEFT"
  );
  jumping_left_animation->set_values(
    std::make_pair(192, 192),
    std::make_pair(192, 192),
    std::make_pair(0, 0)
  );

  engine::GameObject* little_girl = new engine::LittleGirl("little_girl", place, 52);
  engine::Hitbox* hitbox= new engine::Hitbox("hitbox", little_girl->get_position(), std::make_pair(60, 45), std::make_pair(50,140), game.get_renderer());

  little_girl->collidable = true;
  little_girl->add_animation("running_right_animation",running_right_animation);
  little_girl->add_animation("running_left_animation",running_left_animation);
  little_girl->add_animation("idle_right_animation",idle_right_animation);
  little_girl->add_animation("idle_left_animation",idle_left_animation);
  little_girl->add_animation("jumping_right_animation",jumping_right_animation);
  little_girl->add_animation("jumping_left_animation",jumping_left_animation);
  little_girl->set_actual_animation(idle_right_animation);
  little_girl->add_component(hitbox);

  engine::Physics *physics = engine::Physics::get_instance();
  physics->add_physicable(little_girl);

  return little_girl;
}
