#include "observer_pattern.hpp"

#include <memory>

namespace CPPTest::DesignPatterns {
void Subject::attach(const std::shared_ptr<ObserverItf>& /* observer */) {}
void Subject::detach(const std::shared_ptr<ObserverItf>& /* observer */) {}
void Subject::notify() {}
void Observer::update() {}
std::string Observer::get_state() { return ""; }

}  // namespace CPPTest::DesignPatterns