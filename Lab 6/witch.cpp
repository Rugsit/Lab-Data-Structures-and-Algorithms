#include <iostream>
#include <vector>
using namespace std;

int findNumber(vector<string>, string);
int main() {
  vector<string> nameStore; vector<string> numberStore;
  string name; string number;
  while (true) {
    cin >> name;
    if (name.at(0) == '-') break;
    cin >> number;
    nameStore.push_back(name); numberStore.push_back(number);
  }
  string targetName;
  while (cin >> targetName) {
    if (findNumber(nameStore, targetName) == -1) {
      cout << "Contact not found." << endl;
    } else {
      cout << numberStore.at(findNumber(nameStore, targetName)) << endl;
    }
  }
  return 0; 
}

int findNumber(vector<string> nameStore, string name) {
  for (int i = 0; i < nameStore.size(); i++) {
    if (nameStore.at(i) == name) {
      return i;
    }
  }
  return -1;
}