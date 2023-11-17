#include "command_pattern.hpp"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace CPPTest::DesignPatterns::Test {

class MockDocument : public File {
 public:
  MOCK_METHOD(void, paste, (), (override));
  MOCK_METHOD(void, cut, (), (override));
  MOCK_METHOD(void, copy, (), (override));
};

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(CommandPattern, paste) {
  const auto document = std::make_shared<MockDocument>();
  Paste cut(document);

  EXPECT_CALL(*document, paste()).Times(1);
  cut.execute();
}

}  // namespace CPPTest::DesignPatterns::Test