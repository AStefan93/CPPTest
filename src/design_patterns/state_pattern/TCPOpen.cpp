#include "TCPOpen.hpp"
#include "TCPConnection.hpp"

namespace CPPTest::DesignPatterns {

void TCPOpen::open(TCPConnection *const /* connection */) {}
void TCPOpen::close(TCPConnection *const connection) {
  // send commands to close the connection
  connection->change_state(connection->CLOSED);
}

} // namespace CPPTest::DesignPatterns