#ifndef __COMMAND_FLIP_HPP__
#define __COMMAND_FLIP_HPP__

#include "libcommand/command.hpp"
#include "libpile/pile.hpp"

namespace command {

class Flip : public command::Command {
 public:
  virtual bool configureParameters(
      std::vector<std::string> parameters) override;

  virtual bool execute(game::Game& game) const override;

 private:
  void moveWasteToRemainder();
};
};

#endif  //__COMMAND_FLIP_HPP__
