#include "graphics.hpp"

namespace CPPTest::DesignPatterns {
Graphics::Graphics(const std::shared_ptr<ImageItf> &image) : m_image{image} {}

void Graphics::draw() { m_image->draw(); }
} // namespace CPPTest::DesignPatterns