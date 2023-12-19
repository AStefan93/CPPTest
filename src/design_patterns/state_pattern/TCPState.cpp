#include "TCPState.hpp"
#include "TCPConnection.hpp"

namespace CPPTest::DesignPatterns {
void TCPState::change_state(TCPConnection *const connection,
                            const std::shared_ptr<TCPState> &new_state) {
  connection->change_state(new_state);
}

} // namespace CPPTest::DesignPatterns