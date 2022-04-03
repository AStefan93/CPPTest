#include "addressbook.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(Addressbook, WhenPersonIsSetExpectCorrectName) {
  tutorial::Person foo_person_object;
  tutorial::Person* foo_person = &foo_person_object;
  john_doe(foo_person);

  const std::string expected_name = "John Doe";
  const auto actual_name = foo_person->name();
  EXPECT_THAT(expected_name, actual_name);
}

TEST(Addressbook, WhenPersonIsSetExpectCorrectId) {
  tutorial::Person foo_person_object;
  tutorial::Person* foo_person = &foo_person_object;
  john_doe(foo_person);

  constexpr auto expected_id = 1;
  const auto actual_id = foo_person->id();
  EXPECT_THAT(expected_id, actual_id);
}

TEST(Addressbook, WhenPersonIsSetExpectCorrectEmail) {
  tutorial::Person foo_person_object;
  tutorial::Person* foo_person = &foo_person_object;
  john_doe(foo_person);

  const std::string expected_email = "john.doe@test.com";
  const auto actual_email = foo_person->email();
  EXPECT_THAT(expected_email, actual_email);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}