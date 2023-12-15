#include "graphics.hpp"
#include "image.hpp"

namespace CPPTest::DesignPatterns {
Graphics::Graphics(const std::shared_ptr<ImageItf> &image) {
  m_images.push_back(image);
}

void Graphics::draw() {
  for (const auto &image : m_images)
    image->draw();
}
void Graphics::add_file(const std::shared_ptr<ImageItf> &image) {
  m_images.push_back(image);
}
} // namespace CPPTest::DesignPatterns