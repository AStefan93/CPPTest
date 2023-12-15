#include "image_proxy.hpp"
#include <string>

namespace CPPTest::DesignPatterns {
ImageProxy::ImageProxy(std::string filename)
    : m_filename{std::move(filename)} {}

void ImageProxy::draw() {
  if (not m_image)
    m_image = std::make_shared<Image>(m_filename);
  m_image->draw();
}
} // namespace CPPTest::DesignPatterns