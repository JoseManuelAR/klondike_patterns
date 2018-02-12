#include "exit.hpp"

#include "libcommand/exit.hpp"
#include "libgame/game.hpp"

#include <vector>

namespace command {

bool Exit::configureParameters(std::vector<std::string> parameters) {
  return (parameters.empty());
};

bool Exit::execute(game::Game& game) const {
  game.finish();
  return true;
}
}
