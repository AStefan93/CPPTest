#include "observer_pattern.hpp"

#include "gtest/gtest.h"

namespace CPPTest::DesignPatterns::Test {

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(ObserverPattern, AttachMultipleObservers) {
  Subject subject;
  const std::shared_ptr<Observer> observer1 = std::make_shared<Observer>();
  const std::shared_ptr<Observer> observer2 = std::make_shared<Observer>();
  subject.attach(observer1);
  subject.attach(observer2);
}

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(ObserverPattern, DetachMultipleObservers) {
  Subject subject;
  const std::shared_ptr<Observer> observer1 = std::make_shared<Observer>();
  const std::shared_ptr<Observer> observer2 = std::make_shared<Observer>();
  subject.attach(observer1);
  subject.attach(observer2);

  subject.detach(observer1);
  subject.detach(observer2);
}

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(ObserverPattern, SubjectSetState) {
  Subject subject;
  const auto *const expected_state = "notified";
  subject.set_state(expected_state);
  const auto actual_state = subject.get_state();
  EXPECT_EQ(expected_state, actual_state);
}

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(ObserverPattern, NotifyUpdatesObserversState) {
  Subject subject;
  const std::shared_ptr<Observer> observer1 = std::make_shared<Observer>();
  const std::shared_ptr<Observer> observer2 = std::make_shared<Observer>();
  subject.attach(observer1);
  subject.attach(observer2);
  const auto *const expected_state = "notified";
  subject.set_state(expected_state);
  subject.notify();
  const auto actual_state1 = observer1->get_state();
  const auto actual_state2 = observer2->get_state();

  EXPECT_EQ(expected_state, actual_state1);
  EXPECT_EQ(expected_state, actual_state2);
}

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(ObserverPattern, NotifyUpdatesOnlyAttachedObservers) {
  Subject subject;
  const std::shared_ptr<Observer> observer1 = std::make_shared<Observer>();
  const std::shared_ptr<Observer> observer2 = std::make_shared<Observer>();
  subject.attach(observer1);
  subject.attach(observer2);
  const auto *const expected_state1 = "notified";
  subject.set_state(expected_state1);
  subject.notify();
  const auto actual_state1 = observer1->get_state();
  const auto actual_state2 = observer2->get_state();

  ASSERT_EQ(expected_state1, actual_state1);
  ASSERT_EQ(expected_state1, actual_state2);

  subject.detach(observer1);
  const auto *const expected_state2 = "notified2";
  subject.set_state(expected_state2);
  subject.notify();
  const auto actual_state21 = observer1->get_state();
  const auto actual_state22 = observer2->get_state();

  EXPECT_EQ(expected_state1, actual_state21);
  EXPECT_EQ(expected_state2, actual_state22);
}

// NOLINTNEXTLINE(cppcoreguidelines-owning-memory,cppcoreguidelines-avoid-non-const-global-variables)
TEST(ObserverPattern, DoNotAttachTheSameObjectTwice) {
  Subject subject;
  const std::shared_ptr<Observer> observer1 = std::make_shared<Observer>();
  subject.attach(observer1);
  subject.attach(observer1);
  const auto *const expected_state1 = "notified";
  subject.set_state(expected_state1);
  subject.notify();
  const auto actual_state1 = observer1->get_state();

  ASSERT_EQ(expected_state1, actual_state1);

  subject.detach(observer1);
  const auto *const expected_state2 = "notified2";
  subject.set_state(expected_state2);
  subject.notify();
  const auto actual_state2 = observer1->get_state();

  ASSERT_EQ(expected_state1, actual_state2);
}

}  // namespace CPPTest::DesignPatterns::Test