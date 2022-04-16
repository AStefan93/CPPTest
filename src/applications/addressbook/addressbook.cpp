#include "addressbook.hpp"

#include "external_interface/addressbook/addressbook.pb.h"
namespace CPPTest::Addressbook {

void john_doe(tutorial::Person* foo_person) {
  foo_person->set_name("John Doe");
  foo_person->set_email("john.doe@test.com");
  foo_person->set_id(1);
}

void joe_smith(tutorial::Person* foo_person) {
  foo_person->set_name("Joe Smith");
  foo_person->set_email("Joe.Smith@test.com");
  foo_person->set_id(2);
}

void send_addressbook() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  tutorial::AddressBook address_book;
  john_doe(address_book.add_people());
  john_doe(address_book.add_people());
  joe_smith(address_book.add_people());

  address_book.SerializeToOstream(&std::cout);
}
}  // namespace CPPTest::Addressbook