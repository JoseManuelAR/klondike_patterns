#ifndef __FOUNDATION_HPP__
#define __FOUNDATION_HPP__

#include "pile.hpp"

namespace pile {

class Foundation : public Pile {
 public:
  Foundation(std::uint8_t index)
      : Pile(std::string(PREFIX) + std::to_string(index)) {}
  Foundation(std::uint8_t index, std::vector<card::Card> card)
      : Pile(std::string(PREFIX) + std::to_string(index), card) {}

  virtual void deal(card::Deck &deck) override {}

  virtual card::Cards get(std::uint8_t number) override {
    card::Cards card;

    if (number == 1 && not this->empty() && this->top().isFaceUp()) {
      card.push(this->top());
      this->pop();
    }
    return card;
  }

  virtual bool put(card::Cards card) override {
    bool ok = false;

    if (card.size() == 1 && card.top().isFaceUp() &&
        ((this->empty() && card.top() == card::Value::Ace) ||
         (not this->empty() && card.top().next(this->top())))) {
      this->push(card.top());
      card.pop();
      ok = true;
    }
    return ok;
  }

  virtual void moved() override {}

 private:
  constexpr static const char *PREFIX = "F";
};
};

#endif  //__FOUNDATION_HPP__
