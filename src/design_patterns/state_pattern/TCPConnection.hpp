#pragma once

#include "TCPClosed.hpp"
#include "TCPOpen.hpp"
#include "TCPStateItf.hpp"
#include <memory>
namespace CPPTest::DesignPatterns {

class TCPStateItf;
class TCPOpen;
class TCPClosed;
enum class State;

class TCPConnection : public std::enable_shared_from_this<TCPConnection> {

public:
  TCPConnection();
  void open();
  void close();
  std::shared_ptr<TCPStateItf> get_state();

  std::shared_ptr<TCPStateItf> CLOSED = std::make_shared<TCPClosed>();
  std::shared_ptr<TCPStateItf> OPEN = std::make_shared<TCPOpen>();

private:
  void change_state(const std::shared_ptr<TCPStateItf> &new_state);
  friend class TCPClosed;
  friend class TCPOpen;
  std::shared_ptr<TCPStateItf> m_state;
};
} // namespace CPPTest::DesignPatterns