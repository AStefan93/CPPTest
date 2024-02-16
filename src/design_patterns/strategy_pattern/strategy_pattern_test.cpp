#include "strategy_pattern.hpp"
#include "gtest/gtest.h"
#include <memory>

namespace CPPTest::DesignPatterns::Test {

class AStrategyPattern : public ::testing::Test {
protected:
  //   AStrategyPattern m_cut;
};

TEST_F(AStrategyPattern, WithCreditCard) {
  PaymentService payment_service;
  std::shared_ptr<PaymentStrategy> credit_card =
      std::make_shared<CreditCardStrategy>();
  payment_service.set_payment_method(credit_card);
  EXPECT_EQ(payment_service.process_payment(), "CREDIT_CARD");
}

TEST_F(AStrategyPattern, WithBankTransfer) {
  PaymentService payment_service;
  std::shared_ptr<PaymentStrategy> bank_transfer =
      std::make_shared<BankTransferStrategy>();
  payment_service.set_payment_method(bank_transfer);
  EXPECT_EQ(payment_service.process_payment(), "BANK_TRANSFER");
}

} // namespace CPPTest::DesignPatterns::Test