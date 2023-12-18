#pragma once
#include "TCPStateItf.hpp"
#include <memory>

namespace CPPTest::DesignPatterns {
class TCPClosed : public TCPStateItf {
public:
  static std::shared_ptr<TCPClosed> instance();
  void open() override;
  void close() override;
};

bool operator==(const TCPClosed &lhs, const TCPClosed &rhs);
} // namespace CPPTest::DesignPatterns