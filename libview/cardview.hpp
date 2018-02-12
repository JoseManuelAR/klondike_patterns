#ifndef __VIEW_CARDVIEW_HPP__
#define __VIEW_CARDVIEW_HPP__

#include "libview/console.hpp"

namespace card {
class Card;
}

namespace view {
class CardView {
 public:
  void draw(const card::Card& card);

 private:
  view::Console console;
};
}

#endif  //__VIEW_CARDVIEW_HPP__