#include <array>
#include <map>
#include <memory>
#include <vector>

namespace CPPTest::DesignPatterns {

enum class Direction { north, south, west, east };

class MapSide {
 public:
  MapSide(const MapSide&) = default;
  MapSide(MapSide&&) = delete;
  MapSide& operator=(const MapSide&) = default;
  MapSide& operator=(MapSide&&) = delete;
  virtual ~MapSide() = default;
  virtual int enter() = 0;

 protected:
  MapSide() = default;
};

class Room : public MapSide {
 public:
  Room(const Room&) = default;
  Room(Room&&) = delete;
  Room& operator=(const Room&) = default;
  Room& operator=(Room&&) = delete;
  ~Room() override = default;
  Room() = default;

  explicit Room(int roomNumber);
  [[nodiscard]] std::shared_ptr<MapSide> get_side(
      const Direction& direction) const;
  void set_side(const Direction& direction,
                const std::shared_ptr<MapSide>& side);
  int enter() override;

 private:
  int m_roomNumber{0};
  std::map<Direction, std::shared_ptr<MapSide>> m_sides = {
      {Direction::north, nullptr},
      {Direction::south, nullptr},
      {Direction::west, nullptr},
      {Direction::east, nullptr},
  };
};

class MazeItf {
 public:
  MazeItf(const MazeItf&) = default;
  MazeItf(MazeItf&&) = delete;
  MazeItf& operator=(const MazeItf&) = default;
  MazeItf& operator=(MazeItf&&) = delete;
  virtual ~MazeItf() = default;

  virtual void add_room(int roomNumber) = 0;
  [[nodiscard]] virtual std::shared_ptr<Room> room_number(
      int roomNumber) const = 0;

 protected:
  MazeItf() = default;
};

class Maze : public MazeItf {
 public:
  Maze(const Maze&) = default;
  Maze(Maze&&) = delete;
  Maze& operator=(const Maze&) = default;
  Maze& operator=(Maze&&) = delete;
  ~Maze() override = default;
  Maze();

  void add_room(int roomNumber) override;
  [[nodiscard]] std::shared_ptr<Room> room_number(
      int roomNumber) const override;

 private:
  std::map<int, std::shared_ptr<Room>> m_rooms;
};

class MazeFactory {};
class PlayerFactory {};
}  // namespace CPPTest::DesignPatterns