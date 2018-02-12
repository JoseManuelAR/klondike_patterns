#ifndef __COMMAND_EXIT_HPP__
#define __COMMAND_EXIT_HPP__

#include "libcommand/command.hpp"
#include "libpile/pile.hpp"

namespace command {

class Exit : public command::Command {
 public:
  virtual bool configureParameters(
      std::vector<std::string> parameters) override;

  virtual bool execute(game::Game& game) const override;

 private:
};
};

#endif  //__COMMAND_EXIT_HPP__
