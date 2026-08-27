#include <iomanip> // for output manipulator std::setprecision()
#include <iostream>
#include <limits>
#include <source_location>

void types_of_fp()
{
  // Like with ints, C++ only defines minimums for each type
  auto loc = std::source_location::current();
  std::cout << loc.function_name();
  std::cout << sizeof(float) << '\n';       // typical size is 4 bytes, basically always IEEE 754 compliant
  std::cout << sizeof(double) << '\n';      // typical size is 8 bytes, basically always IEEE 754 compliant
  std::cout << sizeof(long double) << '\n'; // typical size is 8, 12, or 16 bytes. Avoid using this one unless you really need to as it might not be IEEE 754 compliant
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

void printing_floats()
{
  // std::cout is precise to 6 digits, so this code will likely print the same
  // thing regardless. In general though if you include f then it will interpret
  // the value as float, without the f it will be a double
  std::cout << 9.87654321f << '\n';
  std::cout << 9.87654321 << '\n';
  std::cout << 987.654321f << '\n';
  std::cout << 987.654321 << '\n';
  std::cout << 987654.321f << '\n';
  std::cout << 987654.321 << '\n';
  std::cout << 9876543.21f << '\n';
  std::cout << 9876543.21 << '\n';
  std::cout << 0.0000987654321f << '\n';
  std::cout << 0.0000987654321 << '\n';
  std::cout << std::setprecision(17);                             // show 17 digits of precision. Note outside of setw, these are sticky.
  std::cout << 3.33333333333333333333333333333333333333f << '\n'; // f suffix means float (prints 3.3333332538604736)
  std::cout << 3.33333333333333333333333333333333333333 << '\n';  // no suffix means double (prints 3.3333333333333335)
}

int losing_precision_and_rounding_errors()
{
  std::cout << std::setprecision(17);

  double d1{1.0};
  std::cout << d1 << '\n'; // prints 1

  double d2{0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1}; // should equal 1.0
  std::cout << d2 << '\n';                                              // 0.99999999999999989

  return 0;
}

int infinity_nan_and_zero()
{
  // not guaranteed that this function will be supported.
  double zero{0.0};

  double posinf{5.0 / zero}; // positive infinity
  std::cout << posinf << '\n';

  double neginf{-5.0 / zero}; // negative infinity
  std::cout << neginf << '\n';

  double z1{0.0 / posinf}; // positive zero
  std::cout << z1 << '\n';

  double z2{-0.0 / posinf}; // negative zero
  std::cout << z2 << '\n';

  double nan{zero / zero}; // not a number (mathematically invalid, don't do this)
  std::cout << nan << '\n';

  return 0;
}

int main()
{
  types_of_fp();
  std::cout << "======================\n";
  is_ieee_compliant();
  std::cout << "======================\n";
  printing_floats();
  std::cout << "======================\n";
  losing_precision_and_rounding_errors();
  std::cout << "======================\n";
  infinity_nan_and_zero();
  return 0;
}
