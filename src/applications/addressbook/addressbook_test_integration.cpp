#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>

#include "addressbook.hpp"
namespace CPPTest::Addressbook::Test {

class AddressbookIntegrationTest : public ::testing::Test {};

TEST_F(AddressbookIntegrationTest, WhenMainCalledExpectOutputToStream) {
  addressbook_main();
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
}  // namespace CPPTest::Addressbook::Test