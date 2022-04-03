#include "addressbook.hpp"

#include "external_interface/addressbook/addressbook.pb.h"

tutorial::Person addressbook_main() {
  tutorial::Person foo_person;
  foo_person.set_name("John Doe");
  foo_person.set_email("john.doe@test.com");
  foo_person.set_id(1);

  return foo_person;
}