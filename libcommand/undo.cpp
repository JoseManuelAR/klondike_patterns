#include "libcommand/undo.hpp"
#include "libgame/game.hpp"

#include "libgame/undoitem.hpp"

namespace command {

bool Undo::configureParameters(std::vector<std::string> parameters) {
  return (parameters.empty());
};

bool Undo::execute(game::Game& game) const { return game.undo(); }
}
