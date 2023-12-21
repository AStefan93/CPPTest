#pragma once
#include "TCPState.hpp"

namespace CPPTest::DesignPatterns {
class TCPIdle : public TCPState {
public:
  TCPIdle(Transition start_transition, Transition close_transition,
          Behaviour start_behaviour, Behaviour close_behaviour);
  void open() override;
  void close() override;
  void start() override;
  void pause() override;
  State get_state() override;

private:
  Transition m_start_transition;
  Transition m_close_transition;
  Behaviour m_start_behaviour;
  Behaviour m_close_behaviour;
};
} // namespace CPPTest::DesignPatterns