#include "array.hpp"

#include <iostream>

Array::Array(int size) {
  if (size != 0) {
    m_ptr = std::make_unique<int>(size);
    m_size = size;
  }
}
int Array::size() const { return m_size; }
bool Array::empty() const { return (m_size == 0); }