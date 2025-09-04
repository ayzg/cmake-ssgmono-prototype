#pragma once
#include <iostream>
#include "library_a.hpp"

int do_something_else(int a, int b) {
  // using method from dependency project_a
  do_something(1,1);

  std::cout << "Doing something else!" << std::endl;
  return 0;
};
