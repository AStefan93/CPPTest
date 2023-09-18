#include "abstract_factory.hpp"

#include <vector>

#include "gtest/gtest.h"

namespace CPPTest::DesignPatterns::Test {

// NOLINTNEXTLINE
class TestBiggerMazeGame : public ::testing::Test {
 public:
  class SecondMazeGameFactoryTest : public MazeGameFactoryItf {
   public:
    [[nodiscard]] std::shared_ptr<MazeItf> create_maze() const override {
      const auto maze = std::make_shared<Maze>();
      maze->add_room(1);
      maze->add_room(2);
      maze->add_room(3);
      maze->add_room(4);
      maze->room_number(0)->set_side(Direction::north, maze->room_number(1));
      maze->room_number(1)->set_side(Direction::north, maze->room_number(2));
      maze->room_number(2)->set_side(Direction::north, maze->room_number(3));
      maze->room_number(2)->set_side(Direction::west, maze->room_number(3));
      maze->room_number(3)->set_side(Direction::west, maze->room_number(4));
      return maze;
    }
    [[nodiscard]] std::shared_ptr<PlayerItf> create_player() const override {
      return std::make_shared<Player>();
    }
    [[nodiscard]] int get_final_room() const override { return 4; }
  };
  TestBiggerMazeGame() = default;
  ~TestBiggerMazeGame() override = default;

 protected:
  // NOLINTNEXTLINE(*-non-private-member-variables-in-classes)
  MazeGame m_cut;
};

TEST_F(TestBiggerMazeGame, MazeGameUpLeft) {
  m_cut = MazeGame(std::make_shared<SecondMazeGameFactoryTest>());
  m_cut.move_up();
  m_cut.move_up();
  m_cut.move_left();
  m_cut.move_left();
  EXPECT_TRUE(m_cut.is_finished());
}

TEST_F(TestBiggerMazeGame, MazeGameLeft) {
  m_cut = MazeGame(std::make_shared<SecondMazeGameFactoryTest>());
  m_cut.move_up();
  m_cut.move_up();
  m_cut.move_up();
  m_cut.move_left();
  EXPECT_TRUE(m_cut.is_finished());
}
}  // namespace CPPTest::DesignPatterns::Test