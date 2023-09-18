
#include <memory>
namespace CPPTest::DesignPatterns {

class ObserverItf {
 public:
  ObserverItf(const ObserverItf &) = default;
  ObserverItf(ObserverItf &&) = delete;
  ObserverItf &operator=(const ObserverItf &) = default;
  ObserverItf &operator=(ObserverItf &&) = delete;
  virtual ~ObserverItf() = default;

  void virtual update(const std::string &subjectState) = 0;

 protected:
  ObserverItf() = default;
};

class SubjectItf {
 public:
  SubjectItf(const SubjectItf &) = default;
  SubjectItf(SubjectItf &&) = delete;
  SubjectItf &operator=(const SubjectItf &) = default;
  SubjectItf &operator=(SubjectItf &&) = delete;
  virtual ~SubjectItf() = default;

  void virtual attach(const std::shared_ptr<ObserverItf> &observer) = 0;
  void virtual detach(const std::shared_ptr<ObserverItf> &observer) = 0;
  void virtual notify() = 0;

 protected:
  SubjectItf() = default;
};
}  // namespace CPPTest::DesignPatterns