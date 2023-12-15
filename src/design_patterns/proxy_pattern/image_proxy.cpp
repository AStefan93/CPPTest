#include "image_proxy.hpp"
#include "image.hpp"
#include <string>

namespace CPPTest::DesignPatterns {
ImageProxy::ImageProxy(std::string filename)
    : m_filename{std::move(filename)} {}

void ImageProxy::draw() {
  if (!m_image)
    m_image = std::make_unique<Image>(m_filename);
  m_image->draw();
}
} // namespace CPPTest::DesignPatterns