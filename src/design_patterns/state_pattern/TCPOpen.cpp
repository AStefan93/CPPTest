#include "TCPOpen.hpp"
#include "TCPClosed.hpp"
#include "TCPConnection.hpp"
#include <stdexcept>

namespace CPPTest::DesignPatterns {

void TCPOpen::open(TCPConnection *const /* connection */) {}
void TCPOpen::close(TCPConnection *const connection) {
  if (connection != nullptr)
    connection->change_state(connection->CLOSED);
  else
    throw std::runtime_error("Cannot CLOSE. Connection not found");
}

} // namespace CPPTest::DesignPatterns