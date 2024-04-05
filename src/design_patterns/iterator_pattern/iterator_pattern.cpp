#include "iterator_pattern.hpp"
#include <memory>

namespace CPPTest::DesignPatterns {

std::shared_ptr<Iterator> Collection::create_iterator(bool isEven) const {
  if (isEven)
    return std::make_shared<EvenNumbersIterator>(
        std::make_shared<std::vector<int>>(m_vector));

  return std::make_shared<OddNumbersIterator>(
      std::make_shared<std::vector<int>>(m_vector));
}

int EvenNumbersIterator::next() {
  if (m_index < m_vector->size()) {
    const int value = m_vector->at(m_index);
    m_index++;
    if (value % 2 == 0) {
      return value;
    }
  }
  return 0;
}

bool EvenNumbersIterator::has_next() { return m_index < m_vector->size(); }

int OddNumbersIterator::next() {
  if (m_index < m_vector->size()) {
    const int value = m_vector->at(m_index);
    m_index++;
    if (value % 2 == 1)
      return value;
  }
  return 0;
}

bool OddNumbersIterator::has_next() { return m_index < m_vector->size(); }
} // namespace CPPTest::DesignPatterns