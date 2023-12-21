#include "TCPRunning.hpp"
#include "TCPState.hpp"

namespace CPPTest::DesignPatterns {
TCPRunning::TCPRunning(Transition pause_transition, Transition close_transition,
                       Behaviour pause_behaviour, Behaviour close_behaviour)
    : m_pause_transition(std::move(pause_transition)),
      m_close_transition(std::move(close_transition)),
      m_pause_behaviour(std::move(pause_behaviour)),
      m_close_behaviour(std::move(close_behaviour)) {}
void TCPRunning::open() {}
void TCPRunning::close() {
  m_close_behaviour();
  m_close_transition();
}
void TCPRunning::start() {}
void TCPRunning::pause() {
  m_pause_behaviour();
  m_pause_transition();
}
TCPState::State TCPRunning::get_state() { return State::RUNNING; }

} // namespace CPPTest::DesignPatterns