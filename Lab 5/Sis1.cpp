#include <iostream>
using namespace std;

int findN(int);
int findSumN(int);
int main() {
  int number;
  while (cin >> number) {
    cout << findSumN(number) << endl;
  }
}

int findN(int number) {
  if (number == 1) return 1;
  return findN(number - 1) + number;
}

int findSumN(int number) {
  if (number == 1) return 1;
  return findN(number) + findSumN(number -1); 
}