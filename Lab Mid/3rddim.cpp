#include <iostream>
using namespace std;

int main() {
  string dataType; long width;
  long startArray, X, Y, Z, x, y, z;
  cin >> dataType;
  cin >> startArray;
  cin >> X >> Y >> Z;
  cin >> x >> y >> z;
  if (dataType == "char") {
    width = 1;
  } else if (dataType == "short") {
    width = 2;
  } else if (dataType == "int") {
    width = 4;
  } else if (dataType == "long") {
    width = 8;
  } else if (dataType == "double") {
    width = 8;
  } else if (dataType == "float") {
    width = 4;
  } else {
    cout << "Invalid Type" << endl;
    return 0;
  }

  if (X <= 0 || Y <= 0 || Z <= 0 || X > 500 || Y > 500 || Z > 500) {
    cout << "Invalid Argument" << endl;
    return 0;
  }
  if (x >= X || y >= Y || z >= Z || x < 0 || y < 0 || z < 0) {
    cout << "Segmentation Fault" << endl;
    return 0;
  }

  long addr = startArray + width * ((x * Y * Z) + (y * Z) + z);
  // if (addr >= startArray + (X * Y * Z * width)) {
  //   cout << "Segmentation Fault" << endl;
  //   return 0;
  // }
  long allByte =  X * Y * Z * width; 
  cout << allByte << " B, Accessing Address  " << addr << endl;
  return 0;
}