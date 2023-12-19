#include "TCPClosed.hpp"
#include "TCPConnection.hpp"

namespace CPPTest::DesignPatterns {

void TCPClosed::close(TCPConnection *const /* connection */) {}
void TCPClosed::open(TCPConnection *const connection) {
  // send commands to open the connection
  connection->change_state(connection->OPEN);
}

} // namespace CPPTest::DesignPatterns