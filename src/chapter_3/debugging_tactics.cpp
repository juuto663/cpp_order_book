#include <iostream>

int getValue()
{
// when debugging. std::cout might not be helpful because it's buffered. So it may
// not print immediately. Use std::cerr instead which is not buffered. To prevent
// modifying and rebuilding by adding ifdef statements to enable debugging.
#ifdef DEBUG
  std::cerr << "getValue() called\n"; // only called when #define DEBUG is added. This can be cluttered and typo prone, so consider using logging
#endif
  return 4;
}

int main()
{
  std::cout << getValue << '\n'; // this will generate a warning cause it will always eval to true (the bug it prints 1 instead 4)
  return 0;
}
