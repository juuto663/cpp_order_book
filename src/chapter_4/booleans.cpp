#include <iostream>
#include <tuple>

std::tuple<bool, bool, bool> instantiating_bools()
{
  // These are actually integral types, not strings.
  // 0 is false, 1 is true.
  bool b1{true};
  bool b2{false};
  bool b3{};           // default initialize to false
  return {b1, b2, b3}; // returning reads the variables, so no unused-variable warnings
}

void printing_true_or_false()
{
  std::cout << true << '\n';           // prints 1
  std::cout << false << '\n';          // prints 0
  std::cout << std::boolalpha << '\n'; // sets std::cout modifier to print true or false (sticky)
  std::cout << true << '\n';           // prints true
  std::cout << false << '\n';          // prints false
}

std::tuple<bool, bool> integer_to_boolean_conversion()
{
  bool bFalse{0}; // okay: initialize to false
  bool bTrue{1};  // okay: initialize to true
  // bool bNo{2};    // error: narrowing conversions disallowed
  return {bFalse, bTrue};
}

void cin_booleans_numeric()
{
  // cin by default only accepts ints for bool values. Any number
  // that isn't 0 will be interpreted as true and causes cin to
  // enter failure mode. Any non-numeric answer is interpreted
  // as false and will also cause cin to enter failure mode
  bool b{};
  std::cout << "Enter a boolean value: ";
  std::cin >> b;
  std::cout << "You entered: " << b << '\n';

  /*
   * Output of this:
   * Enter a boolean value: true
   * You entered: 0
   */
}

void cin_booleans_strings()
{
  // if you add std::boolalpha to cin, it will take in lowercase true or false
  // and will no longer take in numbers
  bool b{};
  std::cout << "Enter a boolean value: ";
  std::cin >> std::boolalpha; // now it also accepts lowercase true or false
  std::cin >> b;
  std::cout << std::boolalpha; // now it prints true or false
  std::cout << "You entered: " << b;
  /*
   * ❯ ./build/chapter_4/booleans
   * Enter a boolean value: true
   * You entered: true
   *
   * ❯ ./build/chapter_4/booleans
   * Enter a boolean value: 24
   * You entered: false
   */
}

int main()
{
  cin_booleans_strings();
  return 0;
}
