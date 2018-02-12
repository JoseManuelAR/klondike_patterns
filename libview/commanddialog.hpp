#ifndef __VIEW_COMMANDDIALOG_HPP__
#define __VIEW_COMMANDDIALOG_HPP__

#include "libcommand/interpreter.hpp"

#include <iostream>
#include <string>

namespace command {
class Command;
};

namespace view {
class CommandDialog {
 public:
  command::Command *get() const {
    command::Command *command = nullptr;
    do {
      std::string commandLine;
      std::cout << "\33[K" << std::flush;
      std::cout << "Enter a command:" << std::flush;

      std::getline(std::cin, commandLine);
      command = interpreter.interpret(commandLine);
    } while (command == nullptr);
    return command;
  };

 private:
  command::Interpreter interpreter;
};
};

#endif  //__VIEW_COMMANDDIALOG_HPP__