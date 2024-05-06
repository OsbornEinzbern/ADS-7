// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template <typename T, int size>
class TPQueue {
 private:
  T data[10] = {};
  int index = 0, start = 0;

 public:
  T pop() {
    start += 1;
    return data[start - 1];
  }

  void push(T elem) {
    data[index] = elem;
    index += 1;
    for (int i = start; i < index; i++) {
      for (int j = start; j < index - 1; j++) {
        if (data[j].prior < data[j + 1].prior) {
          T boofer = data[j];
          data[j] = data[j + 1];
          data[j + 1] = boofer;
        }
      }
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
