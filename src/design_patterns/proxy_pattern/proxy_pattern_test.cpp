#include "graphics.hpp"
#include "graphics_itf.hpp"
#include "image.hpp"
#include "image_proxy.hpp"
#include "gtest/gtest.h"
#include <memory>
#include <string>

namespace CPPTest::DesignPatterns::Test {

// const std::string DATA_FILES_PATH = "/workspace/CPPTest/test_files/";

class AProxyPattern : public ::testing::Test {
public:
  AProxyPattern() {
    m_graphics =
        std::make_shared<Graphics>(std::make_shared<ImageProxy>("image_0.txt"));
  }

protected:
  // NOLINTNEXTLINE: (misc-non-private-member-variables-in-classes)
  std::shared_ptr<GraphicsItf> m_graphics;
};

TEST_F(AProxyPattern, WithAProxyLoadsImageOnlyWhenDrawn) {
  EXPECT_NO_THROW(m_graphics->draw());
}
TEST_F(AProxyPattern, WithMultipleProxiesDoesNotLoadFiles) {

  constexpr auto number_of_files = 20'000;
  for (auto i = 0; i < number_of_files; ++i) {
    const std::shared_ptr<ImageItf> image_proxy =
        std::make_shared<ImageProxy>("image_0.txt");
    EXPECT_NO_THROW(m_graphics->add_file(image_proxy));
  }
}

TEST_F(AProxyPattern, WithMultipleProxiesLoadsAllFilesWhenDrawn) {

  constexpr auto number_of_files = 10'000;
  for (auto i = 0; i < number_of_files; ++i) {
    const std::shared_ptr<ImageItf> image_proxy =
        std::make_shared<ImageProxy>("image_0.txt");
    EXPECT_NO_THROW(m_graphics->add_file(image_proxy));
  }
  EXPECT_NO_THROW(m_graphics->draw());
}

class AnImage : public ::testing::Test {
public:
  AnImage() { m_image = std::make_shared<Image>("image_0.txt"); }

protected:
  // NOLINTNEXTLINE: (misc-non-private-member-variables-in-classes)
  std::shared_ptr<Image> m_image;
};

TEST_F(AnImage, LoadsImageOnlyWhenDrawn) {
  EXPECT_NO_THROW(m_image->draw("Dummy text."));
}

} // namespace CPPTest::DesignPatterns::Test