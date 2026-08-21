#include <iostream>

void burnStack()
{
  int garbage[100];
  for (int i = 0; i < 100; i++)
  {
    garbage[i] = 0xDEADBEEF;
  }
}
int main()
{
  int pad[6];
  int x, y;
  std::cout << x << "\n";
  std::cout << y << "\n";
  return 0;
}
