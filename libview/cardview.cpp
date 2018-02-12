#include "libview/cardview.hpp"
#include "libcard/card.hpp"

namespace view {

void CardView::draw(const card::Card& card) {
  if (not card.isFaceUp()) {
    console.emptyCard();
  } else {
    console.card(static_cast<int>(card.getColor()),
                 static_cast<int>(card.getValue()),
                 static_cast<int>(card.getSuit()));
  }
};
}