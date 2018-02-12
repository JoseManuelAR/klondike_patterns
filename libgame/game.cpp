#include "libgame/game.hpp"
#include "libgame/undoitem.hpp"

namespace game {

void Game::addUndo(game::UndoItem *undoItem) {
  this->undoStack.push(undoItem);
  while (not this->redoStack.empty()) {
    this->redoStack.pop();
  }
}

bool Game::undo() {
  if (not undoStack.empty()) {
    game::UndoItem *undoItem = this->undoStack.top();
    pile::Pile *originPile = this->getPile(undoItem->getOriginName());
    pile::Pile *destinationPile = this->getPile(undoItem->getDestinationName());
    game::UndoItem *redoItem = new game::UndoItem(
        *this, undoItem->getOriginName(), undoItem->getDestinationName());

    originPile->assign(undoItem->getOriginCards());
    destinationPile->assign(undoItem->getDestinationCards());

    this->redoStack.push(redoItem);
    this->undoStack.pop();
    return true;
  }
  return false;
}

bool Game::redo() {
  if (not redoStack.empty()) {
    game::UndoItem *redoItem = this->redoStack.top();
    pile::Pile *originPile = this->getPile(redoItem->getOriginName());
    pile::Pile *destinationPile = this->getPile(redoItem->getDestinationName());
    game::UndoItem *undoItem = new game::UndoItem(
        *this, redoItem->getOriginName(), redoItem->getDestinationName());

    originPile->assign(redoItem->getOriginCards());
    destinationPile->assign(redoItem->getDestinationCards());

    this->undoStack.push(undoItem);
    this->redoStack.pop();
    return true;
  }
  return false;
}
}
