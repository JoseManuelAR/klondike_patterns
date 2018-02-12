#include "libcommand/load.hpp"
#include "libgame/game.hpp"

#include <experimental/filesystem>
#include <fstream>

#include <chrono>    // std::chrono::seconds
#include <iostream>  // std::cout, std::endl
#include <thread>    // std::this_thread::sleep_for

namespace command {

bool Load::configureParameters(std::vector<std::string> parameters) {
  if (parameters.size() == 1) {
    file = parameters[0];
    return true;
  }
  return false;
};

bool Load::execute(game::Game& game) const {
  std::ifstream ifs;
  ifs.open(std::string(std::experimental::filesystem::current_path().c_str()) +
               std::string("/") + file,
           std::ifstream::binary);

  while (ifs.good()) {
    std::string key{};
    std::getline(ifs, key, '\0');
    pile::Pile* pile;
    if ((pile = game.getPile(key)) == nullptr) {
      return false;
    }
    std::size_t size;
    ifs.read(reinterpret_cast<char*>(&size), sizeof(size));
    std::vector<card::Card> list;
    while (size > 0) {
      card::Value value;
      ifs.read(reinterpret_cast<char*>(&value), sizeof(value));
      card::Suit suit;
      ifs.read(reinterpret_cast<char*>(&suit), sizeof(suit));
      bool faceUp;
      ifs.read(reinterpret_cast<char*>(&faceUp), sizeof(faceUp));
      list.push_back({value, suit, faceUp});
      size--;
    }
    pile->assign({list});
  }
  return true;
}
}
