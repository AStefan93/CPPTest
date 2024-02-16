#include "strategy_pattern.hpp"
#include <memory>

namespace CPPTest::DesignPatterns {
void PaymentService::set_payment_method(
    const std::shared_ptr<PaymentStrategy> &payment_method) {
  m_payment_method = payment_method;
}

std::string PaymentService::process_payment() {
  return m_payment_method->process_payment();
}

std::string CreditCardStrategy::process_payment() { return "CREDIT_CARD"; }
std::string BankTransferStrategy::process_payment() { return "BANK_TRANSFER"; }

} // namespace CPPTest::DesignPatterns