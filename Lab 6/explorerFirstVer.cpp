#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int number; int targetNumber;
  string numberLine; string eachNumber;
  getline(cin, numberLine);
  stringstream s(numberLine);
  vector<int> numberStore; vector<int> amountSearch;
  while (s >> eachNumber) {
    numberStore.push_back(stoi(eachNumber));
  }
  cin >> targetNumber;
  for (int i = 0; i < numberStore.size(); i++) {
    if (numberStore.at(i) == targetNumber) {
      amountSearch.push_back(i + 1);
      break;
    }
  }
  if (amountSearch.size() == 0) {
    cout << "Not Found" << endl; 
    return 0;
  } 
  for (int i = numberStore.size() - 1, j = 0; i >= 0; i--, j++) {
    if (numberStore.at(i) == targetNumber) {
      amountSearch.push_back(j + 1);
      break;
    } 
  }
  sort(numberStore.begin(), numberStore.end());
  int count = 0; int low = 0; int high = numberStore.size() - 1; int middle;
  bool found = false;
  while (count < numberStore.size()) {
    count++;
    middle = (high + low) / 2; 
    if (numberStore.at(middle) == targetNumber) {
      found = true;
      break;
    } 
    if (targetNumber > numberStore.at(middle)) {
      low = middle + 1;
    } else {
      high = middle - 1;
    } 
  }
  if (found) amountSearch.push_back(count);
  int min = amountSearch.at(0);
  for (int num : amountSearch) {
    if (num <= min) min = num;
  }
  // cout << amountSearch.at(0) << " " << amountSearch.at(1) << " " << amountSearch.at(2) << endl;
  for (int i = 0; i < amountSearch.size(); i++) {
    if (amountSearch.at(i) == min) {
      if (i == 0) cout << "Linear ";
      else if (i == 1) cout << "Sentinel ";
      else if (i == 2) cout << "Binary ";
    }
  }
  cout << endl;
  cout << min << endl;
}