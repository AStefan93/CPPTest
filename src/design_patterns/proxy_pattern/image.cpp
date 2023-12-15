#include "image.hpp"

namespace CPPTest::DesignPatterns {
Image::Image(std::string filename) : m_filename{std::move(filename)} {}

void Image::draw() {}
} // namespace CPPTest::DesignPatterns