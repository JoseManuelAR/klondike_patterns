#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include "libcard/deck.hpp"
#include "libpile/foundation.hpp"
#include "libpile/pile.hpp"
#include "libpile/remainder.hpp"
#include "libpile/tableau.hpp"
#include "libpile/waste.hpp"

namespace game {

class Board {
 public:
  Board() {
    for (std::uint8_t i = 0; i < FOUNDATION_PILES; ++i) {
      piles.push_back(new pile::Foundation(i + 1));
    }
    for (std::uint8_t i = 0; i < TABLEAU_PILES; ++i) {
      pile::Tableau *tableau = new pile::Tableau(i + 1);
      tableaus.push_back(tableau);
      piles.push_back(tableau);
    }
    waste = new pile::Waste();
    piles.push_back(waste);
    remainder = new pile::Remainder();
    piles.push_back(remainder);
  }

  void deal(card::Deck &deck) {
    for (auto &pile : piles) {
      pile->deal(deck);
    }
  }

  const pile::Piles &getPiles() const { return this->piles; }

  const pile::Piles &getTableaus() const { return this->tableaus; }

  pile::Waste *getWaste() const { return this->waste; }
  pile::Remainder *getRemainder() const { return this->remainder; }

  pile::Pile *getPile(const std::string &key) const {
    for (auto &pile : piles) {
      if (pile->getKey() == key) {
        return pile;
      }
    }
    return nullptr;
  }

  std::size_t size() const { return piles.size(); }

 private:
  constexpr static std::uint8_t FOUNDATION_PILES = 4;
  constexpr static std::uint8_t TABLEAU_PILES = 7;

  pile::Piles piles;

  pile::Piles tableaus;
  pile::Waste *waste;
  pile::Remainder *remainder;
};
};

#endif  //__BOARD_HPP__
