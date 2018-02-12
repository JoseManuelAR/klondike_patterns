#ifndef __CARD_CARD_HPP__
#define __CARD_CARD_HPP__

#include <cstdint>
#include <stack>
#include <type_traits>

#include <iostream>

namespace card {

#define CLASS_ENUM(T, B, E)                               \
  inline T operator+(T v, int inc) {                      \
    return (T)(std::underlying_type<T>::type(v) + inc);   \
  }                                                       \
  inline T operator++(T& v) {                             \
    return v = (T)(std::underlying_type<T>::type(v) + 1); \
  }                                                       \
  inline T operator*(T v) { return v; }                   \
  inline T begin(T v) { return B; }                       \
  inline T end(T v) {                                     \
    T l = E;                                              \
    return ++l;                                           \
  }

enum class Value : std::uint8_t {
  Ace,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King
};
CLASS_ENUM(Value, Value::Ace, Value::King)

enum class Suit : std::uint8_t { Spade, Club, Heart, Diamond };
CLASS_ENUM(Suit, Suit::Spade, Suit::Diamond)

enum class Color : std::uint8_t { Black, Red };

class Card {
 public:
  friend std::ostream& operator<<(std::ostream& os, const card::Card& obj);

  Card(Value value, Suit suit)
      : value(value),
        suit(suit),
        color(COLORS[static_cast<int>(suit)]),
        faceUp(false){};
  Card(Value value, Suit suit, bool faceUp)
      : value(value),
        suit(suit),
        color(COLORS[static_cast<int>(suit)]),
        faceUp(faceUp){};

  Value getValue() const { return this->value; }
  Suit getSuit() const { return this->suit; }
  Color getColor() const { return this->color; }

  bool isFaceUp() const { return faceUp; }
  void setFaceUp() { faceUp = true; }
  void setFaceDown() { faceUp = false; }

  bool operator==(const Value& value) const { return this->value == value; }

  bool next(const Card card) const {
    return static_cast<int>(this->value) == (static_cast<int>(card.value) + 1);
  }

  bool sameColor(const Card card) const {
    return (static_cast<int>(this->color) == static_cast<int>(card.color));
  }

 private:
  static const Color COLORS[];

  Value value;
  Suit suit;
  Color color;
  bool faceUp;
};
};

#endif  //__CARD_CARD_HPP__
