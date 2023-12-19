#include "TCPClosed.hpp"
#include "TCPConnection.hpp"
#include <stdexcept>

namespace CPPTest::DesignPatterns {

void TCPClosed::close(TCPConnection *const /* connection */) {}
void TCPClosed::open(TCPConnection *const connection) {
  if (connection != nullptr)
    connection->change_state(connection->OPEN);
  else
    throw std::runtime_error("Cannot OPEN. Connection not found");
}

} // namespace CPPTest::DesignPatterns