#pragma once

#include <memory>
#include <vector>

#include "graphics_itf.hpp"

namespace CPPTest::DesignPatterns {
class ImageItf;
class Graphics : public GraphicsItf {
public:
  explicit Graphics(const std::shared_ptr<ImageItf> &image);
  void draw() override;
  void add_file(const std::shared_ptr<ImageItf> &image) override;

private:
  std::vector<std::shared_ptr<ImageItf>> m_images;
};
} // namespace CPPTest::DesignPatterns