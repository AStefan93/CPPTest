#include "observer_pattern.hpp"

#include <memory>

namespace CPPTest::DesignPatterns {
void Subject::attach(const std::shared_ptr<ObserverItf>& observer) {
  m_observers.emplace(observer);
}
void Subject::detach(const std::shared_ptr<ObserverItf>& observer) {
  m_observers.erase(observer);
}
void Subject::notify() {
  for (const auto& observer : m_observers) {
    observer->update(m_state);
  }
}
void Subject::set_state(const std::string& state) { m_state = state; }
std::string Subject::get_state() { return m_state; }

void Observer::update(const std::string& subjectState) {
  m_state = subjectState;
}
std::string Observer::get_state() { return m_state; }

}  // namespace CPPTest::DesignPatterns