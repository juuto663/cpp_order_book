#include <iostream>

double RATE_OF_GRAVITY = 9.8;

double calculate_ball_height(double starting_height, double seconds)
{
  double distance_travelled{RATE_OF_GRAVITY * ((seconds * seconds) / 2)};
  return starting_height - distance_travelled;
}

double get_starting_height()
{
  std::cout << "Enter a starting tower height: ";
  double x{};
  std::cin >> x;
  if (x <= 0)
  {
    std::cout << "Enter a non-negative/non-zero starting height. Exiting...\n";
    std::exit(1);
  }
  return x;
}

int main()
{
  double tower_height{get_starting_height()};
  double ball_height = tower_height;
  int seconds_elapsed{1};

  while (ball_height > 0)
  {
    ball_height = calculate_ball_height(tower_height, seconds_elapsed);
    if (ball_height <= 0)
    {
      std::cout << "After " << seconds_elapsed << " second(s), the ball is now on the ground\n";
      return 0;
    }

    std::cout << "After " << seconds_elapsed << " second(s), the ball is now at " << ball_height << " meters\n";
    seconds_elapsed++;
  }

  return 0;
}
