#include "TCPConnection.hpp"
#include "TCPState.hpp"
#include "gtest/gtest.h"

namespace CPPTest::DesignPatterns::Test {

class ATCPConnection : public ::testing::Test {
protected:
  TCPConnection m_cut = TCPConnection([]() {}, []() {}, []() {}, []() {});
};

TEST_F(ATCPConnection, WhenCreatedExpectStateIsClosed) {
  EXPECT_EQ(m_cut.get_state(), TCPState::State::CLOSED);
}

TEST_F(ATCPConnection, WhenOpenCalledExpectStateIsIdle) {
  m_cut.open();
  EXPECT_EQ(m_cut.get_state(), TCPState::State::IDLE);
}

TEST_F(ATCPConnection, WhenCloseCalledExpectStateIsClosed) {
  m_cut.close();
  EXPECT_EQ(m_cut.get_state(), TCPState::State::CLOSED);
}

TEST_F(ATCPConnection, WithClosedStateWhenCloseCalledExpectStateIsClosed) {
  m_cut.close();
  EXPECT_NO_THROW(m_cut.close());
  EXPECT_EQ(m_cut.get_state(), TCPState::State::CLOSED);
}

TEST_F(ATCPConnection, WithIdleStateWhenCloseCalledExpectStateIsClosed) {
  m_cut.open();
  EXPECT_NO_THROW(m_cut.close());
  EXPECT_EQ(m_cut.get_state(), TCPState::State::CLOSED);
}

TEST_F(ATCPConnection, WithIdleStateWhenOpenCalledExpectStateIsIdle) {
  m_cut.open();
  EXPECT_NO_THROW(m_cut.open());
  EXPECT_EQ(m_cut.get_state(), TCPState::State::IDLE);
}

TEST_F(ATCPConnection, WithClosedStateWhenOpenCalledExpectStateIsIdle) {
  m_cut.close();
  EXPECT_NO_THROW(m_cut.open());
  EXPECT_EQ(m_cut.get_state(), TCPState::State::IDLE);
}

TEST_F(ATCPConnection, WithClosedStateWhenStartCalledExpectThrow) {
  m_cut.close();
  EXPECT_THROW(m_cut.start(), TCPState::WrongState);
  EXPECT_EQ(m_cut.get_state(), TCPState::State::CLOSED);
}

TEST_F(ATCPConnection, WithClosedStateWhenStopCalledExpectThrow) {
  m_cut.close();
  EXPECT_THROW(m_cut.pause(), TCPState::WrongState);
  EXPECT_EQ(m_cut.get_state(), TCPState::State::CLOSED);
}

TEST_F(ATCPConnection, WhenIdleAndWhenStopCalledExpectIdle) {
  m_cut.open();
  EXPECT_NO_THROW(m_cut.pause());
  EXPECT_EQ(m_cut.get_state(), TCPState::State::IDLE);
}

TEST_F(ATCPConnection, WhenIdleAndWhenStartCalledExpectRunning) {
  m_cut.open();
  EXPECT_NO_THROW(m_cut.start());
  EXPECT_EQ(m_cut.get_state(), TCPState::State::RUNNING);
}

TEST_F(ATCPConnection, WhenRunningAndWhenStartCalledExpectRunning) {
  m_cut.open();
  m_cut.start();
  EXPECT_NO_THROW(m_cut.start());
  EXPECT_EQ(m_cut.get_state(), TCPState::State::RUNNING);
}

TEST_F(ATCPConnection, WhenRunningAndWhenStopCalledExpectPaused) {
  m_cut.open();
  m_cut.start();
  EXPECT_NO_THROW(m_cut.pause());
  EXPECT_EQ(m_cut.get_state(), TCPState::State::PAUSED);
}

TEST_F(ATCPConnection, WhenRunningAndWhenCloseCalledExpectClosed) {
  m_cut.open();
  m_cut.start();
  EXPECT_NO_THROW(m_cut.close());
  EXPECT_EQ(m_cut.get_state(), TCPState::State::CLOSED);
}

TEST_F(ATCPConnection, WhenPausedAndWhenCloseCalledExpectClosed) {
  m_cut.open();
  m_cut.start();
  m_cut.pause();
  EXPECT_NO_THROW(m_cut.close());
  EXPECT_EQ(m_cut.get_state(), TCPState::State::CLOSED);
}

TEST_F(ATCPConnection, WhenPausedAndWhenStartCalledExpectRunning) {
  m_cut.open();
  m_cut.start();
  m_cut.pause();
  EXPECT_NO_THROW(m_cut.start());
  EXPECT_EQ(m_cut.get_state(), TCPState::State::RUNNING);
}

} // namespace CPPTest::DesignPatterns::Test