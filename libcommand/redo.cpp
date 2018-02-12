#include "libcommand/redo.hpp"
#include "libgame/game.hpp"

#include "libgame/undoitem.hpp"

namespace command {

bool Redo::configureParameters(std::vector<std::string> parameters) {
  return (parameters.empty());
};

bool Redo::execute(game::Game& game) const { return game.redo(); }
}
