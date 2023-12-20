#include "TCPOpened.hpp"

namespace CPPTest::DesignPatterns {

void TCPOpened::open(const Transition & /*transition*/,
                     const Behaviour & /*behaviour*/) {}
// NOLINTNEXTLINE
void TCPOpened::close(const Transition &transition,
                      const Behaviour &behaviour) {
  behaviour();
  transition();
}
TCPOpened::State TCPOpened::get_state() { return State::OPENED; }

} // namespace CPPTest::DesignPatterns