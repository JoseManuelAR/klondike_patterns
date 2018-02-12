#include "libview/commandview.hpp"
#include "libgame/game.hpp"

namespace view {

void CommandView::draw(const game::Game& game) {
  console.out("x|m|f|");
  if (game.isUndoEmpty()) {
    console.disable();
  } else {
    console.enable();
  }
  console.out("u");
  console.reset();
  console.out("|");
  if (game.isRedoEmpty()) {
    console.disable();
  } else {
    console.enable();
  }
  console.out("r");
  console.reset();
  console.out("|l|s");
  console.endl();
};
}