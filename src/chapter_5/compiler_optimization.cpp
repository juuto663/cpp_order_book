import <iostream>;

void profilers()
{
  /*
   * Profilers are a way to see what parts of your C++ program are taking the longest
   * and what you should be optimizing.
   */
}

void as_if()
{
  /*
   * The As-If rule in C++ means the compiler can optimize (if enabled) so long as
   * the program doesn't change behavior. That can be reordering, rewriting, or
   * straight up deleting lines. i = i * 2 might be rewritten i += i or i *= 2
   * depending on the hardware
   */
}

void constant_folding()
{
  /*
   * Since the variables are just literals that are printed out, we can replace
   * statements/expressions with their constant.
   */
  std::cout << 4 + 3 << '\n'; // this
  std::cout << 7 << '\n';     // will rewritten to this
}

void constant_propagation()
{
  int x{4};
  std::cout << x << '\n'; // Since the variable is just a literal,
  std::cout << 4 << '\n'; // Rewrite it to look like this.
}

void dead_code_elimination()
{
  /*
   * This is continuing from constant_propagation. Since the print statement no longer
   * needs that x variable storing the literal, we don't need to make that variable at all
   */
  int x{4};               // delete this line
  std::cout << 4 << '\n'; // only include this line
}

void why_const_matters()
{
  /*
   * Optimization is something you have to tell your compiler to do. Not all compilers
   * are the same either. For the above functions to work, the compiler has to realize
   * that variables are just literals that are only printed out, we can propagate a constant
   * to the print statement, and then delete the variable declaration. We can make it easier
   * on the compiler.
   */
  const int x{4}; // Now the compiler has a guarantee this doesn't change and it can replace it in the print statement
  std::cout << x << '\n';
}

void why_not_always_optimize()
{
  /*
   * Because it can potentially rewrite, reorder, or delete lines meaning it is more difficult to debug.
   * You potentially are chasing an issue that you can't see because you aren't debugging the optimized version
   */
}

int main()
{
  return 0;
}
