#pragma once
#include "TCPState.hpp"

namespace CPPTest::DesignPatterns {
class TCPOpen : public TCPState {
public:
  void open(TCPConnection *connection) override;
  void close(TCPConnection *connection) override;
};
} // namespace CPPTest::DesignPatterns