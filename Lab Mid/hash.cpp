#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int hashNumber(int);
int main() {
  int numHash;
  int numInput;
  cin >> numInput;
  numHash = hashNumber(numInput);
  vector<int> allNum(numHash, -1);
  for (int i = 0; i < numInput; i++) {
    int number; cin >> number;
    if (allNum.at(number % numHash) != -1) {
      int index = number % numHash;
      while (true) {
        if (allNum.at(index) == -1) {
          allNum.at(index) = number;
          break;
        } 
        index++;
        if (index == allNum.size()) index = 0;
      }
    } else {
      allNum.at(number % numHash) = number;
    }
  }
  for (int i = 0; i < numHash; i++) {
    if (allNum.at(i) == -1) cout << "-" << " ";
    else cout << allNum.at(i) << " ";
  }
}

int hashNumber(int number) {
  while(true) {
    bool check = true;
    if (number % 2 == 0 && number != 2) {
      number++;
      continue;
    }
    for (int i = 2; i < sqrt(number); i++) {
      if (number % i == 0) check = false;
    }
    if (check) return number;
    number++;
  }

}