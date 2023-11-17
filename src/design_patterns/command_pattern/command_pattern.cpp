#include "command_pattern.hpp"

#include <memory>
#include <utility>

namespace CPPTest::DesignPatterns {
Paste::Paste(std::shared_ptr<File> file) : m_document(std::move(file)) {}
void Paste::execute() { m_document->paste(); }
}  // namespace CPPTest::DesignPatterns