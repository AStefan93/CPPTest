#pragma once

namespace CPPTest::DesignPatterns {
class ImageItf {
public:
  ImageItf(const ImageItf &) = default;
  ImageItf(ImageItf &&) = delete;
  ImageItf &operator=(const ImageItf &) = default;
  ImageItf &operator=(ImageItf &&) = delete;
  virtual ~ImageItf() = default;
  virtual void draw() = 0;

protected:
  ImageItf() = default;
};
} // namespace CPPTest::DesignPatterns