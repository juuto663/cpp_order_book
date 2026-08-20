#include <iostream>
/*
 * If you recall, there is a fake_helper.cpp file in this repo. It has the function add in it.
 * That file is just another file I have to compile with this one to use the add function. I also
 * need a forward declaration (function prototype) to use it. That is annoying if I have a bunch
 * to use. Instead, let's use a header file
 */

#include "add_function_header.h" // Need double quotes cause we made it
int main()
{
  std::cout << add(3, 4) << "\n";
  return 0;
}
