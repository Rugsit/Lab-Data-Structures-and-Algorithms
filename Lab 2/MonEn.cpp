#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
  int number_input;
  string name_animal, max_name, min_name;
  int hp, atk, def, max_eval = INT_MIN, min_eval = INT_MAX;
  cin >> number_input;
  for (int i = 0; i < number_input; i++)
  {
    cin >> name_animal;
    cin >> hp >> atk >> def;
    int eval = hp + (atk * def);
    if (eval > max_eval)
    {
      max_eval = eval;
      max_name = name_animal;
    }
    if (eval < min_eval)
    {
      min_eval = eval;
      min_name = name_animal;
    }
    cout << name_animal << ": (HP " << hp << " | " << atk << "/" << def << ") - EVAL " << eval << endl;
  }
  cout << "The weakest monster is " << min_name << " with evaluation of " << min_eval << endl;
  cout << "The strongest monster is " << max_name << " with evaluation of " << max_eval << endl;
}