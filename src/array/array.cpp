#include "array.hpp"

#include <exception>
#include <iostream>
#include <stdexcept>

Array::Array(int size) {
  if (size != 0) {
    m_ptr = std::make_unique<int>(size);
    m_size = size;
  }
}
int Array::size() const { return m_size; }
bool Array::empty() const { return (m_size == 0); }
bool Array::IsValidIndex(int index) const {
  return (index >= 0) && (index < m_size);
};

int &Array::operator[](int index) {
  if (!IsValidIndex(index)) {
    throw std::runtime_error("Index out of bounds.");
  }
  return m_ptr.get()[index];
}
int Array::operator[](int index) const {
  if (!IsValidIndex(index)) {
    throw std::runtime_error("Index out of bounds.");
  }
  return m_ptr.get()[index];
}