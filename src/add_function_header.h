// A header guard should go here. For right now until you learn what that is we will omit it.

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
int add(int x, int y);
