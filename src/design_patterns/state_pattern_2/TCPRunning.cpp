#include "TCPRunning.hpp"
#include "TCPState.hpp"

namespace CPPTest::DesignPatterns {

void TCPRunning::open(const Transition & /*transition*/,
                      const Behaviour & /*behaviour*/) {}

// NOLINTNEXTLINE
void TCPRunning::close(const Transition &transition,
                       const Behaviour &behaviour) {
  behaviour();
  transition();
}
void TCPRunning::start(const Transition & /*transition*/,
                       const Behaviour & /*behaviour*/) {}

// NOLINTNEXTLINE
void TCPRunning::stop(const Transition &transition,
                      const Behaviour &behaviour) {
  behaviour();
  transition();
}
TCPState::State TCPRunning::get_state() { return State::RUNNING; }

} // namespace CPPTest::DesignPatterns