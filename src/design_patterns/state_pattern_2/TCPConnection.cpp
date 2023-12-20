#include "TCPConnection.hpp"

#include "TCPClosed.hpp"
#include "TCPIdle.hpp"
#include "TCPPaused.hpp"
#include "TCPRunning.hpp"
#include "TCPState.hpp"
#include <utility>

namespace CPPTest::DesignPatterns {

// NOLINTNEXTLINE
TCPConnection::TCPConnection(TCPState::Behaviour open_behaviour,
                             TCPState::Behaviour close_behaviour,
                             TCPState::Behaviour start_behaviour,
                             TCPState::Behaviour stop_behaviour)
    : m_open_behaviour(std::move(open_behaviour)),
      m_close_behaviour(std::move(close_behaviour)),
      m_start_behaviour(std::move(start_behaviour)),
      m_stop_behaviour(std::move(stop_behaviour)) {
  m_state = std::make_shared<TCPClosed>();
  m_open_transition = [this]() { m_state = std::make_shared<TCPIdle>(); };
  m_close_transition = [this]() { m_state = std::make_shared<TCPClosed>(); };
  m_start_transition = [this]() { m_state = std::make_shared<TCPRunning>(); };
  m_stop_transition = [this]() { m_state = std::make_shared<TCPPaused>(); };
}

TCPClosed::State TCPConnection::get_state() { return m_state->get_state(); }
void TCPConnection::open() {
  m_state->open(m_open_transition, m_open_behaviour);
}
void TCPConnection::close() {
  m_state->close(m_close_transition, m_close_behaviour);
}

void TCPConnection::start() {
  m_state->start(m_start_transition, m_start_behaviour);
}

void TCPConnection::stop() {
  m_state->stop(m_stop_transition, m_stop_behaviour);
}

} // namespace CPPTest::DesignPatterns