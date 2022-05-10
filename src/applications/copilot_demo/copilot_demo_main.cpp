#include <iostream>
#include <memory>
#include <qt5/QtWidgets/QApplication>
#include <qt5/QtWidgets/QLabel>
#include <qt5/QtWidgets/QMainWindow>

#include "copilot_demo.hpp"

/** This application demonstrates the copilot_demo library. */
int copilot_demo_main(int argc, char** argv) {
  QApplication app(argc, argv);
  copilot_demo::CopilotDemo copilot_demo;
  return QApplication::exec();
}

/** As a user I would like to be able to run the copilot_demo application.
 */
int main(int argc, char** argv) { return copilot_demo_main(argc, argv); }
