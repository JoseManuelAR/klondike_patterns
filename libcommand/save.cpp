#include "libcommand/save.hpp"
#include "libgame/game.hpp"

#include <fstream>

namespace command {

bool Save::configureParameters(std::vector<std::string> parameters) {
  if (parameters.size() == 1) {
    file = parameters[0];
    return true;
  }
  return false;
};

bool Save::execute(game::Game& game) const {
  std::ofstream ofs;
  ofs.open(file, std::ofstream::binary | std::ofstream::trunc);

  pile::Piles piles = game.getPiles();
  for (auto pile : piles) {
    ofs.write(pile->getKey().c_str(), pile->getKey().size());
    ofs.put('\0');
    card::Cards cards = pile->getCards();
    std::size_t len = cards.size();
    ofs.write(reinterpret_cast<const char*>(&len), sizeof(len));
    for (auto card : cards) {
      card::Value value = card.getValue();
      ofs.write(reinterpret_cast<const char*>(&value), sizeof(value));
      card::Suit suit = card.getSuit();
      ofs.write(reinterpret_cast<const char*>(&suit), sizeof(suit));
      bool faceUp = card.isFaceUp();
      ofs.write(reinterpret_cast<const char*>(&faceUp), sizeof(faceUp));
    }
  }
  ofs.close();

  return true;
}
}
