#pragma once
#include "TCPStateItf.hpp"

namespace CPPTest::DesignPatterns {
class TCPOpen : public TCPStateItf {
public:
  void open() override;
  void close() override;
};
} // namespace CPPTest::DesignPatterns