#pragma once
#include "TCPState.hpp"

namespace CPPTest::DesignPatterns {
class TCPRunning : public TCPState {
public:
  TCPRunning(Transition pause_transition, Transition close_transition,
             Behaviour pause_behaviour, Behaviour close_behaviour);
  void open() override;
  void close() override;
  void start() override;
  void pause() override;
  State get_state() override;

private:
  Transition m_pause_transition;
  Transition m_close_transition;
  Behaviour m_pause_behaviour;
  Behaviour m_close_behaviour;
};
} // namespace CPPTest::DesignPatterns