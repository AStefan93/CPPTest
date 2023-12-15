#pragma once

#include <memory>

#include "graphics_itf.hpp"
#include "image_itf.hpp"

namespace CPPTest::DesignPatterns {
class Graphics : public GraphicsItf {
public:
  explicit Graphics(const std::shared_ptr<ImageItf> &image);
  void draw() override;

private:
  std::shared_ptr<ImageItf> m_image;
};
} // namespace CPPTest::DesignPatterns