#include "libcommand/flip.hpp"
#include "libgame/game.hpp"
#include "libgame/undoitem.hpp"

#include <vector>

namespace command {

bool Flip::configureParameters(std::vector<std::string> parameters) {
  return (parameters.empty());
};

bool Flip::execute(game::Game& game) const {
  pile::Remainder* remainder = game.getRemainder();
  pile::Waste* waste = game.getWaste();

  game::UndoItem* undoItem =
      new game::UndoItem(game, remainder->getKey(), waste->getKey());
  if (remainder->empty()) {
    std::vector<card::Card> list;
    while (not waste->empty()) {
      list.push_back(waste->get(1).top());
      list.back().setFaceDown();
    }
    card::Cards cards{list};
    remainder->restore(cards);
  } else {
    card::Cards cards = remainder->get(1);
    cards.top().setFaceUp();
    waste->put(cards);
  }
  undoItem->process();
  return true;
}
}
