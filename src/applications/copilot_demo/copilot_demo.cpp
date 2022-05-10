/**
 * @file copilot_demo.cpp
 * @author Arnautu Stefan (arnautu.stefan93@gmail.com)
 * @brief
 *
 *
 */
#include "copilot_demo.hpp"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <memory>

copilot_demo::CopilotDemo::CopilotDemo() {
  // Show me a window with a green triangle in the middle of it
  m_main_window = std::make_unique<QMainWindow>();
  m_main_window->setWindowTitle("Copilot Demo");
  m_main_window->setCentralWidget(std::make_unique<QWidget>().release());
  auto layout = std::make_shared<QGridLayout>();
  m_main_window->centralWidget()->setLayout(layout.get());
  layout->addWidget(std::make_unique<QLabel>("Copilot Demo").release(), 0, 0);

  // Increase window size
  constexpr int window_width = 800;
  constexpr int window_height = 600;
  m_main_window->resize(window_width, window_height);

  m_main_window->show();
}
