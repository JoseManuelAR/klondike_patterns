#ifndef __COMMAND_SAVE_HPP__
#define __COMMAND_SAVE_HPP__

#include "libcommand/command.hpp"
#include "libpile/pile.hpp"

namespace command {

class Save : public command::Command {
 public:
  virtual bool configureParameters(
      std::vector<std::string> parameters) override;

  virtual bool execute(game::Game& game) const override;

 private:
  std::string file;
};
};

#endif  //__COMMAND_SAVE_HPP__
