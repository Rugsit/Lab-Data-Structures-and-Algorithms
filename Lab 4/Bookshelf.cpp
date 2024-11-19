#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
  short numberOfStack, outNumber, eachStackNumber, totalOut = 0;
  stack<vector<string>> stackOfBook;
  vector<short> amountOfEachStack;
  cin >> numberOfStack >> outNumber;
  for (int i = 0; i < numberOfStack; i++) {
    cin >> eachStackNumber;
    string bookName;
    vector<string> nameOfBook;
    for (int j = 0; j < eachStackNumber; j++) {
      cin >> bookName;
      nameOfBook.push_back(bookName);
    }
    stackOfBook.push(nameOfBook);
    amountOfEachStack.insert(amountOfEachStack.begin(), nameOfBook.size());
  }
  for (int i = 0; i < outNumber; i++) {
    if (i >= stackOfBook.size()) break;
    totalOut += amountOfEachStack.at(i);
  }
  cout << totalOut << endl;

  for (int i = 0; i < outNumber; i++) {
    if (stackOfBook.empty()) break;
    vector<string> targetStack = stackOfBook.top();
    for (int j = 0; j < targetStack.size(); j++) {
      cout << targetStack.at(j) << " ";
    }
    cout << endl;
    stackOfBook.pop();
  }
}