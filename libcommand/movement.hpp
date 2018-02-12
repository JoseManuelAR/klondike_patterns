#ifndef __COMMAND_MOVEMENT_HPP__
#define __COMMAND_MOVEMENT_HPP__

#include "libcommand/command.hpp"
#include "libpile/pile.hpp"

namespace command {

class Movement : public command::Command {
 public:
  Movement() : originName(), destinationName(), number(1){};

  virtual bool configureParameters(
      std::vector<std::string> parameters) override;

  virtual bool execute(game::Game& game) const override;

 private:
  std::string originName;
  std::string destinationName;
  std::uint8_t number;
};
};

#endif  //__COMMAND_MOVEMENT_HPP__
