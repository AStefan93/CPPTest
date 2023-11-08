
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

class LightOnCommand : public Command {
 public:
  LightOnCommand(const LightOnCommand&) = default;
  LightOnCommand& operator=(const LightOnCommand&) = default;
  LightOnCommand(LightOnCommand&&) = delete;
  LightOnCommand& operator=(LightOnCommand&&) = delete;

  ~LightOnCommand() override = default;
  void execute() override = 0;

 protected:
  LightOnCommand() = default;
};