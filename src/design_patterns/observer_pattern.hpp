#include <memory>
#include <set>
#include <string>

#include "observer_pattern_itf.hpp"
namespace CPPTest::DesignPatterns {
class Subject : public SubjectItf {
 public:
  Subject() = default;
  void attach(const std::shared_ptr<ObserverItf> &observer) override;
  void detach(const std::shared_ptr<ObserverItf> &observer) override;
  void notify() override;

  std::string get_state();
  void set_state(const std::string &state);

 private:
  std::string m_state;
  std::set<std::shared_ptr<ObserverItf>> m_observers;
};

class Observer : public ObserverItf {
 public:
  Observer() = default;
  void update(const std::string &subjectState) override;
  std::string get_state();

 private:
  std::string m_state;
};
}  // namespace CPPTest::DesignPatterns