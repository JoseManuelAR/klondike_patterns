#ifndef __VIEW_BOARDVIEW_HPP__
#define __VIEW_BOARDVIEW_HPP__

namespace game {
class Board;
}

namespace view {

class BoardView {
 public:
  void draw(const game::Board& board);
};
}

#endif  //__VIEW_BOARDVIEW_HPP__