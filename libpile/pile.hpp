#ifndef __PILE_HPP__
#define __PILE_HPP__

#include "libcard/cards.hpp"
#include "libcard/deck.hpp"

namespace pile {

class Pile {
 public:
  Pile(const std::string& name) : name(name), cards() {}
  Pile(const std::string& name, std::vector<card::Card> cards)
      : name(name), cards(cards) {}

  Pile& operator=(const Pile& other) {
    if (&other == this) {
      return *this;
    }
    this->name = other.name;
    this->cards = other.cards;
    return *this;
  }

  virtual const card::Cards getCards() const { return this->cards; }

  virtual const card::Cards getCardsPile() const {
    if (this->empty()) {
      return card::Cards();
    }
    return {{this->cards.top()}};
  }

  const std::string& getKey() const { return name; }

  std::size_t size() const { return cards.size(); }
  bool empty() const { return cards.empty(); }

  void setFaceUp() { cards.top().setFaceUp(); }

  virtual void deal(card::Deck& deck) = 0;

  virtual card::Cards get(std::uint8_t number) = 0;
  virtual bool put(card::Cards cards) = 0;
  virtual void moved() = 0;

  void assign(card::Cards cards) { this->cards = cards; }

  void restore(card::Cards cards) {
    while (not cards.empty()) {
      this->push(cards.top());
      cards.pop();
    }
  }

 protected:
  void push(const card::Card& card) { cards.push(card); }
  void pop() { cards.pop(); }
  card::Card& top() { return cards.top(); }
  const card::Card& top() const { return cards.top(); }
  void clean() {
    while (not cards.empty()) {
      cards.pop();
    }
  }

  std::string name;
  card::Cards cards;
};

using Piles = std::vector<pile::Pile*>;
};

#endif  //__PILE_HPP__
