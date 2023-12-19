#pragma once

#include "TCPClosed.hpp"
#include "TCPOpen.hpp"
#include "TCPState.hpp"
#include <memory>
namespace CPPTest::DesignPatterns {

enum class State;

class TCPConnection {

public:
  TCPConnection();
  void open();
  void close();
  std::shared_ptr<TCPState> get_state();

  std::shared_ptr<TCPState> CLOSED = std::make_shared<TCPClosed>();
  std::shared_ptr<TCPState> OPEN = std::make_shared<TCPOpen>();

private:
  friend class TCPState;
  void change_state(const std::shared_ptr<TCPState> &new_state);
  std::shared_ptr<TCPState> m_state;
};
} // namespace CPPTest::DesignPatterns