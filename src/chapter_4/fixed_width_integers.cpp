/*
 * C++ only specifies minimums sizes, not maximums. The type, int, has a minimum
 * size of 16 bits. On most systems it is 32 bits, but if you assume that is true
 * then you will run into trouble on systems that implement the minimum
 */

#include <cstdint>
#include <iostream>

void int_overflow_16_vs_32()
{
  int x{32768};
  x++;
  std::cout << x << '\n'; // will overflow on 16-bit systems, will be fine on 32-bit
}

void fixed_width_integers()
{
  std::int8_t a{};   // range: -128 to 127
  std::uint8_t b{};  // range: 0 to 255
  std::int16_t c{};  // range: -32,768 to 32,767
  std::uint16_t d{}; // range: 0 to 65,535
  std::int32_t e{};  // range: -2,147,483,648 to 2,147,483,647
  std::uint32_t f{}; // range: 0 to 4,294,967,295
  std::int64_t g{};  // range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
  std::uint64_t h{}; // range: 0 to 18,446,744,073,709,551,615
}

void disclaimer_about_uint8()
{
  // 8 bit integers are generally interpreted as chars, not ints. This is because this
  // fixed width types aren't actually new types. They are just aliases, so if you are on a
  // system where 32-bits is a long, std::int32_t is an alias for long. On systems where
  // 32-bits is an int, std::int32_t is an alias for int. This also means that std::8int_t
  // is an alias for char on most systems

  std::int8_t x{65};
  std::uint8_t y{65};

  std::cout << "Signed integer with value of 65: " << x << '\n';   // this will print A, not 65
  std::cout << "Unsigned integer with value of 65: " << y << '\n'; // this will print A, not 65
}

/*
 * Potential downsides of fixed widths ints are
 * 1. It is not guaranteed your machine supports it. This is rare, but if you are really old hardware or embedded architecture
 * it is risk
 * 2. Your computer might be faster with larger data types. Using an int32_t is more precise, but you hardware might be faster
 * at processing 64-bit numbers. Still most programs are memory bound not CPU bound, so it is unlikely that your program will
 * run faster by upgrading types to larger ones that play to your CPU's strengths. There is another type to consider though:
 */

void fast_and_least_types()
{
  // this are guaranteed to exist. They will pick the fixed width that your CPU is the fastest at processing. There is also
  // the least data types that give the smallest types that are at least a certain length
  std::int_fast32_t x{}; // the fastest (cpu wise) 32 bit int
  std::int_least8_t{};   // the smallest int that is at least 8 bits wide
  std::cout << "least 8:  " << sizeof(std::int_least8_t) * 8 << " bits\n";
  std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
  std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
  std::cout << '\n';
  std::cout << "fast 8:  " << sizeof(std::int_fast8_t) * 8 << " bits\n";
  std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
  std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";

  // least 8:  8 bits
  // least 16: 16 bits
  // least 32: 32 bits
  // fast 8:  8 bits
  // fast 16: 64 bits
  // fast 32: 64 bits
  // Notice how 64 bits is the fastest for 16 and 32
  // Caveats: Memory wasted, implementation dependent so behavior changes per machine
  // if you wanted to say intentionally overflow a variable, and not many people are
  // familiar with them. So in general, don't use them, but they are options
}

/*
 * Best practice
 * Prefer int when the size of the integer doesn’t matter (e.g. the number will always fit within the range of a 2-byte signed integer).
 * For example, if you’re asking the user to enter their age, or counting from 1 to 10, it doesn’t matter whether int is 16-bits or 32-bits
 * (the numbers will fit either way). This will cover the vast majority of the cases you’re likely to run across.
 * Prefer std::int#_t when storing a quantity that needs a guaranteed range.
 * Prefer std::uint#_t when doing bit manipulation or well-defined wrap-around behavior is required (e.g. for cryptography or random number generation).
 *
 * Avoid the following when possible:
 * short and long integers (prefer a fixed-width integer type instead).
 * The fast and least integral types (prefer a fixed-width integer type instead).
 * Unsigned types for holding quantities (prefer a signed integer type instead).
 * The 8-bit fixed-width integer types (prefer a 16-bit fixed-width integer type instead).
 * Any compiler-specific fixed-width integers (for example, Visual Studio defines __int8, __int16, etc…)
 */

void what_about_size_t()
{
  std::cout << sizeof(int) << '\n'; // This will print 4

  // But what type is size_t? int? long? long long? The answer is that it is of type std::size_t which
  // means the compiler decides what the type is. Many headers include size_t, but if you need to use it
  // use the <cstddef> because it has the least amount of other stuff in it.
  int x{5};
  std::size_t y{sizeof(int)};
  std::cout << y << '\n';                   // will print 4
  std::cout << sizeof(std::size_t) << '\n'; // this will print 8
}

int main()
{
  what_about_size_t();
  return 0;
}
