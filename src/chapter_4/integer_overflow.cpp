#include <iostream>

int main()
{
  int x{2'147'483'647};
  std::cout << x << '\n';
  x++;
  std::cout << x; // will overflow
  return 0;
}
