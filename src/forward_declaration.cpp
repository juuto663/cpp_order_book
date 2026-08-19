#include <iostream>

// Need a prototype since add is defined in another file.
// The function has external linkage thought by default.
int add(int x, int y);

int main()
{
  int x{4};
  int y{12};
  int z{add(x, y)};
  std::cout << z;
}
