#ifndef __VIEW_GAMEVIEW_HPP__
#define __VIEW_GAMEVIEW_HPP__

#include "libview/console.hpp"

namespace game {
class Game;
}

namespace command {
class Command;
}

namespace view {

class GameView {
 public:
  GameView();
  void draw(game::Game &game);

 private:
  view::Console console;

  void drawGame(game::Game &game);
  command::Command *getCommand() const;
};
};

#endif  //__VIEW_GAMEVIEW_HPP__