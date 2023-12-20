#include "TCPConnection.hpp"
#include "TCPClosed.hpp"
#include "TCPOpened.hpp"
#include "TCPState.hpp"

namespace CPPTest::DesignPatterns {

TCPConnection::TCPConnection() {
  m_state = std::make_shared<TCPClosed>();
  m_open_transition = [this]() { m_state = std::make_shared<TCPOpened>(); };
  m_close_transition = [this]() { m_state = std::make_shared<TCPClosed>(); };
  m_open_behaviour = []() {};
  m_close_behaviour = []() {};
}

TCPClosed::State TCPConnection::get_state() { return m_state->get_state(); }
void TCPConnection::open() {
  m_state->open(m_open_transition, m_open_behaviour);
}
void TCPConnection::close() {
  m_state->close(m_close_transition, m_close_behaviour);
}

} // namespace CPPTest::DesignPatterns