#include "TCPPaused.hpp"
#include "TCPState.hpp"

namespace CPPTest::DesignPatterns {

void TCPPaused::open(const Transition & /*transition*/,
                     const Behaviour & /*behaviour*/) {}

// NOLINTNEXTLINE
void TCPPaused::close(const Transition &transition,
                      const Behaviour &behaviour) {
  behaviour();
  transition();
}
// NOLINTNEXTLINE
void TCPPaused::start(const Transition &transition,
                      const Behaviour &behaviour) {
  behaviour();
  transition();
}
void TCPPaused::stop(const Transition & /*transition*/,
                     const Behaviour & /*behaviour*/) {}
TCPState::State TCPPaused::get_state() { return State::PAUSED; }

} // namespace CPPTest::DesignPatterns