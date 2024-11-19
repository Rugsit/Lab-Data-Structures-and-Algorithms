#include <iostream>
#include <vector>
using namespace std;

bool findGemBinary(int[], int, int);
int main() {
  int totalGem; int firstGem; int lastGem;
  int eachGem;
  cin >> totalGem;
  int gemStore[totalGem];
  int size = sizeof(gemStore) / sizeof(int);
  for (int i = 0; i < totalGem; i++) {
    cin >> eachGem;
    if (i == 0) {
      firstGem = eachGem;
      lastGem = eachGem;
    } 
    if (i == totalGem - 1) lastGem = eachGem;
    gemStore[i] = eachGem; 
  }
  for (int i = firstGem; i < lastGem + 1; i++) {
    if (!findGemBinary(gemStore, i, size)) {
      cout << i << " ";
    }
  }
  cout << endl;
  return 0;
}

bool findGemBinary(int gemStore[], int number, int size) {
  int high = size - 1, low = 0, middle;
  for (int i = 0; i < size; i++) {
    middle = (high + low) / 2;
    if (number == gemStore[middle]) {
      return true;
    }
    if (number > gemStore[middle]) {
      low = middle + 1;
    } else {
      high = middle - 1;
    }
  }
  return false;
}