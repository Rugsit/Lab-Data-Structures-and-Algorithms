#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void combination(vector<int>, vector<int> , int , vector<int>); 
int amountBalls;
int maxWeight;
int targetPoint; int countWin = 0; int allPlay = 0;
int main() {
  cin >> amountBalls; cin >> maxWeight; cin >> targetPoint;
  vector<int> vectorWeight; vector<int> vectorPoint;
  for (int i = 0; i < amountBalls; i++) {
    int weight; cin >> weight;
    vectorWeight.push_back(weight);
  }
  for (int i = 0; i < amountBalls; i++) {
    int point; cin >> point;
    vectorPoint.push_back(point);
  }
  vector<int>current;
  combination(vectorPoint, vectorWeight, 0, current);
  cout << fixed;
  cout << setprecision(5);
  double result = countWin / (allPlay * 1.0);
  if (countWin == allPlay - 1) result = 1;
  cout << result;
}

void combination(vector<int> vectorPoint, vector<int> vectorWeight, int start, vector<int> current) {
  if (start == vectorPoint.size()) {
    allPlay++;
    int weight = 0; int point = 0;
    for (int i = 0; i < current.size(); i++) {
      weight += vectorWeight.at(current.at(i)); 
      point += vectorPoint.at(current.at(i));
    }
    if (point >= targetPoint && weight <= maxWeight && current.size() > 0) {
      countWin++;
      for (int i = 0; i < current.size(); i++) {
        cout << current.at(i) << " ";
      }
      cout << endl;
    }
    return;
  }
  current.push_back(start);
  combination(vectorPoint, vectorWeight, start + 1, current); 
  current.pop_back();
  combination(vectorPoint, vectorWeight, start + 1, current); 
}