
#include <memory>

#include "maze.hpp"
namespace CPPTest::DesignPatterns {

class PlayerItf {
public:
  PlayerItf(const PlayerItf &) = default;
  PlayerItf(PlayerItf &&) = delete;
  PlayerItf &operator=(const PlayerItf &) = default;
  PlayerItf &operator=(PlayerItf &&) = delete;
  virtual ~PlayerItf() = default;

  virtual void update() = 0;

protected:
  PlayerItf() = default;
};

class Player : public PlayerItf {
public:
  Player() = default;
  void update() override;

private:
  unsigned int m_lives{3};
  bool m_alive{true};
};

class MazeGameFactoryItf {
public:
  MazeGameFactoryItf(const MazeGameFactoryItf &) = default;
  MazeGameFactoryItf(MazeGameFactoryItf &&) = delete;
  MazeGameFactoryItf &operator=(const MazeGameFactoryItf &) = default;
  MazeGameFactoryItf &operator=(MazeGameFactoryItf &&) = delete;
  virtual ~MazeGameFactoryItf() = default;

  [[nodiscard]] virtual std::shared_ptr<MazeItf> create_maze() const = 0;
  [[nodiscard]] virtual std::shared_ptr<PlayerItf> create_player() const = 0;
  [[nodiscard]] virtual int get_final_room() const = 0;

protected:
  MazeGameFactoryItf() = default;
};

class MazeGameFactory : public MazeGameFactoryItf {
public:
  [[nodiscard]] std::shared_ptr<MazeItf> create_maze() const override;
  [[nodiscard]] std::shared_ptr<PlayerItf> create_player() const override;
  [[nodiscard]] int get_final_room() const override;
};
class MazeGame {
public:
  MazeGame() = default;
  explicit MazeGame(const std::shared_ptr<MazeGameFactoryItf> &factory);
  void move_up();
  void move_down();
  void move_left();
  void move_right();
  [[nodiscard]] bool is_finished() const;

private:
  void update_state();
  bool is_final_room();
  std::shared_ptr<MazeItf> m_maze = std::make_shared<Maze>();
  std::shared_ptr<PlayerItf> m_player = std::make_shared<Player>();
  int m_final_room{0};
  int m_playerPosition{0};
  bool m_isFinished{false};
};

} // namespace CPPTest::DesignPatterns