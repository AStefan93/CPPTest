#include <array>
#include <memory>
#include <vector>

namespace CPPTest::DesignPatterns {

enum class Direction { north, south, west, east };

class MapSite {
 public:
  MapSite(const MapSite&) = default;
  MapSite(MapSite&&) = delete;
  MapSite& operator=(const MapSite&) = default;
  MapSite& operator=(MapSite&&) = delete;
  virtual ~MapSite() = default;
  virtual void enter() = 0;

 protected:
  MapSite() = default;
};

class Room : public MapSite {
 public:
  Room(const Room&) = default;
  Room(Room&&) = delete;
  Room& operator=(const Room&) = default;
  Room& operator=(Room&&) = delete;
  ~Room() override = default;
  Room() = default;

  explicit Room(int roomNumber);
  [[nodiscard]] std::shared_ptr<MapSite> get_side(
      const Direction& direction) const;
  void set_side(const Direction& direction, std::shared_ptr<MapSite> site);
  void enter() override;

 private:
  int m_roomNumber{0};
  std::array<std::shared_ptr<MapSite>, 4> m_sides;
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
  Maze() = default;

  void add_room(int roomNumber) override;
  [[nodiscard]] std::shared_ptr<Room> room_number(
      int roomNumber) const override;

 private:
  std::vector<std::shared_ptr<Room>> m_rooms;
};

class MazeFactory {};
class PlayerFactory {};
}  // namespace CPPTest::DesignPatterns