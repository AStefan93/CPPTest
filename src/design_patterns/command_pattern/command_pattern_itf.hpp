
class Command {
 public:
  Command(const Command&) = default;
  Command& operator=(const Command&) = default;
  Command(Command&&) = delete;
  Command& operator=(Command&&) = delete;
  virtual ~Command() = default;
  virtual void execute() = 0;

 protected:
  Command() = default;
};