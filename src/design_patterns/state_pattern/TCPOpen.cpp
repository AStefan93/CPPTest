#include "TCPOpen.hpp"
#include "TCPConnection.hpp"

namespace CPPTest::DesignPatterns {

void TCPOpen::open(TCPConnection *const /* connection */) {}
void TCPOpen::close(TCPConnection *const connection) {
  // send commands to close the connection
  change_state(connection, connection->CLOSED);
}

} // namespace CPPTest::DesignPatterns