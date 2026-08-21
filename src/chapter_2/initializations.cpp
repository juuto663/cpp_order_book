// There are multiple ways of initializing things in c++. Here are those ways. Main takeaway is use list or zero initialization
// It is want Bjourne recommends

int main()
{
  int a; // default-initialization (no initializer)
         // in this case, a is a indeterminate or "garbage" value.

  // Traditional Initializers
  int b = 5; // copy-initialization (initial value after the equals sign)
             // Copied behavior from C. This has fallen out of favor in modern C++
             // because it is less efficient than other initializers. C++ 17 helped
             // it be more efficient, so some people advocate for it and it is common
             // in older code and it is still the way in C.

  int c(5); // direct-initialization (initial value in the parenthesis)
            // This was introduced as a more efficient initializer for complex objects
            // like classes. It has also fallen out of favor because the direct-list-initialization
            // surpassed it. However, direct-list-initialization has a couple quirks as well so
            // you'll sometimes see direct-initialization in certain use cases. It is also used
            // in casting like via static_cast

  // Modern initializers. Before C++11 which one you used mattered a lot more. List initialization
  // is answer to that with one way that works well and isn't confused with function calls or assignments
  // It also can initialize objects witha list of values rather than a single value which is why we call it list-initialization
  int d{7};    // direct-list-initialization (initial value in braces). Preferred way of initializing
  int d = {7}; // copy-list-initialization. Rarely used.
  int e{};     // value-initialization (empty braces). Normally initializes to 0 (or whatever makes the most sense for 0 depending on the type)
               // If it initializes to 0, we call it zero-initialization

  // As of C++17, copy/direct/direct-list-initialization behave identically in most cases. They do differ though. One of the reasons
  // we like list initialization is because it disallows "narrowing conversions" for example:
  int w1{4.5};  // compilation ERROR: list-init does not allow narrowing conversions
  int w2 = 4.5; // compiles and truncates so w2 is copy initialized to 4
  int w3(4.5);  // compiles and truncates so w3 is direct initialized to 4

  // Side note: [[maybe_unused]]
  // In C++17 you can prepend your initialization with [[maybe_unused]]. This is typically not desirable
  // but imagine some mathematical constants that may be useful.
  [[maybe_unused]] double pi{3.1415265}; // compiler won't complain anymore

  return 0;
}
