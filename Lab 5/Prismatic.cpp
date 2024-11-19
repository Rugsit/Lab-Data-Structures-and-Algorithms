#include <iostream>
#include <vector>
using namespace std;

vector<int> prismaticCom(double, vector<int>, string);
int main() {
  vector<int> result = {0, 0, 0, 0};
  double mass; cin >> mass;
  result = prismaticCom(mass, result, "white");
  for (int i = 0; i < result.size(); i++) {
    cout << result.at(i) << " ";
  }
}

vector<int> prismaticCom(double mass, vector<int> sumStatus, string color) {
  if (color == "white") {
    if (mass <= 1) return sumStatus;
    // cout << "enter white " << mass << endl;
    return prismaticCom(mass - 1, sumStatus, "green");
  }
  else if (color == "green") {
    // cout << "enter green " << mass << endl;
    sumStatus[0] += 1;
    if (mass <= 1) return sumStatus;
    if (mass <= 20) return prismaticCom(mass - 1, sumStatus, "yellow");
    else if (mass <= 50) return prismaticCom(mass * 0.8, sumStatus, "blue");
    else if (mass > 50) return prismaticCom(mass * 0.5, sumStatus, "purple");
  }
  else if (color == "purple") {
    // cout << "enter purple " << mass << endl;
    if (mass >= 0)sumStatus[1] += 1;
    if (mass <= 1) return sumStatus;
    return prismaticCom(mass * 0.3, prismaticCom(mass * 0.7, sumStatus, "blue"), "green");
  }
  else if (color == "blue") {
    // cout << "enter blue " << mass << endl;
    sumStatus[2] += 1;
    if (mass <= 1) return sumStatus;
    if (mass >= 100) return prismaticCom(mass * 0.9, sumStatus, "yellow");
    else if (mass < 100) return prismaticCom(mass - 10, sumStatus, "purple");
  }
  else if (color == "yellow") {
    // cout << "enter yellow " << mass << endl;
    sumStatus[3] += 1;
    if (mass <= 1) return sumStatus;
    return prismaticCom(mass * 0.25, prismaticCom(mass * 0.15, prismaticCom(mass * 0.1, sumStatus, "green"), "purple"), "blue");
  }
}
