#include "testboard.hpp"
#include "libgame/board.hpp"

TestBoard::TestBoard() {}

TestBoard::~TestBoard(){};

TEST_F(TestBoard, TestBoard1) {
  game::Board board;

  EXPECT_EQ(static_cast<int>(board.size()), 13);
}

TEST_F(TestBoard, TestBoard2) {
  game::Board board;
  card::Deck deck;

  deck.shuffle();
  board.deal(deck);
  EXPECT_EQ(static_cast<int>(deck.size()), 0);
}
