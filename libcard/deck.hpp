#ifndef __CARD_DECK_HPP__
#define __CARD_DECK_HPP__

#include "cards.hpp"

namespace card {

class Deck {
 public:
  Deck() : cards() {
    for (auto v : Value()) {
      for (auto s : Suit()) {
        cards.push(Card(v, s));
      }
    }
  }

  std::size_t size() const { return cards.size(); }
  bool empty() const { return cards.empty(); }

  card::Card& top() { return cards.top(); }
  const card::Card& top() const { return cards.top(); }
  void pop() { cards.pop(); }

  Cards get(std::uint8_t number) {
    Cards cards{};

    while (number > 0) {
      cards.push(this->cards.top());
      this->cards.pop();
      number--;
    }
    return cards;
  }

  void shuffle() { cards.shuffle(); }

 private:
  Cards cards;
};
};

#endif  //__CARD_DECK_HPP__
