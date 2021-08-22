#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <algorithm>
#include <memory>

class Array {
 private:
  std::unique_ptr<int> m_ptr{nullptr};
  int m_size{0};

 public:
  Array() = default;
  ~Array() = default;
  explicit Array(int size);
  int size() const;
  bool empty() const;

  bool IsValidIndex(int index) const;

  int &operator[](int index);
  int operator[](int index) const;
};

#endif  // TEST_HPP