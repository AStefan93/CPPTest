#include "image.hpp"
#include <string>

namespace CPPTest::DesignPatterns {
Image::Image(std::string filename) : m_filename{std::move(filename)} {
  m_file.open(m_filename);
  if (!m_file.is_open())
    throw std::runtime_error(
        "Couldn not open file: " + m_filename +
        "\n Current read state: " + std::to_string(m_file.rdstate()));
}

void Image::draw() {}
} // namespace CPPTest::DesignPatterns