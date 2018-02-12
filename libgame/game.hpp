#ifndef __GAME_GAME_HPP__
#define __GAME_GAME_HPP__

#include "libgame/board.hpp"

#include <iostream>

namespace card {
class Deck;
};

namespace game {

class UndoItem;

class Game {
 public:
  Game() : finished(false), won(false), board(){};

  const std::stack<UndoItem *> &getUndoStack() const { return undoStack; }
  bool isUndoEmpty() const { return undoStack.empty(); }
  const std::stack<UndoItem *> &getRedoStack() const { return redoStack; }
  bool isRedoEmpty() const { return redoStack.empty(); }

  const game::Board &getBoard() const { return board; }
  const pile::Piles &getPiles() const { return this->board.getPiles(); }
  pile::Pile *getPile(const std::string &name) const {
    return board.getPile(name);
  }
  pile::Waste *getWaste() const { return board.getWaste(); }
  pile::Remainder *getRemainder() const { return board.getRemainder(); }

  void addUndo(UndoItem *undoItem);

  void start(card::Deck &deck) {
    deck.shuffle();
    board.deal(deck);
  }

  void checkWin() {
    if (this->getWaste()->empty() && this->getRemainder()->empty()) {
      won = true;
      for (auto pile : board.getTableaus()) {
        if (not pile->empty()) {
          won = false;
        }
      }
    }
  }

  void finish() { finished = true; }
  bool isFinished() const { return finished; }
  bool isWon() const { return won; }

  bool undo();
  bool redo();

 private:
  bool finished;
  bool won;
  game::Board board;
  std::stack<UndoItem *> undoStack;
  std::stack<UndoItem *> redoStack;
};
};

#endif  //__GAME_GAME_HPP__