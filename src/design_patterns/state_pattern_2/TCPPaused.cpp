#include "TCPPaused.hpp"
#include "TCPState.hpp"

namespace CPPTest::DesignPatterns {
TCPPaused::TCPPaused(Transition start_transition, Transition close_transition,
                     Behaviour start_behaviour, Behaviour close_behaviour)
    : m_start_transition(std::move(start_transition)),
      m_close_transition(std::move(close_transition)),
      m_start_behaviour(std::move(start_behaviour)),
      m_close_behaviour(std::move(close_behaviour)) {}
void TCPPaused::open() {}
void TCPPaused::close() {
  m_close_behaviour();
  m_close_transition();
}
void TCPPaused::start() {
  m_start_behaviour();
  m_start_transition();
}
void TCPPaused::pause() {}
TCPState::State TCPPaused::get_state() { return State::PAUSED; }

} // namespace CPPTest::DesignPatterns