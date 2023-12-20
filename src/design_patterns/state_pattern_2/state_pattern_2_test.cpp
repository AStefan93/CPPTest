#include "TCPConnection.hpp"
#include "TCPState.hpp"
#include "gtest/gtest.h"

namespace CPPTest::DesignPatterns::Test {

class ATCPConnection : public ::testing::Test {
protected:
  TCPConnection m_cut;
};

TEST_F(ATCPConnection, WhenCreatedExpectStateIsClosed) {
  EXPECT_EQ(m_cut.get_state(), TCPState::State::CLOSED);
}

TEST_F(ATCPConnection, WhenOpenCalledExpectStateIsOpen) {
  m_cut.open();
  EXPECT_EQ(m_cut.get_state(), TCPState::State::OPENED);
}

TEST_F(ATCPConnection, WhenCloseCalledExpectStateIsClosed) {
  m_cut.close();
  EXPECT_EQ(m_cut.get_state(), TCPState::State::CLOSED);
}

TEST_F(ATCPConnection, WithClosedStateWhenCloseCalledExpectStateIsClosed) {
  m_cut.close();
  m_cut.close();
  EXPECT_EQ(m_cut.get_state(), TCPState::State::CLOSED);
}

TEST_F(ATCPConnection, WithOpenStateWhenCloseCalledExpectStateIsClosed) {
  m_cut.open();
  m_cut.close();
  EXPECT_EQ(m_cut.get_state(), TCPState::State::CLOSED);
}

TEST_F(ATCPConnection, WithOpenStateWhenOpenCalledExpectStateIsOpen) {
  m_cut.open();
  m_cut.open();
  EXPECT_EQ(m_cut.get_state(), TCPState::State::OPENED);
}

TEST_F(ATCPConnection, WithCloseStateWhenOpenCalledExpectStateIsOpen) {
  m_cut.close();
  m_cut.open();
  EXPECT_EQ(m_cut.get_state(), TCPState::State::OPENED);
}

} // namespace CPPTest::DesignPatterns::Test