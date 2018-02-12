#ifndef __GAME_KLONDIKE_HPP__
#define __GAME_KLONDIKE_HPP__

#include "libgame/game.hpp"
#include "libview/gameview.hpp"

namespace card {
class Deck;
};

namespace game {

class Klondike {
 public:
  Klondike(){};

  void start() {
    card::Deck deck;
    game::Game game;

    game.start(deck);
    view::GameView().draw(game);
  };
};
};

#endif  //__GAME_KLONDIKE_HPP__