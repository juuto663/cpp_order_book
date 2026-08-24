#include <iostream>

int main()
{
  std::cout << 20 / 5 << '\n'; // will print 4
  std::cout << 8 / 5 << '\n';  // will print 1 cause two ints yield an int that truncates the decimal portion
  return 0;
}
