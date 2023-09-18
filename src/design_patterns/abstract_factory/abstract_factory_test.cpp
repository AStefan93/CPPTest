#include "abstract_factory.hpp"

#include <vector>

#include "gtest/gtest.h"

namespace CPPTest::DesignPatterns::Test {

class TestMazeGame : public ::testing::Test {
  class FirstMazeGameFactoryTest : public MazeGameFactoryItf {
   public:
    [[nodiscard]] std::shared_ptr<MazeItf> create_maze() const override {
      return std::make_shared<Maze>();
    }
    [[nodiscard]] std::shared_ptr<PlayerItf> create_player() const override {
      return std::make_shared<Player>();
    }
    [[nodiscard]] int get_final_room() const override { return 2; }
  };

 protected:
  void SetUp() override {
    m_cut = MazeGame(std::make_shared<FirstMazeGameFactoryTest>());
  }
  void TearDown() override {}

  // NOLINTNEXTLINE(*-non-private-member-variables-in-classes)
  MazeGame m_cut;
};

TEST_F(TestMazeGame, MoveUp) {
  m_cut.move_up();
  m_cut.move_up();
  EXPECT_TRUE(m_cut.is_finished());
}

TEST_F(TestMazeGame, MoveDown) {
  m_cut.move_down();
  m_cut.move_down();
  EXPECT_TRUE(m_cut.is_finished());
}

TEST_F(TestMazeGame, MoveLeft) {
  m_cut.move_left();
  m_cut.move_left();
  EXPECT_TRUE(m_cut.is_finished());
}

TEST_F(TestMazeGame, MoveRight) {
  m_cut.move_right();
  m_cut.move_right();
  EXPECT_TRUE(m_cut.is_finished());
}

TEST_F(TestMazeGame, MazeGame) {
  class SecondMazeGameFactoryTest : public MazeGameFactoryItf {
   public:
    [[nodiscard]] std::shared_ptr<MazeItf> create_maze() const override {
      return std::make_shared<Maze>();
    }
    [[nodiscard]] std::shared_ptr<PlayerItf> create_player() const override {
      return std::make_shared<Player>();
    }
    [[nodiscard]] int get_final_room() const override { return 4; }
  };

  m_cut = MazeGame(std::make_shared<SecondMazeGameFactoryTest>());
  m_cut.move_up();
  m_cut.move_up();
  m_cut.move_left();
  m_cut.move_left();
  EXPECT_TRUE(m_cut.is_finished());
}
}  // namespace CPPTest::DesignPatterns::Test