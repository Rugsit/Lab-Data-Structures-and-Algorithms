#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int sumAllInArea(vector<vector<int>>, int, int, int, int);
int findMaxValueSquare(vector<int>, vector<vector<int>>, int, int, int);

int main()
{
  int total_all = 0;
  int width, height, max_magic, magic_per_cell, each_cell;
  cin >> width >> height;
  cin >> max_magic >> magic_per_cell;
  int magic_area = max_magic / magic_per_cell;
  int bound = sqrt(magic_area);
  vector<vector<int>> area;

  // input
  for (int i = 0; i < height; i++)
  {
    vector<int> each_row;
    for (int j = 0; j < width; j++)
    {
      cin >> each_cell;
      each_row.push_back(each_cell);
    }
    area.push_back(each_row);
  }

  // find possible square
  while (magic_area >= 1)
  {
    vector<int> square;
    if (magic_area <= 0)
    {
      cout << 0;
      return 0;
    }
    for (int i = 1; i < bound + 1; i += 1)
    {
      if (magic_area % i == 0 && (magic_area / i <= width || magic_area / i <= height))
      {
        square.push_back(i);
      }
    }
    if (!square.empty())
    {
      int check = findMaxValueSquare(square, area, magic_area, height, width);
      if (total_all < check)
      {
        total_all = check;
      }
    }
    magic_area--;
  }
  cout << total_all;
  return 0;
}

int findMaxValueSquare(vector<int> square, vector<vector<int>> area, int magic_area, int height, int width)
{
  int max_total = INT_MIN;
  for (int i = 0; i < (int)square.size(); i++)
  {
    int first = sumAllInArea(area, square.at(i), magic_area / square.at(i), height, width);
    int second = sumAllInArea(area, magic_area / square.at(i), square.at(i), height, width);
    int check = first >= second ? first : second;
    if (max_total <= check)
    {
      max_total = check;
    }
  }
  return max_total;
}

int sumAllInArea(vector<vector<int>> area, int square_width, int square_height, int height, int width)
{
  if (square_height > height || square_width > width)
    return INT_MIN;
  int max_total = INT_MIN;
  int total = 0;
  int start_x = 0, start_y = 0;
  while (true)
  {
    int i, j;
    for (i = start_x; i - start_x < square_width; i++)
    {
      for (j = start_y; j - start_y < square_height; j++)
      {
        total += area[j][i];
      }
    }
    if (total > max_total)
      max_total = total;
    total = 0;
    start_x++;
    if (start_x + (square_width - 1) > width - 1)
    {
      start_x = 0;
      start_y++;
    }
    if (start_y + (square_height - 1) > height - 1)
    {
      return max_total;
    }
  }
}