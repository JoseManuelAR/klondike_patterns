#include "libcommand/interpreter.hpp"
#include "libcommand/exit.hpp"
#include "libcommand/flip.hpp"
#include "libcommand/load.hpp"
#include "libcommand/movement.hpp"
#include "libcommand/redo.hpp"
#include "libcommand/save.hpp"
#include "libcommand/undo.hpp"

//#include "libutils/string.hpp"

#include <regex>

namespace command {

Interpreter::Interpreter() {
  commands.insert(std::make_pair<std::string, command::Command *>(
      "X", new command::Exit()));
  commands.insert(std::make_pair<std::string, command::Command *>(
      "M", new command::Movement()));
  commands.insert(std::make_pair<std::string, command::Command *>(
      "F", new command::Flip()));
  commands.insert(std::make_pair<std::string, command::Command *>(
      "U", new command::Undo()));
  commands.insert(std::make_pair<std::string, command::Command *>(
      "R", new command::Redo()));
  commands.insert(std::make_pair<std::string, command::Command *>(
      "L", new command::Load()));
  commands.insert(std::make_pair<std::string, command::Command *>(
      "S", new command::Save()));
}

command::Command *Interpreter::interpret(std::string commandLine) const {
  command::Command *command = nullptr;
  std::vector<std::string> parameters;

  try {
    trim(commandLine);

    std::regex re("[\\s]+");
    std::sregex_token_iterator itComandLine(commandLine.begin(),
                                            commandLine.end(), re, -1);
    std::sregex_token_iterator reg_end;

    for (; itComandLine != reg_end && command == nullptr; ++itComandLine) {
      if (command == nullptr) {
        std::string key = itComandLine->str();
        std::transform(key.begin(), key.end(), key.begin(), ::toupper);

        std::unordered_map<std::string, command::Command *>::const_iterator
            itCommand;
        if ((itCommand = commands.find(key)) != commands.end()) {
          command = itCommand->second;
        }
      }
    }
    for (; itComandLine != reg_end; ++itComandLine) {
      parameters.push_back(itComandLine->str());
    }
    if (command != nullptr) {
      if (not command->configureParameters(parameters)) {
        command = nullptr;
      }
    }
  } catch (...) {
  }
  return command;
}
}