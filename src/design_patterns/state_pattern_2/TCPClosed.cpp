#include "TCPClosed.hpp"

namespace CPPTest::DesignPatterns {
TCPClosed::TCPClosed(Transition open_transition, Behaviour open_behaviour)
    : m_open_transition(std::move(open_transition)),
      m_open_behaviour(std::move(open_behaviour)) {}

void TCPClosed::close() {}
void TCPClosed::open() {
  m_open_behaviour();
  m_open_transition();
}
void TCPClosed::start() { throw WrongState("Cannot start in CLOSED state"); }
void TCPClosed::pause() { throw WrongState("Cannot stop in CLOSED state"); }
TCPClosed::State TCPClosed::get_state() { return State::CLOSED; }

} // namespace CPPTest::DesignPatterns