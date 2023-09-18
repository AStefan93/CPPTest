#include "abstract_factory.hpp"

#include <memory>

namespace CPPTest::DesignPatterns {
void Player::update(){};
MazeGame::MazeGame(const std::shared_ptr<MazeGameFactoryItf>& factory)
    : m_final_room(factory->get_final_room()) {
  m_maze = factory->create_maze();
  m_player = factory->create_player();
};
void MazeGame::move_up() {
  m_player->update();
  m_playerPosition = m_maze->room_number(m_playerPosition)
                         ->get_side(Direction::north)
                         ->enter();
  update_state();
};

void MazeGame::move_down() {
  m_player->update();
  m_playerPosition = m_maze->room_number(m_playerPosition)
                         ->get_side(Direction::south)
                         ->enter();
  update_state();
};

void MazeGame::move_left() {
  m_player->update();
  m_playerPosition =
      m_maze->room_number(m_playerPosition)->get_side(Direction::west)->enter();
  update_state();
}

void MazeGame::move_right() {
  m_player->update();
  m_playerPosition =
      m_maze->room_number(m_playerPosition)->get_side(Direction::east)->enter();
  update_state();
}

void MazeGame::update_state() { m_isFinished = is_final_room(); };

bool MazeGame::is_finished() const { return m_isFinished; };
bool MazeGame::is_final_room() { return m_playerPosition == m_final_room; }
}  // namespace CPPTest::DesignPatterns