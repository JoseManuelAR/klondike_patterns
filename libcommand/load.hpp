#ifndef __COMMAND_LOAD_HPP__
#define __COMMAND_LOAD_HPP__

#include "libcommand/command.hpp"
#include "libpile/pile.hpp"

namespace command {

class Load : public command::Command {
 public:
  virtual bool configureParameters(
      std::vector<std::string> parameters) override;

  virtual bool execute(game::Game& game) const override;

 private:
  std::string file;
};
};

#endif  //__COMMAND_LOAD_HPP__
