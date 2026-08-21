#include <iostream>

int readNumber()
{
  std::cout << "Enter an integer: ";
  int input{};
  std::cin >> input;
  return input;
}

void writeAnswer(int output)
{
  std::cout << output;
}

int main()
{
  int num1{readNumber()};
  int num2{readNumber()};
  writeAnswer(num1 + num2);
  return 0;
}
