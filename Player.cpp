//
// Created by anderson on 20/01/23.
//

#include <stack>
#include <cstdlib>
#include "Player.hpp"

Player::Player(int location) {
  this->location = location;
  this->currentDisk = nullptr;
  this->numOfTurns = 0;
}

int Player::getLocation() {
  return this->location;
}
int Player::getNumOfTurns() {
  return this->numOfTurns;
}
void Player::changeLocation(int currentLocation, int max, double direction) {
  // if the players location is the leftmost location
  if (currentLocation == 0)
    // the player must move right in this case
    this->location++;
    // likewise, if the players location is at the rightmost location
  else if (currentLocation == max - 1)
    // the player must move left
    this->location--;
    // otherwise the movement is randomized by direction
    // if direction should be rounded up
  else if (direction >= 0.5)
    // move right
    this->location++;
    // if the direction should be rounded down
  else
    // move left
    this->location--;
}
void Player::moveTo(int goal, int tiles) {
  // loop until at the correct location
  while (getLocation() != goal) {
    // use random to randomly pick a direction
    double direction = ((double) rand() / (RAND_MAX));
    // call locationChange()
    this->changeLocation(getLocation(), tiles, direction);
    // increment number of turns
    this->numOfTurns++;
  }
}

void Player::replace(int moveFrom, int moveTo, int tiles, std::stack<Disk> *gameBoard) {
  // first the player must pick up a disc from the first goal
  pickUp(moveFrom, tiles, gameBoard);
  // and then the player will set down the disc at the second goal
  setDown(moveTo, tiles, gameBoard);
}

void Player::pickUp(int goal, int tiles, std::stack<Disk> *gameBoard) {
  // move to the goal location
  moveTo(goal, tiles);
  // collect the disc at the current location
  this->currentDisk = &gameBoard[goal].top();
  // remove the disc from the rod
  gameBoard[goal].pop();
}
void Player::setDown(int goal, int tiles, std::stack<Disk> *gameBoard) {
  // move to the goal location
  moveTo(goal, tiles);
  // push the disc onto the rod
  gameBoard[goal].push(*getCurrentDisk());
  // remove the disc from the player
  this->currentDisk = nullptr;
}

void Player::solve(int discs, int rodA, int rodB, int rodC, int tiles, std::stack<Disk> *gameBoard) {
  // base case of only 1 disc
  if (discs == 1) {
    // move rodA top to rodC
    replace(rodA - 1, rodC - 1, tiles, gameBoard);
  }
    // Recursive case
  else {
    // move n-1 discs from starting rod to middle rod
    solve(discs - 1, rodA, rodC, rodB, tiles, gameBoard);
    // move nth disc to ending ring
    replace(rodA - 1, rodC - 1, tiles, gameBoard);
    // move n-1 discs from middle rod to ending rod
    solve(discs - 1, rodB, rodA, rodC, tiles, gameBoard);
  }
}

Disk *Player::getCurrentDisk() {
    return this->currentDisk;
}

