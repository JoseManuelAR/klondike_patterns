#ifndef __CARD_CARDS_HPP__
#define __CARD_CARDS_HPP__

#include "card.hpp"

#include <algorithm>
#include <random>

#include <vector>

namespace card {

class Cards {
 public:
  friend std::ostream& operator<<(std::ostream& os, const card::Cards& obj);

  Cards() : list() {}
  Cards(std::vector<Card> list) : list(list) {}

  inline std::vector<Card>::iterator begin() { return list.begin(); }
  inline std::vector<Card>::iterator end() { return list.end(); }
  const card::Card& operator[](int position) const { return list[position]; }

  std::size_t size() const { return list.size(); }
  bool empty() const { return list.empty(); }

  card::Card& top() { return list.front(); }
  const card::Card& top() const { return list.front(); }

  void clear() { list.clear(); }
  void push(const card::Card& card) { list.insert(list.begin(), card); }
  void pop() { list.erase(list.begin()); }

  void shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(list.begin(), list.end(), g);
  }

 private:
  std::vector<Card> list;
};
};

#endif  //__CARD_CARDS_HPP__
