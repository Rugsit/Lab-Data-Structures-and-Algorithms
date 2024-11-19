#include <iostream>
#include <vector>
using namespace std;

int countX(string);
int main() {
  while (true) {
    int number; cin >> number;
    string buffer;
    getline(cin, buffer);
    if (number == 0) break;
    vector<int> countCharLine; int max = 0;
    for (int i = 0; i < number; i++) {
      string line; getline(cin, line);
      int x = countX(line); 
      countCharLine.push_back(x);
      if (x >= max) max = x;
    }
    int sum = 0;
    for (int i = 0; i < countCharLine.size(); i++) {
      sum += max - countCharLine.at(i);
    }
    cout << sum << endl;
  }
  return 0;
}

int countX(string line) {
  int sum = 0;
  for (int i = 0; i < line.size(); i++) {
    if (line.at(i) == 'X') sum++;
  }
  return sum;
}