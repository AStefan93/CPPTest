#pragma once

#include <memory>
#include <vector>
namespace CPPTest::DesignPatterns {

class Iterator {
public:
  Iterator(const Iterator &) = default;
  Iterator(Iterator &&) = delete;
  Iterator &operator=(const Iterator &) = default;
  Iterator &operator=(Iterator &&) = delete;
  virtual ~Iterator() = default;
  virtual int next() = 0;
  virtual bool has_next() = 0;

protected:
  Iterator() = default;
};

class Collection {
public:
  [[nodiscard]] std::shared_ptr<Iterator> create_iterator(bool = true) const;

private:
  // NOLINTNEXTLINE
  std::vector<int> m_vector = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
};

class EvenNumbersIterator : public Iterator {

public:
  explicit EvenNumbersIterator(std::shared_ptr<std::vector<int>> vector)
      : m_vector(std::move(vector)) {}
  int next() override;
  bool has_next() override;

private:
  size_t m_index = 0;
  std::shared_ptr<std::vector<int>> m_vector;
};

class OddNumbersIterator : public Iterator {

public:
  explicit OddNumbersIterator(std::shared_ptr<std::vector<int>> vector)
      : m_vector(std::move(vector)) {}
  int next() override;
  bool has_next() override;

private:
  size_t m_index = 0;
  std::shared_ptr<std::vector<int>> m_vector;
};

} // namespace CPPTest::DesignPatterns