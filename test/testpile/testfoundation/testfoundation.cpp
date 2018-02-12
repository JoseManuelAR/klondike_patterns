#include "testfoundation.hpp"
#include "libpile/foundation.hpp"

TestFoundation::TestFoundation() {}

TestFoundation::~TestFoundation(){};

TEST_F(TestFoundation, TestFoundation_CreateFoundation_Empty) {
  pile::Foundation foundation{1};

  EXPECT_EQ(static_cast<int>(foundation.empty()), true);
}

TEST_F(TestFoundation, TestFoundation_FoundationEmpty_Put1CardAce_ReturnEmpty) {
  pile::Foundation foundation{1};

  EXPECT_EQ(foundation.put({{{card::Value::Ace, card::Suit::Heart, true}}}),
            true);
  EXPECT_EQ(static_cast<int>(foundation.size()), 1);
}

TEST_F(TestFoundation, TestFoundation_FoundationEmpty_Put1CardTwo_Return1Card) {
  pile::Foundation foundation{1};

  EXPECT_EQ(foundation.put({{{card::Value::Two, card::Suit::Heart, true}}}),
            false);
  EXPECT_EQ(static_cast<int>(foundation.size()), 0);
}

TEST_F(TestFoundation, TestFoundation_FoundationEmpty_Put2Cards_Return2Cards) {
  pile::Foundation foundation{1};

  EXPECT_EQ(foundation.put({{{card::Value::Ace, card::Suit::Heart, true},
                             {card::Value::Two, card::Suit::Heart, true}}}),
            false);
  EXPECT_EQ(static_cast<int>(foundation.size()), 0);
}

TEST_F(TestFoundation, TestFoundation_Foundation_PutCards_Ok) {
  pile::Foundation foundation{1};

  EXPECT_EQ(foundation.put({{{card::Value::Ace, card::Suit::Heart, true}}}),
            true);
  EXPECT_EQ(static_cast<int>(foundation.size()), 1);
  EXPECT_EQ(foundation.put({{{card::Value::Two, card::Suit::Heart, true}}}),
            true);
  EXPECT_EQ(static_cast<int>(foundation.size()), 2);
}

TEST_F(TestFoundation, TestFoundation_Foundation_PutCards_Error) {
  pile::Foundation foundation{1};

  EXPECT_EQ(foundation.put({{{card::Value::Ace, card::Suit::Heart, true}}}),
            true);
  EXPECT_EQ(static_cast<int>(foundation.size()), 1);
  EXPECT_EQ(foundation.put({{{card::Value::Three, card::Suit::Heart, true}}}),
            false);
  EXPECT_EQ(static_cast<int>(foundation.size()), 1);
}

TEST_F(TestFoundation, TestFoundation_Get1_Empty) {
  pile::Foundation foundation{1};

  card::Cards cards = foundation.get(1);
  EXPECT_EQ(static_cast<int>(cards.empty()), true);
  EXPECT_EQ(static_cast<int>(foundation.empty()), true);
}

TEST_F(TestFoundation, TestFoundation_Get1_Return1_Size0) {
  pile::Foundation foundation{1};

  foundation.put({{{card::Value::Ace, card::Suit::Heart, true}}});
  card::Cards cards = foundation.get(1);
  EXPECT_EQ(static_cast<int>(cards.size()), 1);
  EXPECT_EQ(static_cast<int>(foundation.size()), 0);
}

TEST_F(TestFoundation, TestFoundation_Get1_Return1_Size1) {
  pile::Foundation foundation{1};

  EXPECT_EQ(foundation.put({{{card::Value::Ace, card::Suit::Heart, true}}}),
            true);
  EXPECT_EQ(static_cast<int>(foundation.size()), 1);
  EXPECT_EQ(foundation.put({{{card::Value::Two, card::Suit::Heart, true}}}),
            true);
  EXPECT_EQ(static_cast<int>(foundation.size()), 2);

  card::Cards cards = foundation.get(1);
  EXPECT_EQ(static_cast<int>(cards.size()), 1);
  EXPECT_EQ(static_cast<int>(foundation.size()), 1);
}

TEST_F(TestFoundation, TestFoundation_Empty_Restore_Size1) {
  pile::Foundation foundation{1};

  foundation.restore({{{card::Value::Ace, card::Suit::Heart, true}}});
  EXPECT_EQ(static_cast<int>(foundation.size()), 1);
}

TEST_F(TestFoundation, TestFoundation_Empty_Restore_Size2) {
  pile::Foundation foundation{1};

  foundation.put({{{card::Value::Ace, card::Suit::Heart, true}}});
  foundation.restore({{{card::Value::Two, card::Suit::Heart, true}}});
  EXPECT_EQ(static_cast<int>(foundation.size()), 2);
}
