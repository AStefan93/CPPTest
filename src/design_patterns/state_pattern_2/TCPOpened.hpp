#pragma once
#include "TCPState.hpp"

namespace CPPTest::DesignPatterns {
class TCPOpened : public TCPState {
public:
  void open(const Transition &transition, const Behaviour &behaviour) override;
  void close(const Transition &transition, const Behaviour &behaviour) override;
  State get_state() override;
};
} // namespace CPPTest::DesignPatterns