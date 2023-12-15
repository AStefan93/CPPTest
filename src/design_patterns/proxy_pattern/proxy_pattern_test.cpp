#include "graphics.hpp"
#include "graphics_itf.hpp"
#include "image_proxy.hpp"
#include "gtest/gtest.h"
#include <memory>
namespace CPPTest::DesignPatterns::Test {

class AProxyPattern : public ::testing::Test {
public:
  AProxyPattern() {
    m_graphics =
        std::make_shared<Graphics>(std::make_shared<ImageProxy>("image.png"));
  }

protected:
  std::shared_ptr<GraphicsItf> m_graphics;
};

TEST_F(AProxyPattern, WithAProxyLoadsImageOnlyWhenDrawn) { m_graphics->draw(); }

} // namespace CPPTest::DesignPatterns::Test