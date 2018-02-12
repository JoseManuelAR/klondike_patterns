#ifndef __PILES_REMAINDER_HPP__
#define __PILES_REMAINDER_HPP__

#include "pile.hpp"

namespace pile {

class Remainder : public Pile {
 public:
  Remainder() : Pile(std::string(PREFIX)) {}
  Remainder(std::vector<card::Card> cards) : Pile(std::string(PREFIX), cards) {}

  virtual void deal(card::Deck &deck) override {
    while (not deck.empty()) {
      this->push(deck.top());
      deck.pop();
    }
  }

  virtual card::Cards get(std::uint8_t number) override {
    card::Cards cards;

    if (number == 1 && not this->empty() && not this->top().isFaceUp()) {
      cards.push(this->top());
      this->pop();
    }
    return cards;
  }

  virtual bool put(card::Cards cards) override { return false; }

  virtual void moved() override {}

 private:
  constexpr static const char *PREFIX = "D";
};
};

#endif  //__PILES_REMAINDER_HPP__
