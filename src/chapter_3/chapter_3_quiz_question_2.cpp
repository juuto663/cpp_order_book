#include <iostream>

int readNumber()
{
  std::cout << "Please enter a number: ";
  int x{};
  std::cin >> x;
  std::cerr << "Num is " << x << '\n';
  return x;
}

void writeAnswer(int x)
{
  std::cerr << "X is " << x << '\n';
  std::cout << "The quotient is: " << x << '\n';
}

int main()
{
  int x{};
  int y{};
  x = readNumber();
  x = readNumber();
  writeAnswer(x / y);

  return 0;
}
