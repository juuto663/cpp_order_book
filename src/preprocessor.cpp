#include <iostream> // include is a preprocessor directive

#define MY_MACRO "SUB_STRING" // define is another preprocessor directive. This will replace MY_MACRO with SUB_STRING
#define PRINT_JOE

int main()
{

  // in general, don't do this. This is a C convention, use a namespace
  std::cout << "Hi, my name is " << MY_MACRO << '\n'; // obviously SUB_STRING should be your name

// ifdef, ifndef, if defined() and if !defined(). Conditional compilation. ifdef and ifndef are C style, the other two are c++ style.
#ifdef PRINT_JOE
  std::cout << "Joe\n"; // this will be compiled because PRINT_JOE was defined
#endif

#if defined(PRINT_JOE)
  std::cout << "Joe\n"; // this will be compiled because PRINT_JOE was defined
#endif

#ifdef PRINT_BOB
  std::cout << "Bob\n"; // this will not be compiled because PRINT_JOE was defined
#endif

#if defined(PRINT_BOB)
  std::cout << "Bob\n"; // this will be compiled because PRINT_JOE was defined
#endif

#ifndef PRINT_JOE
  std::cout << "Joe\n"; // this will not be compiled because PRINT_JOE was defined
#endif

#if !defined(PRINT_JOE)
  std::cout << "Joe\n"; // this will not be compiled because PRINT_JOE was defined
#endif

#if !defined(PRINT_BOB)
  std::cout << "Bob\n"; // this will not be compiled because PRINT_JOE was defined
#endif

#ifndef PRINT_BOB
  std::cout << "Bob\n"; // this will be compiled because PRINT_JOE was defined
#endif

#if 0  // Don't compile anything from here
  std::cout << "This will not print\n"; // You do this to comment out a block of code that has a multiline comment since those are not nestable.
#endif // until here

  return 0;
}
