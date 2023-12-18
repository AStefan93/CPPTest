#include "TCPConnection.hpp"
#include "TCPClosed.hpp"
#include "TCPOpen.hpp"

namespace CPPTest::DesignPatterns {

TCPConnection::TCPConnection() { m_state = std::make_shared<TCPClosed>(); }

std::shared_ptr<TCPStateItf> TCPConnection::get_state() { return m_state; }
void TCPConnection::open() { m_state = std::make_shared<TCPOpen>(); }
void TCPConnection::close() { m_state = std::make_shared<TCPClosed>(); }
} // namespace CPPTest::DesignPatterns