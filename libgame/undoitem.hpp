#ifndef __GAME_UNDOITEM_HPP__
#define __GAME_UNDOITEM_HPP__

#include "libgame/game.hpp"

namespace game {

class UndoItem {
 public:
  UndoItem(game::Game& game, const std::string& originName,
           const std::string& destinationName)
      : game{game},
        originName{originName},
        originCards{game.getPile(originName)->getCards()},
        destinationName{destinationName},
        destinationCards(game.getPile(destinationName)->getCards()) {}

  void process() { game.addUndo(this); }

  const std::string& getOriginName() const { return originName; }
  const std::string& getDestinationName() const { return destinationName; }

  const card::Cards& getOriginCards() const { return originCards; }
  const card::Cards& getDestinationCards() const { return destinationCards; }

 private:
  game::Game& game;
  std::string originName;
  card::Cards originCards;
  std::string destinationName;
  card::Cards destinationCards;
};
};

#endif  //__GAME_GAME_HPP__