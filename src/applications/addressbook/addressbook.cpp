#include "addressbook.hpp"

#include "external_interface/addressbook/addressbook.pb.h"

void john_doe(tutorial::Person* foo_person) {
  foo_person->set_name("John Doe");
  foo_person->set_email("john.doe@test.com");
  foo_person->set_id(1);
}

void addressbook_main() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  tutorial::AddressBook address_book;
  john_doe(address_book.add_people());
}