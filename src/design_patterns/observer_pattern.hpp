#include <memory>
#include <string>

#include "observer_pattern_itf.hpp"
namespace CPPTest::DesignPatterns {
class Subject : public SubjectItf {
 public:
  Subject() = default;
  void attach(const std::shared_ptr<ObserverItf> &observer) override;
  void detach(const std::shared_ptr<ObserverItf> &observer) override;
  void notify() override;
};

class Observer : public ObserverItf {
 public:
  Observer() = default;
  void update() override;
  std::string get_state();

 private:
  std::string m_state;
};
}  // namespace CPPTest::DesignPatterns