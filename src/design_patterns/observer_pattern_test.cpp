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
TEST(ObserverPattern, NotifyUpdatesObserverState) {
  Subject subject;
  const std::shared_ptr<Observer> observer1 = std::make_shared<Observer>();
  subject.attach(observer1);
  subject.notify();
  const auto actual_state = observer1->get_state();
}

}  // namespace CPPTest::DesignPatterns::Test