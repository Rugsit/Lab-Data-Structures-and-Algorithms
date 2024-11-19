#include <iostream>
#include <vector>
using namespace std;

int main() {
  int person, exam, each_score, total_score = 0;
  cin >> person >> exam;
  vector<int> answer;
  for (int i = 0; i < exam; i++) {
    cin >> each_score;
    answer.push_back(each_score);
  }
  for (int i = 0; i < person; i++) {
    for (int j = 0; j < exam; j++) {
      cin >> each_score;  
      if (each_score == answer.at(j)) total_score++;
    }
    cout << total_score << " ";
    total_score = 0;
  }
  return 0;
}