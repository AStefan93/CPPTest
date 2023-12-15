#pragma once

namespace CPPTest::DesignPatterns {
class GraphicsItf {
public:
  GraphicsItf(const GraphicsItf &) = default;
  GraphicsItf(GraphicsItf &&) = delete;
  GraphicsItf &operator=(const GraphicsItf &) = default;
  GraphicsItf &operator=(GraphicsItf &&) = delete;
  virtual ~GraphicsItf() = default;
  virtual void draw() = 0;

protected:
  GraphicsItf() = default;
};
} // namespace CPPTest::DesignPatterns