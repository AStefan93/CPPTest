#include "addressbook.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(Addressbook, WhenPersonIsSetExpectCorrectName) {
  const auto person = addressbook_main();

  const std::string expected_name = "John Doe";
  const auto actual_name = person.name();
  EXPECT_THAT(expected_name, actual_name);
}

TEST(Addressbook, WhenPersonIsSetExpectCorrectId) {
  const auto actual_name = addressbook_main();

  constexpr auto expected_id = 1;
  const auto actual_id = actual_name.id();
  EXPECT_THAT(expected_id, actual_id);
}

TEST(Addressbook, WhenPersonIsSetExpectCorrectEmail) {
  const auto person = addressbook_main();

  const std::string expected_email = "john.doe@test.com";
  const auto actual_email = person.email();
  EXPECT_THAT(expected_email, actual_email);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}