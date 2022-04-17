// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T n[size] = {0};
    int first = 0, last = 0;
 public:
  void push(T value) {
      int j = last;
      while ((--j >= first) && (value.prior > n[j % size].prior)) {
          n[(j + 1) % size] = n[j % size];
      }
      n[(j+1) % size] = value;
      last++;
  }
  T pop() {
      return n[(first++) % size];
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
