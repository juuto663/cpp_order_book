/* This is the content, just a function prototype. fake_helper.cpp has the definition.
 * It has to be this way. Otherwise, if multiple files included this header file and
 * it had the full definition, then there would be multiple identical definitions
 * for the same function, which violates ODR (one definition rule) and the linker
 * will throw. Another reason is that if that serves as the authoritattive source
 * of truth for the function signature. If a header file mistypes it (like they put
 * the wrong data type) a compilation error will occur, finding the issue at compilation
 * not at linking. There are certain exceptions we will learn about later such as for
 * in-line functions, inline variables, types, and templates.
 */

/* Side note. Don't include .cpp files cause it is weird, it might a huge file, if the
 * .cpp file changes it will cause both to recompile taking a while and it might break ODR.
 * Also Use double quotes to include header files that you’ve written or are expected
 * to be found in the current directory. Use angled brackets to include headers that come
 * with your compiler, OS, or third-party libraries you’ve installed elsewhere on your system.
 */

/* The preprocessing directives are a "header guard" essentially. If multiple files were to
 * include this header file and we had a full definition in here (which outside of templates you shouldn't do)
 * it would break ODR. With the guard, whichever one includes first will define the macro, so when the
 * header file is included again it just won't compile and won't break ODR. A better (although not C++ standard) is to use #pragma once
 */

#pragma once // Does the same thing as the guard although it won't dedupe identical header files spread across the system. Since it is not standard in the c++ standard it is not guaranteed that a compiler will support it.

#ifndef ADD
#define ADD
int add(int x, int y);
#endif
