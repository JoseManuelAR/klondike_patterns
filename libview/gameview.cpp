#include "gameview.hpp"
#include "libcommand/command.hpp"
#include "libgame/game.hpp"
#include "libview/boardview.hpp"
#include "libview/commanddialog.hpp"
#include "libview/commandview.hpp"
#include "libview/windialog.hpp"

namespace view {

GameView::GameView() : console(){};

void GameView::draw(game::Game &game) {
  this->drawGame(game);
  do {
    command::Command *command = this->getCommand();
    command->execute(game);
    this->drawGame(game);
  } while (not game.isFinished() && not game.isWon());
  if (game.isWon()) {
    WinDialog().show();
  }
}

void GameView::drawGame(game::Game &game) {
  console.clean();
  view::CommandView().draw(game);
  view::BoardView().draw(game.getBoard());
}

command::Command *GameView::getCommand() const { return CommandDialog().get(); }
}