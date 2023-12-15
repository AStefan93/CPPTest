#include "image.hpp"
#include <string>

namespace CPPTest::DesignPatterns {
Image::Image(std::string filename) : m_filename{std::move(filename)} {
  m_file.open(m_filename);
  if (!m_file.is_open())
    throw std::runtime_error(
        "Could not open file: " + m_filename +
        "\n Current read state: " + std::to_string(m_file.rdstate()));
}

void Image::draw() {}

void Image::draw(const std::string &text) {
  if (m_file.is_open()) {
    m_file << text;
  } else {
    throw std::runtime_error("File is not open: " + m_filename);
  }
}
} // namespace CPPTest::DesignPatterns