//
// Created by anderson on 20/01/23.
//

#include <stack>
#include <iostream>
#include "Player.hpp"
#include "Disk.hpp"

int drunkenTowerOfHanoi(int discs, int tiles, int rodA, int rodB, int rodC, int trials) {
  int sumNumOfTurns = 0;
  Player *player;

  for (int i = 0; i < trials; i++) {
    auto *gameBoard = new std::stack<Disk>[tiles];

    for(int j = 0; j < tiles; j++)
    {
      gameBoard[j] = std::stack<Disk>();
    }
    for(int j = discs; j > 0; j--)
    {
      // for the total number of discs, push them onto rodA in order of smallest at the top and largest at the bottom
      gameBoard[rodA-1].push(*new Disk(j));
    }
    player = new Player(rodB-1);

    while(!(gameBoard[rodA-1].empty() && gameBoard[rodB-1].empty() && player->getCurrentDisk() == nullptr))
    {
      // refer to standard algorithm for solution
      player->solve(discs, rodA, rodB, rodC, tiles, gameBoard);
    }
    // add the current players number of turns to the sum of number of turns
    sumNumOfTurns += player->getNumOfTurns();
  }
  return sumNumOfTurns / trials;
}

int main() {
  std::cout << "(2,5,1,3,5) has to be 60 and it is: ";
  std::cout << drunkenTowerOfHanoi(2, 5 , 1, 3, 5, 10000) << std::endl;

  std::cout << "(3,20,4,9,17) has to be 2358 and it is: ";
  std::cout << drunkenTowerOfHanoi(3, 20, 4, 9, 17, 100001) << std::endl;

  return 0;
}