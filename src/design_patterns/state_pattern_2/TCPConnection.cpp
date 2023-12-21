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
                             TCPState::Behaviour pause_behaviour)
    : m_open_behaviour(std::move(open_behaviour)),
      m_close_behaviour(std::move(close_behaviour)),
      m_start_behaviour(std::move(start_behaviour)),
      m_pause_behaviour(std::move(pause_behaviour)) {

  m_open_transition = [this]() { m_state = m_idle; };
  m_close_transition = [this]() { m_state = m_closed; };
  m_start_transition = [this]() { m_state = m_running; };
  m_pause_transition = [this]() { m_state = m_paused; };

  m_closed = std::make_shared<TCPClosed>(m_open_transition, m_open_behaviour);
  m_idle = std::make_shared<TCPIdle>(m_start_transition, m_close_transition,
                                     m_start_behaviour, m_close_behaviour);
  m_running =
      std::make_shared<TCPRunning>(m_pause_transition, m_close_transition,
                                   m_pause_behaviour, m_close_behaviour);
  m_paused = std::make_shared<TCPPaused>(m_start_transition, m_close_transition,
                                         m_start_behaviour, m_close_behaviour);

  m_state = m_closed;
}

TCPClosed::State TCPConnection::get_state() { return m_state->get_state(); }
void TCPConnection::open() { m_state->open(); }
void TCPConnection::close() { m_state->close(); }
void TCPConnection::start() { m_state->start(); }
void TCPConnection::pause() { m_state->pause(); }

} // namespace CPPTest::DesignPatterns