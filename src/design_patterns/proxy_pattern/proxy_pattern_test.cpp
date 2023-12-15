#include "graphics.hpp"
#include "graphics_itf.hpp"
#include "image.hpp"
#include "image_proxy.hpp"
#include "gtest/gtest.h"
#include <memory>
namespace CPPTest::DesignPatterns::Test {

class AProxyPattern : public ::testing::Test {
public:
  AProxyPattern() {
    m_graphics = std::make_shared<Graphics>(std::make_shared<ImageProxy>(
        "/workspace/CPPTest/test_files/image_0.txt"));
  }

protected:
  // NOLINTNEXTLINE: (misc-non-private-member-variables-in-classes)
  std::shared_ptr<GraphicsItf> m_graphics;
};

TEST_F(AProxyPattern, WithAProxyLoadsImageOnlyWhenDrawn) { m_graphics->draw(); }
TEST_F(AProxyPattern, WithMultipleProxiesDoesNotLoadFiles) {

  const std::shared_ptr<ImageItf> image_proxy1 =
      std::make_shared<ImageProxy>("/workspace/CPPTest/test_files/image_1.txt");
  const std::shared_ptr<ImageItf> image_proxy2 =
      std::make_shared<ImageProxy>("/workspace/CPPTest/test_files/image_2.txt");
  const std::shared_ptr<ImageItf> image_proxy3 =
      std::make_shared<ImageProxy>("/workspace/CPPTest/test_files/image_3.txt");
  m_graphics->add_file(image_proxy1);
  m_graphics->add_file(image_proxy2);
  m_graphics->add_file(image_proxy3);
}

TEST_F(AProxyPattern, WithMultipleProxiesLoadsAllFilesWhenDrawn) {

  const std::shared_ptr<ImageItf> image_proxy1 =
      std::make_shared<ImageProxy>("/workspace/CPPTest/test_files/image_1.txt");
  const std::shared_ptr<ImageItf> image_proxy2 =
      std::make_shared<ImageProxy>("/workspace/CPPTest/test_files/image_2.txt");
  const std::shared_ptr<ImageItf> image_proxy3 =
      std::make_shared<ImageProxy>("/workspace/CPPTest/test_files/image_3.txt");
  m_graphics->add_file(image_proxy1);
  m_graphics->add_file(image_proxy2);
  m_graphics->add_file(image_proxy3);
  m_graphics->draw();
}

class AnImage : public ::testing::Test {
public:
  AnImage() {
    m_image =
        std::make_shared<Image>("/workspace/CPPTest/test_files/image_0.txt");
  }

protected:
  // NOLINTNEXTLINE: (misc-non-private-member-variables-in-classes)
  std::shared_ptr<ImageItf> m_image;
};

TEST_F(AnImage, LoadsImageOnlyWhenDrawn) { EXPECT_NO_THROW(m_image->draw()); }

} // namespace CPPTest::DesignPatterns::Test