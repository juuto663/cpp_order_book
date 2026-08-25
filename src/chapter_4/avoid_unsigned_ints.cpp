/*
 * A lot of C++ shops like Google will say not to use unsigned ints. Since
 * the bottom of the range is 0, it is potentially that you will overflow
 * and wrap back around at the top of the range. With unsigned ints, the number
 * has to get pretty large (2.1 billionish) in either the positive or negative
 * direction before it overflows. Consider this:
 */

#include <iostream>

void overflow_zero()
{
  unsigned int x{2};
  unsigned int y{3};
  std::cout << x - y << '\n'; // This will not display -1, easy mistake especially in loops that are decrementing
}

/*
 * Even worse are operations that combine signed and unsigned. Generally, signed ints
 * are converted to unsigned ints. Imagine this case:
 */

void combine_signed_and_unsigned()
{
  signed int x{2}; // signed here is unnecessary, it's just for emphasis
  unsigned int y{3};
  std::cout << x - y << '\n'; // prints 4294967295
}

void comparing_signed_and_unsigned()
{
  signed int x{-1}; // signed here is unnecessary, it's just for emphasis
  unsigned int y{3};
  if (x < y)
  {
    std::cout << "X is smaller than Y\n"; // This does not execute.
  }
  else
  {
    std::cout << "X is larger than Y\n"; // This will execute, because x gets covered to unsigned
  }
}

void incorrect_param_convert_to_unsigned(unsigned int x)
{
  std::cout << x << '\n'; // if you pass a signed int of value -1, it will silently cast/convert and print 4294967295
}

/*
 * Side note that sometimes on memory constrained devices like arduinos, unsigned ints are more common since the space
 * for extra bits is not a luxury. Also for bit operations and certain algorithms, we tend to prefer unsigned ints.
 */

int main()
{
  signed int x{-1};
  incorrect_param_convert_to_unsigned(x);
  return 0;
}
