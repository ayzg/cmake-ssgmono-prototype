#include <iostream>
#include "project_headers.hpp"

int do_something_executable(int a, int b) {
  // using method from dependency project_a
  do_something(a,b);
  // using method from dependency project_b
  do_something_else(a, b);

  std::cout << "Doing something!" << std::endl;

  return 0;
};


int main() { return do_something_executable(1, 1); }
