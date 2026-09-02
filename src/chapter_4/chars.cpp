#include <iostream>

char get_input()
{
  char x{};
  std::cout << "Enter a char: ";
  std::cin >> x;
  return x;
}

void get_multiple_queued_inputs()
{
  // =a and b can only hold one character, so if you enter multiple
  // cin will queue your input. For example this prints:
  // Enter a char: ab
  // First char: a
  // Second char: b
  //
  // Note that it will skip white space, like this:
  // Enter a char: a b
  // First char: a
  // Second char: b
  char a{};
  std::cout << "Enter a char: ";
  std::cin >> a;
  char b{};
  std::cin >> b;
  std::cout << "First char: " << a << '\n';
  std::cout << "Second char: " << b << '\n';
}
void using_cin_get()
{
  // Since std::cin skips whitespace we can use std::cin.get() to avoid that implicit behavior
  // enter chars with white space (a b): a b
  // Entered: a
  // Entered:
  // Entered: b
  char x{};
  char y{};
  char z{};
  std::cout << "enter chars with white space (a b): ";
  std::cin.get(x);
  std::cin.get(y);
  std::cin.get(z);
  std::cout << "Entered: " << x << '\n';
  std::cout << "Entered: " << y << '\n';
  std::cout << "Entered: " << z << '\n';
}

int main()
{
  char x{get_input()};
  std::cout << x << '\n';
  get_multiple_queued_inputs();
  using_cin_get();
  return 0;
}
