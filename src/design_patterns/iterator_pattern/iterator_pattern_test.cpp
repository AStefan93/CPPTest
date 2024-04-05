#include "iterator_pattern.hpp"
#include "gtest/gtest.h"

namespace CPPTest::DesignPatterns::Test {
class IteratorPatternTest : public ::testing::Test {
protected:
  // NOLINTNEXTLINE
  Collection m_cut;
  std::shared_ptr<Iterator> m_iterator;
};

TEST_F(IteratorPatternTest, EvenNumbers) {
  m_iterator = m_cut.create_iterator();
  std::vector<int> even_numbers;
  while (m_iterator->has_next()) {
    even_numbers.push_back(m_iterator->next());
  }

  std::vector<int> expected_even_numbers = {0, 0, 2, 0, 4,
                                            0, 6, 0, 8, 0}; // NOLINT
  EXPECT_EQ(even_numbers, expected_even_numbers);
}

TEST_F(IteratorPatternTest, OddNumbers) {
  m_iterator = m_cut.create_iterator(false);
  std::vector<int> even_numbers;
  while (m_iterator->has_next()) {
    even_numbers.push_back(m_iterator->next());
  }

  std::vector<int> expected_even_numbers = {0, 1, 0, 3, 0,
                                            5, 0, 7, 0, 9}; // NOLINT
  EXPECT_EQ(even_numbers, expected_even_numbers);
}

} // namespace CPPTest::DesignPatterns::Test