#include <iostream>

int main()
{
  unsigned short x{65535};
  std::cout << x << '\n'; // prints 65,535
  x++;
  std::cout << x << '\n'; // prints 0
  return 0;
}
