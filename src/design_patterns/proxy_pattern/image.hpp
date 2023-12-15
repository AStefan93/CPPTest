#pragma once

#include "image_itf.hpp"
#include <fstream>
#include <string>

namespace CPPTest::DesignPatterns {
class Image : public ImageItf {
public:
  explicit Image(std::string filename);
  void draw() override;

private:
  std::string m_filename;
  std::ofstream m_file;
};
} // namespace CPPTest::DesignPatterns