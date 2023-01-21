//
// Created by anderson on 20/01/23.
//

#ifndef DRUNK_HANOI__DISK_HPP_
#define DRUNK_HANOI__DISK_HPP_

class Disk {

 public:

  Disk();

  Disk(int size);

  ~Disk();

  Disk(const Disk &disk);

  Disk &operator=(const Disk &disk);

  bool compare(Disk disc2) const;

  int getSize() const;
 private:
  int size;
};

#endif //DRUNK_HANOI__DISK_HPP_
