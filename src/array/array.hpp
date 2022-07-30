#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <memory>
#include <stdexcept>

namespace CPPTest::Array {

/**
 * @brief
 *
 * @tparam T
 */
template <typename T>
class Array {
 private:
  // NOLINTNEXTLINE (cppcoreguidelines-avoid-c-arrays)
  std::unique_ptr<T[]> m_ptr{nullptr};
  T m_size{0};

  bool is_valid_index(T index) const {
    return (index >= 0) && (index < m_size);
  }

 public:
  Array() = default;
  Array(const Array &source) {
    if (!source.empty()) {
      m_size = source.size();
      // NOLINTNEXTLINE (cppcoreguidelines-avoid-c-arrays)
      m_ptr = std::make_unique<T[]>(m_size);
      for (T i = 0; i < source.size(); i++) {
        m_ptr.get()[i] = source.m_ptr.get()[i];
      }
    }
    std::cout << "COPY CONSTRUCTOR CALLED" << std::endl;
  }
  Array(Array &&source) noexcept {
    if (!source.empty()) {
      m_size = std::move(source.m_size);
      m_ptr = std::move(source.m_ptr);
    }
    std::cout << "MOVE CONSTRUCTOR CALLED" << std::endl;
  }
  ~Array() = default;
  explicit Array(T size) {
    if (size != 0) {
      // NOLINTNEXTLINE (cppcoreguidelines-avoid-c-arrays)
      m_ptr = std::make_unique<T[]>(size);
      m_size = size;
    }
    std::cout << "CONSTRUCTOR CALLED" << std::endl;
  }
  T size() const { return m_size; };
  [[nodiscard]] bool empty() const { return (m_size == 0); }
  T &operator[](T index) {
    if (!is_valid_index(index)) {
      throw std::runtime_error("Index out of bounds.");
    }
    return m_ptr.get()[index];
  }
  T operator[](T index) const {
    if (!is_valid_index(index)) {
      throw std::runtime_error("Index out of bounds.");
    }
    return m_ptr.get()[index];
  }
  Array &operator=(const Array &source) {
    if (!source.empty()) {
      m_size = source.size();
      for (T i = 0; i < source.size(); i++) {
        m_ptr.get()[i] = source.m_ptr.get()[i];
      }
    }
    std::cout << "ASSIGNMENT CALLED" << std::endl;

    return *this;
  }
  Array &operator=(Array &&source) noexcept {
    if (!source.empty()) {
      m_size = source.m_size;
      m_ptr = std::move(source.m_ptr);
    }
    source.m_size = 0;
    std::cout << "MOVE ASSIGNMENT CALLED" << std::endl;
    return *this;
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &ostream, const Array<T> &input) {
  ostream << "[ ";
  for (int i = 0; i < input.size(); i++) {
    ostream << input[i] << ' ';
  }
  ostream << "]";
  return ostream;
}
}  // namespace CPPTest::Array

#endif  // ARRAY_HPP