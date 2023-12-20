#pragma once
#include <functional>
#include <iostream>

namespace CPPTest::DesignPatterns {

class TCPConnection;

class TCPState {
public:
  enum class State { CLOSED, IDLE, RUNNING, PAUSED };
  using Transition = std::function<void()>;
  using Behaviour = std::function<void()>;

  TCPState(const TCPState &) = default;
  TCPState(TCPState &&) = delete;
  TCPState &operator=(const TCPState &) = default;
  TCPState &operator=(TCPState &&) = delete;
  virtual ~TCPState() = default;

  virtual void open(const Transition &transition,
                    const Behaviour &behaviour) = 0;
  virtual void close(const Transition &transition,
                     const Behaviour &behaviour) = 0;
  virtual void start(const Transition &transition,
                     const Behaviour &behaviour) = 0;
  virtual void stop(const Transition &transition,
                    const Behaviour &behaviour) = 0;
  virtual State get_state() = 0;

  class WrongState : public std::runtime_error {
  public:
    explicit WrongState(const std::string &message)
        : std::runtime_error(message) {}
  };

protected:
  TCPState() = default;
};

inline std::ostream &operator<<(std::ostream &ostr,
                                const TCPState::State &state) {
  switch (state) {
  case TCPState::State::CLOSED:
    ostr << "CLOSED";
    break;
  case TCPState::State::IDLE:
    ostr << "OPENED";
    break;
  case TCPState::State::RUNNING:
    ostr << "RUNNING";
    break;
  case TCPState::State::PAUSED:
    ostr << "PAUSED";
    break;
  default:
    break;
  }
  return ostr;
}
} // namespace CPPTest::DesignPatterns