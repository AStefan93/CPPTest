#include "TCPClosed.hpp"

namespace CPPTest::DesignPatterns {

void TCPClosed::close() {}

void TCPClosed::open() {}

bool operator==(const TCPClosed &lhs, const TCPClosed &rhs) {
  // comparing singletons
}
} // namespace CPPTest::DesignPatterns