#include "testdeck.hpp"
#include "libcard/deck.hpp"
#include "libpile/tableau.hpp"

TestDeck::TestDeck() {}

TestDeck::~TestDeck(){};

TEST_F(TestDeck, TestDeck1) {
  card::Deck deck;

  EXPECT_EQ(static_cast<int>(deck.size()), 52);
}

TEST_F(TestDeck, TestDeck2) {
  card::Deck deck;

  deck.shuffle();

  pile::Tableau tableau{1};
  tableau.put(deck.get(1));

  EXPECT_EQ(static_cast<int>(deck.size()), 51);
  EXPECT_EQ(static_cast<int>(tableau.size()), 1);
}

TEST_F(TestDeck, TestDeck3) {
  card::Deck deck;

  deck.shuffle();

  pile::Tableau tableau1{1};
  tableau1.put(deck.get(1));

  pile::Tableau tableau2{2};
  tableau2.put(deck.get(2));

  EXPECT_EQ(static_cast<int>(deck.size()), 49);
  EXPECT_EQ(static_cast<int>(tableau1.size()), 1);
  EXPECT_EQ(static_cast<int>(tableau2.size()), 2);
}
