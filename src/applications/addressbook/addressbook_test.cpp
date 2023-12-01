#include "addressbook.hpp"

#include <gmock/gmock-matchers.h>
#include <google/protobuf/message_lite.h>  // for ShutdownProtobufLibrary

#include <memory>  // for allocator, make_unique, unique_ptr
#include <string>  // for string

#include "gtest/gtest.h"  // for TestInfo, InitGoogleTest, Message, RUN_ALL_TESTS, TEST_F, TestPartResult
namespace CPPTest::Addressbook::Test {

// NOLINTNEXTLINE(cppcoreguidelines-special-member-functions)
class AddressbookTest : public ::testing::Test {
 public:
  AddressbookTest() { john_doe(m_foo_person.get()); }
  ~AddressbookTest() override { google::protobuf::ShutdownProtobufLibrary(); }

 protected:
  // NOLINTNEXTLINE (cppcoreguidelines-non-private-member-variables-in-classes)
  std::unique_ptr<tutorial::Person> m_foo_person{
      std::make_unique<tutorial::Person>()};
};

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST_F(AddressbookTest, WhenPersonIsSetExpectCorrectName) {
  const std::string expected_name = "John Doe";
  const auto actual_name = m_foo_person->name();
  EXPECT_THAT(expected_name, actual_name);
}

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST_F(AddressbookTest, WhenPersonIsSetExpectCorrectId) {
  constexpr auto expected_id = 1;
  const auto actual_id = m_foo_person->id();
  EXPECT_THAT(expected_id, actual_id);
}

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST_F(AddressbookTest, WhenPersonIsSetExpectCorrectEmail) {
  const std::string expected_email = "john.doe@test.com";
  const auto actual_email = m_foo_person->email();
  EXPECT_THAT(expected_email, actual_email);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
}  // namespace CPPTest::Addressbook::Test