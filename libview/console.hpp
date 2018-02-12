#ifndef __VIEW_CONSOLE_HPP__
#define __VIEW_CONSOLE_HPP__

#include <iomanip>
#include <iostream>
#include <string>

namespace view {

class Console {
 public:
  inline void clean() const { std::cout << "\033[2J\033[1;1H"; }
  inline void out(const std::string& text) const { std::cout << text; }
  inline void endl() const { std::cout << std::endl; }
  inline void enable() const { std::cout << ENABLE; }
  inline void disable() const { std::cout << DISABLE; }
  inline void reset() const { std::cout << RESET; }

  inline void emptyCard() const { std::cout << std::setw(3) << "XX"; }
  inline void card(int color, int value, int suit) {
    std::cout << StringColor[color] << std::setw(2) << StringValue[value]
              << StringSuit[suit] << RESET;
  }

 private:
  static const std::string DISABLE;
  static const std::string ENABLE;
  static const std::string RESET;

  static const std::string StringValue[];
  static const std::string StringSuit[];
  static const std::string StringColor[];
};
}

#endif  //__VIEW_CONSOLE_HPP__