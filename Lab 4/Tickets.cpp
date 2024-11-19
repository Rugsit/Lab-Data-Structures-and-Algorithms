#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printAllTickets(vector<string>, vector<string>);

int main() {
  char command;
  string line;
  getline(cin, line);
  stringstream ss(line);
  string word;
  vector<string> ticketsBottle;
  vector<string> ticketsLine; 
  while (ss >> word) {
    ticketsBottle.push_back(word);
  }
  while (true) {
    cin >> command;
    command = tolower(command);
    if (command == 'q') break;
    switch (command) {
      case 'e':
        if (ticketsBottle.empty()) break;
        ticketsLine.push_back(ticketsBottle.back());
        ticketsBottle.pop_back();
        break;
      case 'd':
        if (ticketsLine.empty()) break;
        ticketsBottle.push_back(ticketsLine.front());
        ticketsLine.erase(ticketsLine.begin());
        break;
      case 'p':
        printAllTickets(ticketsBottle, ticketsLine);
        break;
      default:
        cout << "Input Error";
    }
    if (command != 'e' && command != 'd' && command != 'p') break;
  }
  
}

void printAllTickets(vector<string> ticketsBottle, vector<string> ticketsLine) {
  vector<string> newBottle = ticketsBottle;
  vector<string> newLine = ticketsLine;
  bool haveTicketLine = false, haveTicketBottle = false;
  cout << "Remaining Tickets In The Line: ";
  for (short i = 0; i < newLine.size(); i++) {
    cout << newLine.at(i) << " ";
    haveTicketLine = true;
  }
  if (!haveTicketLine) cout << "Line Is Empty";
  cout << endl;
  cout << "Remaining Tickets In The Bottle: ";
  for (short i = 0; i < newBottle.size(); i++) {
    cout << newBottle.at(i) << " ";
    haveTicketBottle = true;
  }
  if (!haveTicketBottle) cout << "Bottle Is Empty";
  cout << endl;
  cout << "====================" << endl;
}