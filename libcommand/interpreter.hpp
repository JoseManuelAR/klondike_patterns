#ifndef __COMMAND_INTERPRETER_HPP__
#define __COMMAND_INTERPRETER_HPP__

#include <string>
#include <unordered_map>

namespace command {

class Command;

class Interpreter {
 public:
  Interpreter();
  command::Command *interpret(std::string commandLine) const;

 private:
  std::unordered_map<std::string, command::Command *> commands;
};
};

#endif  //__COMMAND_INTERPRETER_HPP__