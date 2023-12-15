#pragma once

#include "image_itf.hpp"
#include <string>

namespace CPPTest::DesignPatterns {
class Image : public ImageItf {
public:
  explicit Image(std::string filename);
  void draw() override;

private:
  std::string m_filename;
};
} // namespace CPPTest::DesignPatterns