//
// Created by anderson on 20/01/23.
//

#include <stack>
#include <iostream>
#include <cmath>
#include "Player.hpp"
#include "Disk.hpp"

int drunkenTowerOfHanoi(int discs, int tiles, int rodA, int rodB, int rodC, int trials) {
  int sumNumOfTurns = 0;
  Player *player;

  for (int i = 0; i < trials; i++) {
    auto *gameBoard = new std::stack<Disk>[tiles];

    for (int j = 0; j < tiles; j++) {
      gameBoard[j] = std::stack<Disk>();
    }
    for (int j = discs; j > 0; j--) {
      // for the total number of discs, push them onto rodA in order of smallest at the top and largest at the bottom
      Disk newDisk(j);
      gameBoard[rodA - 1].push(newDisk);
    }
    player = new Player(rodB - 1);

    while (!(gameBoard[rodA - 1].empty() && gameBoard[rodB - 1].empty() && player->getCurrentDisk() == nullptr)) {
      // refer to standard algorithm for solution
      player->solve(discs, rodA, rodB, rodC, tiles, gameBoard);
    }
    // add the current players number of turns to the sum of number of turns
    sumNumOfTurns += player->getNumOfTurns();
    // free the memory allocated to the player
    delete[] gameBoard;
    delete player;
  }
//  delete player;
  return sumNumOfTurns / trials;
}

long simpleSolver(int n, int k, int a, int b, int c) {
  int g = pow(2, n + 2) - 3 - pow(-1, n);

  g /= 6;
  return 2 * g * (c - a) * (k - 1) - (2 * k - b - c) * (c - b);
}

long problemSolver(long k, long a, long b, long c) {
  long total_awaited_number = 0;
  long temp = 1;
  long previous = 0;
  long current = 1;
  long mod2 = pow(10, 9);

  while (temp < 10001) {
    long long awaited_number = ((2 * current * (c - a) * (k - 1)) - ((2 * k - b - c) * (c - b))) % mod2;
    total_awaited_number = (total_awaited_number + awaited_number) % mod2;
    long old = (current + (2 * previous) + 1) % mod2;
    previous = current;
    current = old;
    k = (k * 10) % mod2;
    a = (a * 3) % mod2;
    b = (b * 6) % mod2;
    c = (c * 9) % mod2;
    temp++;
  }
  return total_awaited_number;
}

int main() {
  std::cout << "(2,5,1,3,5) has to be 60 and it is: ";
  std::cout << drunkenTowerOfHanoi(2, 5, 1, 3, 5, 10000) << std::endl;
  std::cout << "(2,5,1,3,5) has to be 60 and it is: ";
  std::cout << simpleSolver(2, 5, 1, 3, 5) << std::endl;

//  std::cout << "(3,20,4,9,17) has to be 2358 and it is: ";
//  std::cout << drunkenTowerOfHanoi(3, 20, 4, 9, 17, 100001) << std::endl;
  std::cout << "(3,20,4,9,17) has to be 2358 and it is: ";
  std::cout << simpleSolver(3, 20, 4, 9, 17) << std::endl;

  std::cout << "The number is: ";
  std::cout << problemSolver(10, 3, 6, 9) << std::endl;
  return 0;
}