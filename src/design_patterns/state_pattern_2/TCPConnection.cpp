#include "TCPConnection.hpp"
#include "TCPState.hpp"

namespace CPPTest::DesignPatterns {

// TCPConnection::TCPConnection(const TCPState::Transition &opened_transition,
//                              const TCPState::Transition &closed_transition,
//                              const TCPState::Behaviour &opened_behaviour,
//                              const TCPState::Behaviour &closed_behaviour)
//     : m_opened_transition(opened_transition),
//       m_closed_transition(closed_transition),
//       m_opened_behaviour(opened_behaviour),
//       m_closed_behaviour(closed_behaviour) {
//   m_state = std::make_shared<TCPClosed>();
// }

TCPConnection::TCPConnection() {
  m_state = std::make_shared<TCPClosed>();
  m_opened_transition = [this]() { m_state = std::make_shared<TCPOpened>(); };
  m_closed_transition = [this]() { m_state = std::make_shared<TCPClosed>(); };
  m_opened_behaviour = []() {};
  m_closed_behaviour = []() {};
}

TCPClosed::State TCPConnection::get_state() { return m_state->get_state(); }
void TCPConnection::open() {
  m_state->open(m_opened_transition, m_opened_behaviour);
}
void TCPConnection::close() {
  m_state->close(m_closed_transition, m_closed_behaviour);
}

} // namespace CPPTest::DesignPatterns