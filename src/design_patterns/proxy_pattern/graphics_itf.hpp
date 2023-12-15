#pragma once
#include <memory>

namespace CPPTest::DesignPatterns {
class ImageItf;
class GraphicsItf {
public:
  GraphicsItf(const GraphicsItf &) = default;
  GraphicsItf(GraphicsItf &&) = delete;
  GraphicsItf &operator=(const GraphicsItf &) = default;
  GraphicsItf &operator=(GraphicsItf &&) = delete;
  virtual ~GraphicsItf() = default;
  virtual void draw() = 0;
  virtual void add_file(const std::shared_ptr<ImageItf> &image) = 0;

protected:
  GraphicsItf() = default;
};
} // namespace CPPTest::DesignPatterns