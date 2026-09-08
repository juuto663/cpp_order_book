#include <iostream>

int declaring_const()
{
  /*
   * Use the const keyword (generally before the data type). In general, the
   * compiler can make optimizations with the assumption that variables are
   * immutable, so if you can make it const, then do it.
   */
  const int var{1};
  return var;
}

const int when_not_to_use_const(const int c)
{
  /*
   * It can be super helpful for a function to guarantee that it won't mutate data.
   * However in pass by value functions like this, it is receiving a copy, so it
   * doesn't really matter if the arg here is a const, it just clutters the prototype,
   * so you shouldn't do it in general. With the return type, most compilers will ignore it
   * for fundamental data types and generate a warning. This just messes with stuff.
   * The only time this matters (and it matters a lot) is pass by reference where
   * you aren't dealing with copies
   */
  return 0;
}

int using_macros()
{
  /*
   * Macros are essentially constants, but macros should generally be avoided as much
   * as possible in favor of const. This is for a few reasons:
   *
   * 1. Macros are global to a file and replace EVERYTHING including what is brought in via
   * includes and function names and args, so you can get unwanted substitution.
   *
   * 2. They are much harder to DEBUG. Because they don't work until compilation and your compiler
   * actually never sees them because they have already been substituted, there's a disconnect that
   * is difficult for debuggers and manually debugging.
   *
   * 3. They work differently than everyhting else in c++ so they are unituitive and error-prone. If
   * you can just use a const, use a const.
   */

  return 0;
}

int volatile_the_opposite_of_const()
{
  /*
   * Const is considered a type qualifier. In C++23 there are only 2 type qualifiers: const and volatile.
   * Const means that a value can never change. Volatile means that a value can change at any point and it
   * is used to shut off certain compiler optimizations.
   *
   * You can now appreciate this joke from JF Bastien:
   *
   * Q: How do you know if a C++ developer is qualified?
   * A: You look at their CV.
   */
  return 0;
}

int main()
{
  return 0;
}
