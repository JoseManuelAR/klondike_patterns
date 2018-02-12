#include "testmovement.hpp"
#include "libcommand/movement.hpp"
#include "libpile/foundation.hpp"
#include "libpile/tableau.hpp"
#include "libpile/waste.hpp"

TestMovement::TestMovement() {}

TestMovement::~TestMovement(){};

// T --> T
/*TEST_F(TestMovement, Tableau2Tableau1) {
  pile::Tableau tableau1{1,
                         {{card::Value::Three, card::Suit::Heart, true},
                          {card::Value::King, card::Suit::Spade},
                          {card::Value::Ace, card::Suit::Spade}}};
  pile::Tableau tableau2{2,
                         {{card::Value::Four, card::Suit::Club, true},
                          {card::Value::Ace, card::Suit::Club}}};

  command::Movement movement;
  movement.configureParameters({{"T1"}, {"T2"}});
  EXPECT_EQ(static_cast<int>(tableau1.size()), 3);
  EXPECT_EQ(static_cast<int>(tableau2.size()), 2);
  EXPECT_EQ(movement.execute(), true);
  EXPECT_EQ(static_cast<int>(tableau1.size()), 2);
  EXPECT_EQ(static_cast<int>(tableau2.size()), 3);
}

/*TEST_F(TestMovement, Tableau2Tableau2) {
  pile::Tableau tableau1{1,
                         {{card::Value::Two, card::Suit::Spade, true},
                          {card::Value::Three, card::Suit::Heart, true},
                          {card::Value::Ace, card::Suit::Spade}}};
  pile::Tableau tableau2{2,
                         {{card::Value::Four, card::Suit::Club, true},
                          {card::Value::Ace, card::Suit::Club}}};

  EXPECT_EQ(static_cast<int>(tableau1.size()), 3);
  EXPECT_EQ(static_cast<int>(tableau2.size()), 2);
  command::Movement movement(tableau1, tableau2, 2);
  EXPECT_EQ(movement.execute(), true);
  EXPECT_EQ(static_cast<int>(tableau1.size()), 1);
  EXPECT_EQ(static_cast<int>(tableau2.size()), 4);
}

TEST_F(TestMovement, Tableau2Tableau3) {
  pile::Tableau tableau1{1};
  pile::Tableau tableau2{2,
                         {{card::Value::Five, card::Suit::Club, true},
                          {card::Value::Ace, card::Suit::Club}}};

  EXPECT_EQ(static_cast<int>(tableau1.size()), 0);
  EXPECT_EQ(static_cast<int>(tableau2.size()), 2);
  command::Movement movement(tableau1, tableau2, 1);
  EXPECT_EQ(movement.execute(), false);
  EXPECT_EQ(static_cast<int>(tableau1.size()), 0);
  EXPECT_EQ(static_cast<int>(tableau2.size()), 2);
}

TEST_F(TestMovement, Tableau2Tableau4) {
  pile::Tableau tableau1{1,
                         {{card::Value::Three, card::Suit::Heart, true},
                          {card::Value::King, card::Suit::Spade},
                          {card::Value::Ace, card::Suit::Spade}}};
  pile::Tableau tableau2{2,
                         {{card::Value::Five, card::Suit::Club, true},
                          {card::Value::Ace, card::Suit::Club}}};

  EXPECT_EQ(static_cast<int>(tableau1.size()), 3);
  EXPECT_EQ(static_cast<int>(tableau2.size()), 2);
  command::Movement movement(tableau1, tableau2, 1);
  EXPECT_EQ(movement.execute(), false);
  EXPECT_EQ(static_cast<int>(tableau1.size()), 3);
  EXPECT_EQ(static_cast<int>(tableau2.size()), 2);
}

// T --> F
TEST_F(TestMovement, Tableau2Foundation1) {
  pile::Tableau tableau{1,
                        {{card::Value::Ace, card::Suit::Heart, true},
                         {card::Value::King, card::Suit::Spade},
                         {card::Value::Ace, card::Suit::Spade}}};
  pile::Foundation foundation{1};

  EXPECT_EQ(static_cast<int>(tableau.size()), 3);
  EXPECT_EQ(static_cast<int>(foundation.size()), 0);
  command::Movement movement(tableau, foundation, 1);
  EXPECT_EQ(movement.execute(), true);
  EXPECT_EQ(static_cast<int>(tableau.size()), 2);
  EXPECT_EQ(static_cast<int>(foundation.size()), 1);
}

TEST_F(TestMovement, Tableau2Foundation2) {
  pile::Tableau tableau{1,
                        {{card::Value::King, card::Suit::Heart, true},
                         {card::Value::King, card::Suit::Spade},
                         {card::Value::Ace, card::Suit::Spade}}};
  pile::Foundation foundation{1};

  EXPECT_EQ(static_cast<int>(tableau.size()), 3);
  EXPECT_EQ(static_cast<int>(foundation.size()), 0);
  command::Movement movement(tableau, foundation, 1);
  EXPECT_EQ(movement.execute(), false);
  EXPECT_EQ(static_cast<int>(tableau.size()), 3);
  EXPECT_EQ(static_cast<int>(foundation.size()), 0);
}

TEST_F(TestMovement, Tableau2Foundation3) {
  pile::Tableau tableau{1,
                        {{card::Value::Two, card::Suit::Heart, true},
                         {card::Value::King, card::Suit::Spade},
                         {card::Value::Ace, card::Suit::Spade}}};
  pile::Foundation foundation{1, {{card::Value::Ace, card::Suit::Heart, true}}};

  EXPECT_EQ(static_cast<int>(tableau.size()), 3);
  EXPECT_EQ(static_cast<int>(foundation.size()), 1);
  command::Movement movement(tableau, foundation, 1);
  EXPECT_EQ(movement.execute(), true);
  EXPECT_EQ(static_cast<int>(tableau.size()), 2);
  EXPECT_EQ(static_cast<int>(foundation.size()), 2);
}

TEST_F(TestMovement, Tableau2Foundation4) {
  pile::Tableau tableau{1,
                        {{card::Value::Four, card::Suit::Heart, true},
                         {card::Value::King, card::Suit::Spade},
                         {card::Value::Ace, card::Suit::Spade}}};
  pile::Foundation foundation{1, {{card::Value::Ace, card::Suit::Heart, true}}};

  EXPECT_EQ(static_cast<int>(tableau.size()), 3);
  EXPECT_EQ(static_cast<int>(foundation.size()), 1);
  command::Movement movement(tableau, foundation, 1);
  EXPECT_EQ(movement.execute(), false);
  EXPECT_EQ(static_cast<int>(tableau.size()), 3);
  EXPECT_EQ(static_cast<int>(foundation.size()), 1);
}

// F --> T
TEST_F(TestMovement, Foundation2Tableau1) {
  pile::Foundation foundation{1,
                              {{card::Value::Two, card::Suit::Heart, true},
                               {card::Value::Ace, card::Suit::Heart, true}}};
  pile::Tableau tableau{1, {{card::Value::Three, card::Suit::Spade, true}}};

  EXPECT_EQ(static_cast<int>(foundation.size()), 2);
  EXPECT_EQ(static_cast<int>(tableau.size()), 1);
  command::Movement movement(foundation, tableau, 1);
  EXPECT_EQ(movement.execute(), true);
  EXPECT_EQ(static_cast<int>(foundation.size()), 1);
  EXPECT_EQ(static_cast<int>(tableau.size()), 2);
}

TEST_F(TestMovement, Foundation2Tableau2) {
  pile::Foundation foundation{1,
                              {{card::Value::Two, card::Suit::Heart, true},
                               {card::Value::Ace, card::Suit::Heart, true}}};
  pile::Tableau tableau{1, {{card::Value::Three, card::Suit::Spade, true}}};

  EXPECT_EQ(static_cast<int>(foundation.size()), 2);
  EXPECT_EQ(static_cast<int>(tableau.size()), 1);
  command::Movement movement(foundation, tableau, 2);
  EXPECT_EQ(movement.execute(), false);
  EXPECT_EQ(static_cast<int>(foundation.size()), 2);
  EXPECT_EQ(static_cast<int>(tableau.size()), 1);
}

TEST_F(TestMovement, Foundation2Tableau3) {
  pile::Foundation foundation{1,
                              {{card::Value::Two, card::Suit::Heart, true},
                               {card::Value::Ace, card::Suit::Heart, true}}};
  pile::Tableau tableau{1, {{card::Value::Four, card::Suit::Spade, true}}};

  EXPECT_EQ(static_cast<int>(foundation.size()), 2);
  EXPECT_EQ(static_cast<int>(tableau.size()), 1);
  command::Movement movement(foundation, tableau, 1);
  EXPECT_EQ(movement.execute(), false);
  EXPECT_EQ(static_cast<int>(foundation.size()), 2);
  EXPECT_EQ(static_cast<int>(tableau.size()), 1);
}

// W --> T
TEST_F(TestMovement, Waste2Tableau1) {
  pile::Waste waste{{{card::Value::Two, card::Suit::Heart, true},
                     {card::Value::Five, card::Suit::Club, true}}};
  pile::Tableau tableau{1, {{card::Value::Three, card::Suit::Spade, true}}};

  EXPECT_EQ(static_cast<int>(waste.size()), 2);
  EXPECT_EQ(static_cast<int>(tableau.size()), 1);
  command::Movement movement(waste, tableau, 1);
  EXPECT_EQ(movement.execute(), true);
  EXPECT_EQ(static_cast<int>(waste.size()), 1);
  EXPECT_EQ(static_cast<int>(tableau.size()), 2);
}

TEST_F(TestMovement, Waste2Tableau2) {
  pile::Waste waste{{{card::Value::Two, card::Suit::Heart, true},
                     {card::Value::Five, card::Suit::Club, true}}};
  pile::Tableau tableau{1, {{card::Value::Three, card::Suit::Spade, true}}};

  EXPECT_EQ(static_cast<int>(waste.size()), 2);
  EXPECT_EQ(static_cast<int>(tableau.size()), 1);
  command::Movement movement(waste, tableau, 2);
  EXPECT_EQ(movement.execute(), false);
  EXPECT_EQ(static_cast<int>(waste.size()), 2);
  EXPECT_EQ(static_cast<int>(tableau.size()), 1);
}

TEST_F(TestMovement, Waste2Tableau3) {
  pile::Waste waste{};
  pile::Tableau tableau{1, {{card::Value::Three, card::Suit::Spade, true}}};

  EXPECT_EQ(static_cast<int>(waste.size()), 0);
  EXPECT_EQ(static_cast<int>(tableau.size()), 1);
  command::Movement movement(waste, tableau, 1);
  EXPECT_EQ(movement.execute(), false);
  EXPECT_EQ(static_cast<int>(waste.size()), 0);
  EXPECT_EQ(static_cast<int>(tableau.size()), 1);
}

TEST_F(TestMovement, Waste2Tableau4) {
  pile::Waste waste{{{card::Value::Two, card::Suit::Heart, true},
                     {card::Value::Five, card::Suit::Club, true}}};
  pile::Tableau tableau{1, {{card::Value::Four, card::Suit::Spade, true}}};

  EXPECT_EQ(static_cast<int>(waste.size()), 2);
  EXPECT_EQ(static_cast<int>(tableau.size()), 1);
  command::Movement movement(waste, tableau, 1);
  EXPECT_EQ(movement.execute(), false);
  EXPECT_EQ(static_cast<int>(waste.size()), 2);
  EXPECT_EQ(static_cast<int>(tableau.size()), 1);
}*/
