#pragma once

#include <memory>
namespace CPPTest::DesignPatterns {

class TCPConnection;

class TCPState {
public:
  TCPState(const TCPState &) = default;
  TCPState(TCPState &&) = delete;
  TCPState &operator=(const TCPState &) = default;
  TCPState &operator=(TCPState &&) = delete;
  virtual ~TCPState() = default;

  virtual void open(TCPConnection * /*connection*/){};
  virtual void close(TCPConnection * /*connection*/){};

protected:
  static void change_state(TCPConnection *connection,
                    const std::shared_ptr<TCPState> &new_state);
  TCPState() = default;
};

} // namespace CPPTest::DesignPatterns