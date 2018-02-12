#ifndef __TABLEAU_HPP__
#define __TABLEAU_HPP__

#include "pile.hpp"

namespace pile {

class Tableau : public Pile {
 public:
  Tableau(std::uint8_t index)
      : Pile(std::string(PREFIX) + std::to_string(index)), index(index) {}
  Tableau(std::uint8_t index, std::vector<card::Card> cards)
      : Pile(std::string(PREFIX) + std::to_string(index), cards),
        index(index) {}

  virtual const card::Cards getCardsPile() const override {
    if (this->empty()) {
      return card::Cards();
    }
    return this->cards;
  }

  virtual void deal(card::Deck &deck) override {
    card::Cards cards = deck.get(index);

    while (not cards.empty()) {
      this->push(cards.top());
      cards.pop();
    }
    this->top().setFaceUp();
  }

  virtual card::Cards get(std::uint8_t number) override {
    card::Cards cards;

    while (number > 0 && not this->empty() && this->top().isFaceUp()) {
      cards.push(this->top());
      this->pop();
      number--;
    }
    if (number > 0) {
      this->restore(cards);
      cards.clear();
    }
    return cards;
  }

  virtual bool put(card::Cards cards) override {
    std::size_t initialSize = this->size();
    bool ok = true;

    while (not cards.empty() && ok) {
      ok = false;
      if (checkCard(cards.top())) {
        this->push(cards.top());
        cards.pop();
        ok = true;
      }
    }
    if (not ok) {
      while (this->size() > initialSize) {
        this->pop();
      }
    }
    return ok;
  }

  virtual void moved() override {
    if (not cards.top().isFaceUp()) {
      cards.top().setFaceUp();
    }
  }

 private:
  constexpr static const char *PREFIX = "T";
  std::uint8_t index;

  bool checkCard(card::Card card) const {
    return ((this->empty() && ((card.isFaceUp() && card == card::Value::King) ||
                               not card.isFaceUp())) ||
            (not this->empty() &&
             (not this->top().isFaceUp() ||
              (this->top().next(card) && not this->top().sameColor(card)))));
  }
};
};

#endif  //__TABLEAU_HPP__
