#include "maze.hpp"

namespace CPPTest::DesignPatterns {
Room::Room(const int roomNumber) : m_roomNumber(roomNumber) {}
std::shared_ptr<MapSide> Room::get_side(const Direction& direction) const {
  return m_sides.find(direction)->second;
}
void Room::set_side(const Direction& direction,
                    const std::shared_ptr<MapSide>& side) {
  m_sides[direction] = side;
}
int Room::enter() { return m_roomNumber; }
Maze::Maze() { m_rooms[0] = std::make_shared<Room>(0); }
void Maze::add_room(int roomNumber) {
  m_rooms[roomNumber] = std::make_shared<Room>(roomNumber);
}
std::shared_ptr<Room> Maze::room_number(const int roomNumber) const {
  return m_rooms.find(roomNumber)->second;
}
}  // namespace CPPTest::DesignPatterns