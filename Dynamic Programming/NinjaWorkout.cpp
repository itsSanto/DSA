#include <cstdlib>
#include <iostream>
#include <vector>

/*
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform
any one of these three activities. (Running, Fighting Practice or Learning New
Moves). Each activity has some merit points on each day. As Ninja has to improve
all his skills, he can’t do the same activity in two consecutive days. Can you
help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to
each day and activity. Your task is to calculate the maximum number of merit
points that Ninja can earn.

For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be
11 as 5 + 3 + 3.
*/

int f(int day, std::vector<std::vector<int>> &points, int lastWorkout) {
  int max = 0;
  if (day == 0) {
    for (int i = 0; i < points[day].size(); ++i) {
      if (lastWorkout != i) {
        max = std::max(max, points[day][i]);
      }
    }
    return max;
  }

  for (int i = 0; i < points[day].size(); ++i) {
    if (i != lastWorkout) {
      max = std::max(max, points[day][i] + f(day - 1, points, i));
    }
  }
  return max;
}

int ninjaTraining(int n, std::vector<std::vector<int>> &points) {
  return f(n - 1, points, points[n - 1].size());
}
int main() {
  std::vector<std::vector<int>> points{{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
  std::cout << ninjaTraining(points.size(), points);

  return 0;
}