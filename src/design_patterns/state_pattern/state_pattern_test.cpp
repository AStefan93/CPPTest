#include "TCPClosed.hpp"
#include "TCPConnection.hpp"
#include "gtest/gtest.h"

namespace CPPTest::DesignPatterns::Test {

class ATCPConnection : public ::testing::Test {
protected:
  TCPConnection m_cut;
};

// TEST_F(ATCPConnection, WhenCreatedExpectStateIsClosed) {
//   EXPECT_EQ(m_cut.get_state(), TCPConnection::closed;);
// }

// TEST_F(ATCPConnection, WhenOpenCalledExpectStateIsOpen) {
//   m_cut.open();
//   EXPECT_EQ(m_cut.get_state(), TCPOpen{});
// }

// TEST_F(ATCPConnection, WhenCloseCalledExpectStateIsClosed) {
//   m_cut.close();
//   EXPECT_EQ(m_cut.get_state(), TCPClosed{});
// }

} // namespace CPPTest::DesignPatterns::Test