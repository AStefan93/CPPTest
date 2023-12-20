#include "TCPIdle.hpp"

namespace CPPTest::DesignPatterns {

void TCPIdle::open(const Transition & /*transition*/,
                   const Behaviour & /*behaviour*/) {}
// NOLINTNEXTLINE
void TCPIdle::close(const Transition &transition, const Behaviour &behaviour) {
  behaviour();
  transition();
}
// NOLINTNEXTLINE
void TCPIdle::start(const Transition &transition, const Behaviour &behaviour) {
  behaviour();
  transition();
}

void TCPIdle::stop(const Transition & /*transition*/,
                   const Behaviour & /*behaviour*/) {}
TCPIdle::State TCPIdle::get_state() { return State::IDLE; }

} // namespace CPPTest::DesignPatterns