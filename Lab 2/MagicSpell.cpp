#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct
{
  short a = 0;
  short b = 0;
  short c = 0;
} Factor_formula;

typedef struct
{
  int x;
  int y;
} Points;

typedef struct
{
  short two = 0;
  short one = 0;
} Y;

int main()
{
  short number_points;
  bool is_minus = false, is_y = false, is_x = false, is_exponent = false, is_equal = false;
  string formula, number_in_formula = "", number_exponent = "";
  cin >> number_points;
  vector<Points> points;
  Y y;
  Factor_formula factor;
  for (int i = 0; i < number_points; i++)
  {
    int x, y;
    cin >> x >> y;
    Points point = {x, y};
    points.push_back(point);
  }
  cin >> formula;
  for (int i = 0; i < formula.size(); i++)
  {
    if (isdigit(formula[i]) && !is_exponent)
      number_in_formula += formula[i];
    else if (isdigit(formula[i]) && is_exponent)
      number_exponent += formula[i];
    else if (formula[i] == 'y')
      is_y = true;
    else if (formula[i] == 'x')
      is_x = true;
    else if (formula[i] == '^')
    {
      is_exponent = true;
    }
      if (formula[i] == '-' || formula[i] == '+' || formula[i] == '=' || i == formula.size() - 1)
      {
        if (is_equal) is_minus = !is_minus;
        if (is_minus && number_in_formula != "")
          number_in_formula = "-" + number_in_formula;
        else if (is_minus && number_in_formula == "" && (is_x || is_y))
        {
          number_in_formula = "-1";
        }
        if (is_y)
        {
          if (number_exponent == "")
            y.one += number_in_formula == "" ? 1 : stoi(number_in_formula);
          else if (number_exponent == "2")
            y.two += number_in_formula == "" ? 1 : stoi(number_in_formula);
        }
        else if (is_x)
        {
          if (number_exponent == "")
            factor.b += number_in_formula == "" ? 1 : stoi(number_in_formula);
          else if (number_exponent == "2")
            factor.a += number_in_formula == "" ? 1 : stoi(number_in_formula);
        }
        else if (!is_x && !is_y)
        {
          factor.c += number_in_formula == "" ? 0 : stoi(number_in_formula);
        }

        if (formula[i] == '=') is_equal = true;
        is_minus = formula[i] == '-' ? true : false;
        is_y = false;
        is_x = false;
        is_exponent = false;
        number_exponent = "";
        number_in_formula = "";
      }
  }
  short temp = factor.c;
  for (int i = 0; i < points.size(); i++)
  {
    factor.c = temp;
    factor.c += (y.two * pow(points[i].y, 2) + y.one * pow(points[i].y, 1));
    int result = (pow(points[i].x, 2) * factor.a) + (points[i].x * factor.b) + factor.c;
    if (result == 0)
      cout << "(" << points[i].x << ", " << points[i].y << ")" << " TRUE" << endl;
    else
      cout << "(" << points[i].x << ", " << points[i].y << ")" << " FALSE" << endl;
  }

  // cout << y.one << " " << y.two << endl;
}
