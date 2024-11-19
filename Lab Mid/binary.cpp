#include <iostream>
#include <vector>
using namespace std;

vector<int>convertUnsigned(int);
vector<int>oneCom(vector<int>, int);
vector<int>convertUnsigned(double);
int main() {
  double number; cin >> number;
  int numberInt = int(number);
  vector<int> vectorBinary;
  if (numberInt == number) {
    vectorBinary = convertUnsigned(numberInt);
    if (numberInt < 0) {
      cout << "Unsigned: Underflow" << endl;
    } else {
      cout << "Unsigned: ";
      for (int i = 0; i < vectorBinary.size(); i++) {
        cout << vectorBinary.at(i); 
      }
    cout << endl;
    }
    cout << "Signed Magnitude: ";
    for (int i = 0; i < vectorBinary.size(); i++) {
      if (numberInt < 0 && i == 0) {
        cout << "1 "; continue;
      } else if (numberInt >= 0 && i == 0){
        cout << "0 "; continue;
      }
      cout << vectorBinary.at(i); 
    }
    cout << endl;
    cout << "1's Complement: ";
    vector<int> vector1Com = oneCom(vectorBinary, numberInt);
    if (numberInt < 0) {
      for (int i = 0; i < vector1Com.size(); i++) cout << vector1Com.at(i);
    } else {
      for (int i = 0; i < vectorBinary.size(); i++) cout << vectorBinary.at(i);
    }
    cout << endl;
    cout << "2's Complement: ";
    vector<int> vector2Com = vector1Com;
    if (numberInt < 0) {
      for (int i = vector2Com.size() - 1; i >= 0; i--) {
        if (vector2Com.at(i) == 0) {
          vector2Com.at(i) = 1; break;
        }
        vector2Com.at(i) = 0;
      }
      for (int i = 0; i < vector2Com.size(); i++) {
        cout << vector2Com.at(i);
      }
    } else {
      for (int i = 0; i < vectorBinary.size(); i++) {
        cout << vectorBinary.at(i);
      }
    }
    cout << endl;
    cout << "IEEE 754: ";
    if (numberInt < 0) {
      cout << "1 ";
    } else {
      cout << "0 ";
    }
    int firstOne;
    for (int i = 0; i < vectorBinary.size(); i++) {
      if (vectorBinary.at(i) == 1) {
        firstOne = i + 1; break;
      }
    }
    vector<int> vectorExponent = convertUnsigned(8 - firstOne + 127);
    for (int i = 0; i < vectorExponent.size(); i++) {
      cout << vectorExponent.at(i);
    }
    cout << " ";
    for (int i = 0; i < 23; i++) {
      if (firstOne >= vectorBinary.size()) cout << "0";
      else cout << vectorBinary.at(firstOne++);
    }
  } else {
    vectorBinary = convertUnsigned(numberInt);
    cout << "IEEE 754: ";
    if (numberInt < 0) {
      cout << "1 ";
    } else {
      cout << "0 ";
    }
    int firstOne;
    for (int i = 0; i < vectorBinary.size(); i++) {
      if (vectorBinary.at(i) == 1) {
        firstOne = i + 1; break;
      }
    }
    vector<int> vectorExponent = convertUnsigned(8 - firstOne + 127);
    for (int i = 0; i < vectorExponent.size(); i++) {
      cout << vectorExponent.at(i);
    }
    cout << " ";
    vector<int> mantisa = convertUnsigned(number);
    for (int i = 1; i < mantisa.size(); i++) {
      cout << mantisa.at(i);
    }
  }
  return 0;
}

vector<int> convertUnsigned(double number) {
  if (number < 0) number *= -1;
  int numberInt = int(number);
  vector<int> stackBinary;
  while (numberInt != 0) { 
    stackBinary.insert(stackBinary.begin(),numberInt % 2);
    numberInt /= 2;
  }
  double faction = number - int(number);
  while(stackBinary.size() != 24) {
    faction *= 2;
    if (faction >= 1) {
      stackBinary.push_back(1); faction -= 1;
    } else {
      stackBinary.push_back(0);
    }
  }
  return stackBinary;
}

vector<int> convertUnsigned(int number) {
  if (number < 0) number *= -1;
  vector<int> stackBinary;
  while (number != 0) { 
    stackBinary.insert(stackBinary.begin(),number % 2);
    number /= 2;
  }
  while(stackBinary.size() != 8) {
    stackBinary.insert(stackBinary.begin(), 0);
  }
  return stackBinary;
}

vector<int> oneCom(vector<int> vectorBinary, int numberInt) {
  if (numberInt < 0) {
    for (int i = 0; i < vectorBinary.size(); i++) {
     if (vectorBinary.at(i) == 1) vectorBinary.at(i) = 0;
     else vectorBinary.at(i) = 1;
    }
  }
  return vectorBinary;
}