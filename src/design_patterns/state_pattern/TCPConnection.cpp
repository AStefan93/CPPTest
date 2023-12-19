#include "TCPConnection.hpp"
#include "TCPStateItf.hpp"
#include <memory>

namespace CPPTest::DesignPatterns {

TCPConnection::TCPConnection() : m_state(CLOSED) {}

std::shared_ptr<TCPStateItf> TCPConnection::get_state() { return m_state; }
void TCPConnection::open() { m_state->open(this); }
void TCPConnection::close() { m_state->close(this); }

void TCPConnection::change_state(
    const std::shared_ptr<TCPStateItf> &new_state) {
  m_state = new_state;
}

} // namespace CPPTest::DesignPatterns