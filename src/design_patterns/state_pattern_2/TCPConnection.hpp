#pragma once

#include "TCPClosed.hpp"
#include "TCPOpened.hpp"
#include "TCPState.hpp"
#include <memory>
namespace CPPTest::DesignPatterns {

class TCPConnection {

public:
  // TCPConnection(const TCPState::Transition &opened_transition,
  //               const TCPState::Transition &closed_transition,
  //               const TCPState::Behaviour &opened_behaviour,
  //               const TCPState::Behaviour &closed_behaviour);
  TCPConnection();
  void open();
  void close();
  TCPState::State get_state();

private:
  std::shared_ptr<TCPState> m_state = std::make_shared<TCPClosed>();
  TCPState::Transition m_opened_transition;
  TCPState::Transition m_closed_transition;
  TCPState::Behaviour m_opened_behaviour;
  TCPState::Behaviour m_closed_behaviour;
};
} // namespace CPPTest::DesignPatterns