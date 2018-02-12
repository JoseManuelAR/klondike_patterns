#ifndef __COMMAND_COMMAND_HPP__
#define __COMMAND_COMMAND_HPP__

#include <string>
#include <vector>

namespace game {
class Game;
}

namespace command {

class Command {
 public:
  virtual bool configureParameters(std::vector<std::string> parameters) = 0;
  virtual bool execute(game::Game& game) const = 0;
};
};

#endif  //__COMMAND_COMMAND_HPP__
