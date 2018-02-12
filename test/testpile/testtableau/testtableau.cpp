#include "testtableau.hpp"
#include "libpile/tableau.hpp"

TestTableau::TestTableau() {}

TestTableau::~TestTableau(){};

TEST_F(TestTableau, GivenEmptyTableau_ThenEmptyTrue) {
  pile::Tableau tableau{1};

  EXPECT_EQ(tableau.empty(), true);
}
