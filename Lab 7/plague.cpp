#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool havePassed(int, vector<int> &);
void breadthFirstSearch(int, vector<vector<int>> &, int &,vector<int> &);
void printOutput(int, int);
void BFSFindComponent(int, vector<vector<int>> &, vector<int> &);
void clearHavePass(vector<int>&);
vector<int> storeCompleteCount;
vector<int> eachComponent;
vector<vector<int>> component;
int main() {
  int count = 0;
  int amountPeople;
  int timeInfected;
  cin >> amountPeople;
  vector<int>havePass(amountPeople, 0);
  vector<int> eachGraphPeople;
  vector<vector<int>> graphPeople(amountPeople,eachGraphPeople); 
  cin >> timeInfected;
  while(true) {
    int number1, number2; 
    cin >> number1;
    if (number1 == -1) break;
    cin >> number2;
    graphPeople.at(number1).push_back(number2);
    graphPeople.at(number2).push_back(number1);
  }
  for (int i = 0; i < graphPeople.size(); i++) {
    if (havePass.at(i) == 1) continue;
    havePass.at(i) = 1;
    eachComponent.push_back(i);
    BFSFindComponent(i, graphPeople, havePass);
    component.push_back(eachComponent);
    eachComponent.clear();
  }
  vector<int> storeMin;
  clearHavePass(havePass);
  for (int i = 0; i < component.size(); i++) {
    for (int j = 0; j < component.at(i).size(); j++) {
      breadthFirstSearch(component[i][j], graphPeople, count, havePass);
      clearHavePass(havePass);
      storeCompleteCount.push_back(--count);
      count = 0;
    }
    int min = storeCompleteCount.at(0);
    for (int i = 0; i < storeCompleteCount.size(); i++) {
      if (storeCompleteCount.at(i) < min) {
        min = storeCompleteCount.at(i);
      }
    }
    storeCompleteCount.clear();
    storeMin.push_back(min);
  }
  int maxMin = storeMin.at(0);
  for (int i = 0; i < storeMin.size(); i++) {
    if (storeMin.at(i) > maxMin) maxMin = storeMin.at(i);
  }
  printOutput(timeInfected, maxMin);
}

void breadthFirstSearch(int startNode, vector<vector<int>> &graphPeople, int &count, vector<int> &havePass){
  queue<int> adjacentNode;
  havePass.at(startNode) = 1;
  adjacentNode.push(startNode);
  while (!adjacentNode.empty()) {
    int size = adjacentNode.size();
    count++;
    for (int j = 0; j < size; j++) {
      int current = adjacentNode.front();
      adjacentNode.pop();
      for (int adj : graphPeople[current]) {
        if (havePass.at(adj) == 0) {
          havePass.at(adj) = 1;
          adjacentNode.push(adj);
        }
      }
    }
  }
}


void BFSFindComponent(int startNode, vector<vector<int>> &graphPeople, vector<int> &havePass){
  queue<int> adjacentNode;
  havePass.at(startNode) = 1;
  eachComponent.push_back(startNode);
  adjacentNode.push(startNode);
  while (!adjacentNode.empty()) {
      int current = adjacentNode.front();
      adjacentNode.pop();
      
      for (int adj : graphPeople[current]) {
        if (havePass.at(adj) == 0) {
          havePass.at(adj) = 1;
          eachComponent.push_back(adj);
          adjacentNode.push(adj);
        }
      }
    }
}

void printOutput(int timeInfected, int count) {
  if (count == 0) {
    cout << "0 minutes" << endl;
    return;
  }
  int totalTime = timeInfected * count;
  vector<int>storeTime(5, 0);
  storeTime.at(0) = totalTime / 518400;
  totalTime -= storeTime.at(0) * 518400;
  storeTime.at(1) = totalTime / 43200;
  totalTime -= storeTime.at(1) * 43200;
  storeTime.at(2) = totalTime / 1440;
  totalTime -= storeTime.at(2) * 1440;
  storeTime.at(3) = totalTime / 60;
  totalTime -= storeTime.at(3) * 60;
  storeTime.at(4) = totalTime;

  for (int i = 0; i < storeTime.size(); i++) {
    if (storeTime.at(i) == 0) continue;
    else {
      if (i == 0) {
        if (storeTime.at(i) > 1) {
          cout << storeTime.at(i) << " years ";
        } else {
          cout << storeTime.at(i) << " year ";
        } 
      } else if (i == 1) {
        if (storeTime.at(i) > 1) {
          cout << storeTime.at(i) << " months ";
        } else {
          cout << storeTime.at(i) << " month ";
        }
      } else if (i == 2) {
        if (storeTime.at(i) > 1) {
          cout << storeTime.at(i) << " days ";
        } else {
          cout << storeTime.at(i) << " day ";
        }
      } else if (i == 3) {
        if (storeTime.at(i) > 1) {
          cout << storeTime.at(i) << " hours ";
        } else {
          cout << storeTime.at(i) << " hour ";
        }
      } else if (i == 4) {
        if (storeTime.at(i) > 1) {
          cout << storeTime.at(i) << " minutes ";
        } else {
          cout << storeTime.at(i) << " minute ";
        }
      }
    }
  }
  cout << endl;
}

void clearHavePass(vector<int> &havePass) {
  for (int i = 0; i < havePass.size(); i++) {
    havePass.at(i) = 0;
  }
}