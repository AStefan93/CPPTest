/**
 * @file copilot_demo.hpp
 * @author Arnautu Stefan (arnautu.stefan93@gmail.com)
 * @brief
 *
 *
 */
#ifndef COPILOT_DEMO_HPP
#define COPILOT_DEMO_HPP

#include <QtWidgets/QMainWindow>
#include <memory>

namespace copilot_demo {

/**
 * @brief This class creates a window with a stickman in the middle of the
 * screen.
 */
class CopilotDemo {
 public:
  /**
   * @brief Construct a new Copilot Demo object
   */
  CopilotDemo();

 private:
  std::unique_ptr<QMainWindow> m_main_window;
};

}  // namespace copilot_demo

#endif  // COPILOT_DEMO_HPP