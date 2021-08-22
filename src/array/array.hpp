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
  explicit Array(int size);
  int size() const;
  bool empty() const;
};

#endif  // TEST_HPP