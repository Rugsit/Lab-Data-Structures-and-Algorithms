#include <iostream>
#include <vector>
using namespace std;

bool findWay = false;
vector<int> indexStart, indexStop;
vector<vector<int>> storeHavePass;
int path;
int mazeWidth, mazeHeight;
int stop;
void deepFirstSearch(vector<vector<int>>&, vector<int>);
bool findHavePass(vector<int>);
int main() {
  int start, eachMaze;
  cin >> mazeHeight >> mazeWidth;
  cin >> start >> stop;
  cin >> path;
  vector<int> subMaze(mazeWidth, 0);
  vector<vector<int>> maze(mazeHeight, subMaze);
  for (int i = 0; i < mazeHeight; i++) {
    for (int j = 0; j < mazeWidth; j++) {
      cin >> eachMaze;
      if (eachMaze == start) {
        indexStart.push_back(i);
        indexStart.push_back(j);
      } else if (eachMaze == stop) {
        indexStop.push_back(i);
        indexStop.push_back(j);
      }
      maze[i][j] = eachMaze; 
    }
  }
  deepFirstSearch(maze, indexStart);
  if (!findWay) cout << "Oh No! We're Trapped." << endl;
  else cout << "Yeah, There's The Way Out!" << endl;
}

void deepFirstSearch(vector<vector<int>> &maze, vector<int>indexCurrent) {
  if (indexCurrent.at(0) == indexStop.at(0) && indexCurrent.at(1) == indexStop.at(1)) {
    findWay = true;
    return;
  }
  if (findHavePass(indexCurrent)) {
    return;
  } 
  storeHavePass.push_back(indexCurrent);
  int currentRow = indexCurrent.at(0);
  int currentColumn = indexCurrent.at(1);
  if (currentRow - 1 >= 0 && (maze[currentRow - 1][currentColumn] == path || maze[currentRow - 1][currentColumn] == stop)) {
    vector<int> newCurrent;
    newCurrent.push_back(indexCurrent.at(0) - 1);
    newCurrent.push_back(indexCurrent.at(1));
    if (!findHavePass(newCurrent)) {
      deepFirstSearch(maze, newCurrent);
    }
  }
  if (currentRow + 1 < mazeHeight && (maze[currentRow + 1][currentColumn] == path || maze[currentRow + 1][currentColumn] == stop )) {
    vector<int> newCurrent;
    newCurrent.push_back(indexCurrent.at(0) + 1);
    newCurrent.push_back(indexCurrent.at(1));
    if (!findHavePass(newCurrent)) {
      deepFirstSearch(maze, newCurrent);
    }
  }
  if (currentColumn - 1 >= 0 && (maze[currentRow][currentColumn - 1] == path || maze[currentRow][currentColumn - 1] == stop )) {
    vector<int> newCurrent;
    newCurrent.push_back(indexCurrent.at(0));
    newCurrent.push_back(indexCurrent.at(1) - 1);
    if (!findHavePass(newCurrent)) {
      deepFirstSearch(maze, newCurrent);
    }
  }
  if (currentColumn + 1 < mazeWidth && (maze[currentRow][currentColumn + 1] == path || maze[currentRow][currentColumn + 1] == stop)) {
    vector<int> newCurrent;
    newCurrent.push_back(indexCurrent.at(0));
    newCurrent.push_back(indexCurrent.at(1) + 1);
    if (!findHavePass(newCurrent)) {
      deepFirstSearch(maze, newCurrent);
    }
  }
  return;
}

bool findHavePass(vector<int> indexCurrent) {
  for (int i = 0; i < storeHavePass.size(); i++) {
    if (storeHavePass[i][0] == indexCurrent.at(0) && storeHavePass[i][1] == indexCurrent.at(1)) {
      return true;
    }
  }
  return false;
}