#pragma once

#include "image.hpp"
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
  std::shared_ptr<Image> m_image;
};
} // namespace CPPTest::DesignPatterns