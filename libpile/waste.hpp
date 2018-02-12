#ifndef __WASTE_HPP__
#define __WASTE_HPP__

#include "pile.hpp"

namespace pile {

class Waste : public Pile {
 public:
  Waste() : Pile(std::string(PREFIX)) {}
  Waste(std::vector<card::Card> cards) : Pile(std::string(PREFIX), cards) {}

  virtual void deal(card::Deck &deck) override {}

  virtual card::Cards get(std::uint8_t number) override {
    card::Cards cards;

    if (number == 1 && not this->empty() && this->top().isFaceUp()) {
      cards.push(this->top());
      this->pop();
    }
    return cards;
  }

  virtual bool put(card::Cards cards) override {
    bool ok = false;

    if (cards.size() == 1) {
      this->push(cards.top());
      cards.pop();
      ok = true;
    }
    return ok;
  }

  virtual void moved() override {}

 private:
  constexpr static const char *PREFIX = "W";
};
};

#endif  //__WASTE_HPP__
