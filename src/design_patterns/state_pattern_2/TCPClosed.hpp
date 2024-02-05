#pragma once
#include "TCPState.hpp"

namespace CPPTest::DesignPatterns {
class TCPClosed : public TCPState {
public:
  TCPClosed(Transition open_transition, Behaviour open_behaviour);

  void open() override;
  void close() override;
  void start() override;
  void pause() override;
  State get_state() override;

private:
  Transition m_open_transition;
  Behaviour m_open_behaviour;
};

} // namespace CPPTest::DesignPatterns