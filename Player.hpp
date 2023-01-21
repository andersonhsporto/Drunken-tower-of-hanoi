//
// Created by anderson on 20/01/23.
//

#ifndef DRUNK_HANOI__PLAYER_HPP_
#define DRUNK_HANOI__PLAYER_HPP_

#include "Disk.hpp"
#include <cstddef>

class Player {

 public:
  Player(int location);

  int getLocation();

  int getNumOfTurns();

  void changeLocation(int location, int max, double direction);

  Disk *getCurrentDisk();

  void moveTo(int goal, int tiles);

  void replace(int moveFrom, int moveTo, int tiles, std::stack<Disk> *gameBoard);

  void pickUp(int goal, int tiles, std::stack<Disk> *gameBoard);

  void setDown(int goal, int tiles, std::stack<Disk> *gameBoard);

  void solve(int discs, int rodA, int rodB, int rodC,
             int tiles, std::stack<Disk> *gameBoard);

 private:
  int location;
  Disk *currentDisk;
  int numOfTurns;

};

#endif //DRUNK_HANOI__PLAYER_HPP_
