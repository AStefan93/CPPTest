#pragma once

#include <memory>
#include <string>
namespace CPPTest::DesignPatterns {

class PaymentStrategy {
public:
  PaymentStrategy(const PaymentStrategy &) = default;
  PaymentStrategy(PaymentStrategy &&) = delete;
  PaymentStrategy &operator=(const PaymentStrategy &) = default;
  PaymentStrategy &operator=(PaymentStrategy &&) = delete;
  virtual ~PaymentStrategy() = default;
  virtual std::string process_payment() = 0;

protected:
  PaymentStrategy() = default;
};

class CreditCardStrategy : public PaymentStrategy {
public:
  CreditCardStrategy() = default;
  CreditCardStrategy(const CreditCardStrategy &) = default;
  CreditCardStrategy(CreditCardStrategy &&) = delete;
  CreditCardStrategy &operator=(const CreditCardStrategy &) = default;
  CreditCardStrategy &operator=(CreditCardStrategy &&) = delete;
  ~CreditCardStrategy() = default;
  std::string process_payment() override;
};

class BankTransferStrategy : public PaymentStrategy {
public:
  BankTransferStrategy() = default;
  BankTransferStrategy(const BankTransferStrategy &) = default;
  BankTransferStrategy(BankTransferStrategy &&) = delete;
  BankTransferStrategy &operator=(const BankTransferStrategy &) = default;
  BankTransferStrategy &operator=(BankTransferStrategy &&) = delete;
  ~BankTransferStrategy() = default;
  std::string process_payment() override;
};

class PaymentService {
public:
  void
  set_payment_method(const std::shared_ptr<PaymentStrategy> &payment_method);
  std::string process_payment();

private:
  std::shared_ptr<PaymentStrategy> m_payment_method{};
};
} // namespace CPPTest::DesignPatterns