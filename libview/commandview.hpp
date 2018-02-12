#ifndef __VIEW_COMMANDVIEW_HPP__
#define __VIEW_COMMANDVIEW_HPP__

#include "libview/console.hpp"

namespace game {
class Game;
}

namespace view {

class CommandView {
 public:
  void draw(const game::Game& game);

 private:
  view::Console console;
};
}

#endif  //__VIEW_COMMANDVIEW_HPP__