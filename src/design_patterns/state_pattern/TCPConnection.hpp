#pragma once

#include <memory>
namespace CPPTest::DesignPatterns {

class TCPStateItf;
enum class State;

class TCPConnection {

public:
  TCPConnection();
  void open();
  void close();
  std::shared_ptr<TCPStateItf> get_state();

private:
  std::shared_ptr<TCPStateItf> m_state;
};
} // namespace CPPTest::DesignPatterns