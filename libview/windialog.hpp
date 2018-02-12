#ifndef __VIEW_WINDIALOG_HPP__
#define __VIEW_WINDIALOG_HPP__

#include "libcommand/interpreter.hpp"

#include <iostream>
#include <string>

namespace command {
class Command;
};

namespace view {
class WinDialog {
 public:
  void show() const {
    view::Console console;
    console.out("You have won!!!!");
    console.endl();
  };

 private:
};
};

#endif  //__VIEW_WINDIALOG_HPP__