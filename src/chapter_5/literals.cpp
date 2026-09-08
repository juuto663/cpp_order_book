#include <iostream>
#include <typeinfo>

void literal_suffixes()
{
  /*
   * Literals are raw values you put into things. For instance, literals
   * with ints are 0, 5, 26, etc... When instantiating a type, you often provide
   * a literal to initialize. If the default literal for a certain type (like how 5.0 is
   * not the default literal type for an int) you can supply suffixes to specify.
   *
   * data type          suffix                                  meaning
   * ----------------------------------------------------------------------------
   * integral	        u or U	                                unsigned int
   * integral	        l or L	                                long
   * integral	        ul, uL, Ul, UL, lu, lU, Lu, LU	        unsigned long
   * integral	        ll or LL	                        long long
   * integral	        ull, uLL, Ull, ULL, llu, llU, LLu, LLU	unsigned long long
   * integral	        z or Z	                                The signed version of std::size_t (C++23)
   * integral	        uz, uZ, Uz, UZ, zu, zU, Zu, ZU	        std::size_t (C++23)
   * floating point	f or F	                                float
   * floating point	l or L	                                long double
   * string	        s	                                std::string
   * string	        sv	                                std::string_view
   *
   * For longs the best practice is to use captial L even though lowercase is possible. Also note that
   * s and sv require extra modules in std
   */
  std::cout << 5 << '\n';  // Without a suffix, the default is a signed int.
  std::cout << 5l << '\n'; // With the suffix, l, it is now a long.
  std::cout << 5u << '\n'; // With the suffix, u, it is now an unsigned int.
}

void floating_point_literals()
{
  std::cout << 5.0 << " is of type: " << typeid(5.0).name() << '\n';   // defaults to double for floating point type
  std::cout << 5.0f << " is of type: " << typeid(5.0f).name() << '\n'; // specifies float specifically
}

int main()
{
  literal_suffixes();
  floating_point_literals();
  return 0;
}
