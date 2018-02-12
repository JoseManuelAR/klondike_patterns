#include "libcommand/movement.hpp"
#include "libgame/game.hpp"
#include "libgame/undoitem.hpp"

#include <chrono>    // std::chrono::seconds
#include <iostream>  // std::cout, std::endl
#include <thread>    // std::this_thread::sleep_for

namespace command {

bool Movement::configureParameters(std::vector<std::string> parameters) {
  if (parameters.size() == 2 || parameters.size() == 3) {
    this->originName = parameters[0];
    std::transform(this->originName.begin(), this->originName.end(),
                   this->originName.begin(), ::toupper);
    this->destinationName = parameters[1];
    std::transform(this->destinationName.begin(), this->destinationName.end(),
                   this->destinationName.begin(), ::toupper);
    if (parameters.size() == 3) {
      this->number = std::stoi(parameters[2]);
    } else {
      this->number = 1;
    }
    return (this->originName != this->destinationName && this->number > 0);
  }
  return false;
};

bool Movement::execute(game::Game& game) const {
  bool ok = false;
  pile::Pile* originPile = game.getPile(this->originName);
  pile::Pile* destinationPile = game.getPile(this->destinationName);

  if (originPile != nullptr && destinationPile != nullptr) {
    game::UndoItem* undoItem =
        new game::UndoItem(game, this->originName, this->destinationName);
    card::Cards cardsToMove = originPile->get(number);
    if (cardsToMove.size() == number) {
      if (not destinationPile->put(cardsToMove)) {
        std::cout << "not destinationPile->put(cardsToMove) failed!"
                  << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        originPile->restore(cardsToMove);
      } else {
        undoItem->process();
        originPile->moved();
        game.checkWin();
        ok = true;
      }
    } else {
      std::cout << "cardsToMove.size() == number failed!" << std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    if (not ok) {
      delete undoItem;
    }
  } else {
    std::cout << "originPile != nullptr && destinationPile != nullptr failed!"
              << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }
  return ok;
}
}
