#pragma once

#include "TCPState.hpp"
#include <memory>
namespace CPPTest::DesignPatterns {

class TCPConnection {

public:
  TCPConnection(TCPState::Behaviour open_behaviour,
                TCPState::Behaviour close_behaviour,
                TCPState::Behaviour start_behaviour,
                TCPState::Behaviour stop_behaviour);
  void open();
  void close();
  void start();
  void stop();
  TCPState::State get_state();

private:
  std::shared_ptr<TCPState> m_state;
  TCPState::Transition m_open_transition;
  TCPState::Transition m_close_transition;
  TCPState::Transition m_start_transition;
  TCPState::Transition m_stop_transition;
  TCPState::Behaviour m_open_behaviour;
  TCPState::Behaviour m_close_behaviour;
  TCPState::Behaviour m_start_behaviour;
  TCPState::Behaviour m_stop_behaviour;
};
} // namespace CPPTest::DesignPatterns