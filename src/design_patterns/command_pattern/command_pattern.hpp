#include <memory>

#include "command_pattern_itf.hpp"

namespace CPPTest::DesignPatterns {

class File {
 public:
  File() = default;
  virtual ~File() = default;
  File(const File&) = default;
  File& operator=(const File&) = default;
  File(File&&) = delete;
  File& operator=(File&&) = delete;

  virtual void paste() = 0;
  virtual void cut() = 0;
  virtual void copy() = 0;
};

class Paste : public Command {
 public:
  Paste() = default;
  ~Paste() override = default;
  Paste(const Paste&) = default;
  Paste& operator=(const Paste&) = default;
  Paste(Paste&&) = delete;
  Paste& operator=(Paste&&) = delete;

  explicit Paste(std::shared_ptr<File> file);

  void execute() override;

 private:
  std::shared_ptr<File> m_document;
};

class Document : public File {
 public:
  Document() = default;
  ~Document() override = default;
  Document(const Document&) = default;
  Document& operator=(const Document&) = default;
  Document(Document&&) = delete;
  Document& operator=(Document&&) = delete;

  void paste() override;
  void cut() override;
  void copy() override;
};
}  // namespace CPPTest::DesignPatterns