#include "libview/pileview.hpp"
#include "libpile/pile.hpp"

namespace view {

void PileView::draw(const pile::Pile& pile) {
  std::cout << std::setw(2) << pile.getKey() << "[" << std::setw(2)
            << pile.size() << "]:";
  card::Cards cards = pile.getCardsPile();
  if (cards.empty()) {
    std::cout << std::setw(3) << "<>";
  } else {
    for (const auto& card : cards) {
      view::CardView().draw(card);
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}
}