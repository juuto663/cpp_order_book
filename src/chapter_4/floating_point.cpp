#include <iostream>
#include <limits>
#include <source_location>

void types_of_fp()
{
  // Like with ints, C++ only defines minimums for each type
  auto loc = std::source_location::current();
  std::cout << loc.function_name();
  std::cout << sizeof(float) << '\n'; // typical size is 4 bytes, basically always IEEE 754 compliant
  std::cout << sizeof(double) << '\n';             // typical size is 8 bytes, basically always IEEE 754 compliant
  std::cout << sizeof(long double) << '\n';        // typical size is 8, 12, or 16 bytes. Avoid using this one unless you really need to as it might not be IEEE 754 compliant
}

void is_ieee_compliant()
{
  auto loc = std::source_location::current();
  std::cout << loc.function_name();
  std::cout << std::boolalpha; // print bool as true or false rather than 1 or 0
  std::cout << "float: " << std::numeric_limits<float>::is_iec559 << '\n';
  std::cout << "double: " << std::numeric_limits<double>::is_iec559 << '\n';
  std::cout << "long double: " << std::numeric_limits<long double>::is_iec559 << '\n';
}

int main()
{
  types_of_fp();
  std::cout << "======================\n";
  is_ieee_compliant();
  return 0;
}
