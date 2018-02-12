#ifndef __VIEW_PILEVIEW_HPP__
#define __VIEW_PILEVIEW_HPP__

#include "libview/cardview.hpp"

namespace pile {
class Pile;
}

namespace view {

class PileView {
 public:
  void draw(const pile::Pile& pile);
};
}

#endif  //__VIEW_PILEVIEW_HPP__