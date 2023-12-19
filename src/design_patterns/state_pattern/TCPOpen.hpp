#pragma once
#include "TCPStateItf.hpp"

namespace CPPTest::DesignPatterns {
class TCPOpen : public TCPStateItf {
public:
  void open(TCPConnection *connection) override;
  void close(TCPConnection *connection) override;
};
} // namespace CPPTest::DesignPatterns