#include "TCPClosed.hpp"

namespace CPPTest::DesignPatterns {

void TCPClosed::close(const Transition & /*transition*/,
                      const Behaviour & /*behaviour*/) {}
// NOLINTNEXTLINE
void TCPClosed::open(const Transition &transition, const Behaviour &behaviour) {
  behaviour();
  transition();
}

void TCPClosed::start(const Transition & /*transition*/,
                      const Behaviour & /*behaviour*/) {
  throw WrongState("Cannot start in CLOSED state");
}

void TCPClosed::stop(const Transition & /*transition*/,
                     const Behaviour & /*behaviour*/) {
  throw WrongState("Cannot stop in CLOSED state");
}

TCPClosed::State TCPClosed::get_state() { return State::CLOSED; }

} // namespace CPPTest::DesignPatterns