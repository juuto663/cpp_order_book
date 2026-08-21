/* How to design programs
 * 1. Define your goal. This should be just a couple of sentences max. Examples are "Generate a list of stock recommendations for stocks that have high dividends".
 * 2. Define requirements. These are the constraints that your solution needs to follow (time, budget, space, memory, etc). This should be focused on the what, not the how.
 * Examples include: Phone numbers need to be saved to contact later, we need a testable version in 7 days, it should crash less than 0.1% of the time
 * 3. Define your tools, targets, and backup plan. What OS are we running on? What set of tools is available to you? How should we test and release this?
 * 4. Break hard problems into easy ones. You don't "clean your house," you do the laundry, and then the dishes, and then you vacuum the living room and then another room, etc...
 * Try listing out all the easy problems and then bucketing them into larger categories such as clean the tile, wash the towels, clean the mirror, put away things on the vanity all
 * bucket up to "bathroom."
 * 5. Determine the sequence of events. You don't brush your teeth after going to work, so we need to define the logical flow of when everything has to be done.
 *
 * Implementation Step 1: Outlining you main function (calculator example)
 */
#include <iostream>
int main()
{
  // getUserInput();
  // getOperator();
  // getUserInput();
  // calculateResult();
  return 0;
}

// Implementation step 2: Implement each function
int getUserInput()
{
  std::cout << "Enter an integer: ";
  int input{};
  std::cin >> input;
  return input;
}

// Note: work in stages. Don't do everything in one shot. Test as you go and at the end.

/* Words of Wisdom
 * 1. Keep your programs simple to start. If you try to do something too complex at first, you'll get overwhelmed and off track.
 * 2. Add features over time
 * 3. Focus on one area at a time. Don't code everything at once and don't divide your attention. Get one working task before 6 broken ones.
 * 4. Test each piece of code as you go.
 * 5. Don't invest in perfecting early code. The first draft is rarely good and programs evolve over time. As you add stuff, you upgrade.
 * 6. Optimize for maintainability, not performance. Donald Knuth says that "premature optimization is the root of all evil." It is better
 * to have code that is simple and usable over top tier performance which frequently doesn't matter that much.
 */
