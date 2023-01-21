//
// Created by anderson on 20/01/23.
//

#include "Disk.hpp"

Disk::Disk() {
  this->size = 1;
}

Disk::Disk(int size) {
  this->size = size;
}

Disk::~Disk() {

}
Disk::Disk(const Disk &disk) {
  this->size = disk.size;
}
Disk &Disk::operator=(const Disk &disk) {
  if (this != &disk) {
    this->size = disk.size;
  }
  return *this;
}

bool Disk::compare(Disk disc2) const {
  bool isLarger;

  if (this->size > disc2.getSize()) {
    isLarger = true;
  } else if (this->size < disc2.getSize()) {
    isLarger = false;
  } else {
    isLarger = false;
  }
  return isLarger;
}

int Disk::getSize() const {
  return this->size;
}
