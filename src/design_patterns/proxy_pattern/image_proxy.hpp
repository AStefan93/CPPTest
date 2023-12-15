#pragma once

#include "image_itf.hpp"
#include <memory>
#include <string>
namespace CPPTest::DesignPatterns {
class ImageProxy : public ImageItf {
public:
  explicit ImageProxy(std::string filename);
  void draw() override;

private:
  std::string m_filename;
  std::unique_ptr<ImageItf> m_image;
};
} // namespace CPPTest::DesignPatterns