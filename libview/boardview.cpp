#include "libview/boardview.hpp"
#include "libgame/board.hpp"
#include "libpile/pile.hpp"
#include "libview/pileview.hpp"

namespace view {

void BoardView::draw(const game::Board& board) {
  pile::Piles piles = board.getPiles();
  for (const auto& pile : piles) {
    view::PileView().draw(*pile);
  }
}
}