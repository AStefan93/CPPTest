#pragma once

namespace CPPTest::DesignPatterns {

class TCPConnection;

class TCPStateItf {
public:
  enum class State { Closed, Closing, Open, Opening };

  TCPStateItf(const TCPStateItf &) = default;
  TCPStateItf(TCPStateItf &&) = delete;
  TCPStateItf &operator=(const TCPStateItf &) = default;
  TCPStateItf &operator=(TCPStateItf &&) = delete;
  virtual ~TCPStateItf() = default;

  virtual void open(TCPConnection *connection) = 0;
  virtual void close(TCPConnection *connection) = 0;

protected:
  TCPStateItf() = default;
};

} // namespace CPPTest::DesignPatterns