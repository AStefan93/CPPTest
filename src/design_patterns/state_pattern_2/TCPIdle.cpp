#include "TCPIdle.hpp"

#include <utility>

namespace CPPTest::DesignPatterns {
TCPIdle::TCPIdle(Transition start_transition, Transition close_transition,
                 Behaviour start_behaviour, Behaviour close_behaviour)
    : m_start_transition(std::move(start_transition)),
      m_close_transition(std::move(close_transition)),
      m_start_behaviour(std::move(start_behaviour)),
      m_close_behaviour(std::move(close_behaviour)) {}
void TCPIdle::open() {}
void TCPIdle::close() {
  m_close_behaviour();
  m_close_transition();
}
void TCPIdle::start() {
  m_start_behaviour();
  m_start_transition();
}
void TCPIdle::pause() {}
TCPIdle::State TCPIdle::get_state() { return State::IDLE; }

} // namespace CPPTest::DesignPatterns