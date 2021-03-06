#include "addressbook.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>
namespace CPPTest::Addressbook::Test {

class AddressbookTest : public ::testing::Test {
  void SetUp() override { john_doe(m_foo_person.get()); }
  void TearDown() override { google::protobuf::ShutdownProtobufLibrary(); }

 protected:
  // NOLINTNEXTLINE (cppcoreguidelines-non-private-member-variables-in-classes)
  std::unique_ptr<tutorial::Person> m_foo_person{
      std::make_unique<tutorial::Person>()};
};

TEST_F(AddressbookTest, WhenPersonIsSetExpectCorrectName) {
  const std::string expected_name = "John Doe";
  const auto actual_name = m_foo_person->name();
  EXPECT_THAT(expected_name, actual_name);
}

TEST_F(AddressbookTest, WhenPersonIsSetExpectCorrectId) {
  constexpr auto expected_id = 1;
  const auto actual_id = m_foo_person->id();
  EXPECT_THAT(expected_id, actual_id);
}

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