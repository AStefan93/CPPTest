#include "maze.hpp"

namespace CPPTest::DesignPatterns {
Room::Room(const int roomNumber) : m_roomNumber(roomNumber) {}
void Room::enter() {}
void Maze::add_room(int roomNumber) {
  m_rooms.push_back(std::make_shared<Room>(roomNumber));
}
std::shared_ptr<Room> Maze::room_number(const int roomNumber) const {
  return m_rooms.at(roomNumber);
}
}  // namespace CPPTest::DesignPatterns