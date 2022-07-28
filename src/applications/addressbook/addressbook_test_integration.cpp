#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>

#include "addressbook.hpp"

namespace CPPTest::Addressbook::Test {

class AddressbookIntegrationTest : public ::testing::Test {};

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST_F(AddressbookIntegrationTest, WhenMainCalledExpectOutputToStream) {
  send_addressbook();
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
}  // namespace CPPTest::Addressbook::Test