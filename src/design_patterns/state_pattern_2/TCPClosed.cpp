#include "TCPClosed.hpp"

namespace CPPTest::DesignPatterns {

void TCPClosed::close(const Transition & /*transition*/,
                      const Behaviour & /*behaviour*/) {}
void TCPClosed::open(const Transition &transition, const Behaviour &behaviour) {
  behaviour();
  transition();
}

TCPClosed::State TCPClosed::get_state() { return State::CLOSED; }

} // namespace CPPTest::DesignPatterns