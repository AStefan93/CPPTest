#pragma once

#include "TCPState.hpp"
#include <memory>
namespace CPPTest::DesignPatterns {

class TCPConnection {

public:
  TCPConnection();
  void open();
  void close();
  TCPState::State get_state();

private:
  std::shared_ptr<TCPState> m_state;
  TCPState::Transition m_open_transition;
  TCPState::Transition m_close_transition;
  TCPState::Behaviour m_open_behaviour;
  TCPState::Behaviour m_close_behaviour;
};
} // namespace CPPTest::DesignPatterns