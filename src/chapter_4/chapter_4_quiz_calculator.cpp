#include <iostream>

double get_double()
{
  double x{};
  std::cin >> x;
  return x;
}

char get_operand()
{
  char x{};
  std::cin >> x;
  return x;
}

void print_results(double result)
{
  std::cout << "Result: " << result;
}

int main()
{
  std::cout << "Enter a double: ";
  double x{get_double()};

  std::cout << "Enter another double: ";
  double y{get_double()};

  std::cout << "You entered: " << x << " and " << y << '\n';

  std::cout << "Enter an operand (+, -, *, /): ";
  char operand{get_operand()};

  if (operand == '+')
  {
    print_results(x + y);
  }
  else if (operand == '-')
  {
    print_results(x - y);
  }
  else if (operand == '*')
  {
    print_results(x * y);
  }
  else if (operand == '/')
  {
    print_results(x / y);
  }
  else
  {
    std::cout << "Operand " << operand << " not supported. Exiting.";
    return 1;
  }

  return 0;
}
