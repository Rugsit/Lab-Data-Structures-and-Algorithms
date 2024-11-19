  #include <iostream>
  #include <vector>
  #include <stack>
  #include<bits/stdc++.h>
  using namespace std;

  int main() {
    stack<char> storeBac;
    bool checkBalance = true;
    int i = 0;
    string line;
    vector<string> postFix;
    stack<char> opeStack;
    getline(cin, line);
    while (true) {
      if (i >= line.size()) break;
      char character = line.at(i);
      if (character == ')') {
        if (storeBac.empty() || storeBac.top() != '(') {
          checkBalance = false;
        } else if (!storeBac.empty() && storeBac.top() == '(') {
          storeBac.pop();
        }
      }
      else if (character == '(') storeBac.push(character);

      if (i == 0 && (character == '+' || character == '-')) {
        line.insert(i, "0"); i++;
        continue;
      } else if (i == 0 && (character == '*' || character == '/')) {
        line.insert(i, "1"); i++;
        continue;
      } else if (i == line.size()-1 && (character == '+' || character == '-')) {
        line.push_back('0'); i++;
        continue;
      } else if (i == line.size()-1 && (character == '*' || character == '/')) {
        line.push_back('1'); i++;
        continue;
      }

      switch (character) {
        case '+':
        case '-':
          if (i > 0 && line.at(i - 1) != ')' && !isdigit(line.at(i - 1))) {
            line.insert(i, "0");
          } else if (i < line.size() - 1 && line.at(i + 1) != '(' && !isdigit(line.at(i + 1))) {
            line.insert(i+1, "0");
          } 
          break;
        case '*':
        case '/':
          if (i > 0 && line.at(i - 1) != ')' && !isdigit(line.at(i - 1))) {
            line.insert(i, "1");
          } else if (i < line.size() - 1 && line.at(i + 1) != '(' && !isdigit(line.at(i + 1))) {
            line.insert(i+1, "1");
          }
          break;
      }
      i++;
    }
    if (!storeBac.empty()) checkBalance = false;
    if (!checkBalance) {
      cout << "Error: Unbalanced parenthesis";
      return 0;
    }

    // create postfix from line
    string number = "";
    bool isPushinStack = false;
    for (int i = 0; i < line.size(); i++) {
      char charactor = line.at(i);
      if (charactor == '+' || charactor == '-' ||charactor == '*' ||charactor == '/'
      || charactor == '(' || charactor == ')') {
        if (number != "") postFix.push_back(number);
        number = "";
        if ((opeStack.empty() || opeStack.top() == '(') && charactor != ')') {
          opeStack.push(charactor);
          continue;
        }
        
        if (charactor == ')') {
          while (!opeStack.empty() && opeStack.top() != '(') {
            postFix.push_back(string(1, opeStack.top()));
            opeStack.pop();
          }
          if (!opeStack.empty()) opeStack.pop();
          continue;
        }
        if (opeStack.empty()) continue;
        char newOpe = charactor, topOpe = opeStack.top(); isPushinStack = false;
        while(true) {
            if (((topOpe == '+' || topOpe == '-') && 
              (newOpe == '*' || newOpe == '/')) || newOpe == '(') {
                opeStack.push(newOpe);
                isPushinStack = true;
                break;
            } else {
              postFix.push_back(string(1, topOpe));
              if (!opeStack.empty()) opeStack.pop();
              if (opeStack.empty() || opeStack.top() == '(') break;
              topOpe = opeStack.top();
            }
        }
        if (!isPushinStack) opeStack.push(newOpe);
        continue;
      }
      number += charactor;
    }
    if (number != "") postFix.push_back(number);
    while (!opeStack.empty()) {
      if (opeStack.top() == '(' || opeStack.top() == ')') {
        opeStack.pop(); continue;
      }
      postFix.push_back(string(1, opeStack.top()));
      if (!opeStack.empty()) opeStack.pop();
    }
    // for (int i = 0; i < postFix.size(); i++) {
    //   cout << postFix.at(i) << " ";
    // }

    stack<double> calculateStack;
    // calculate result from postfix
    double right, left;
      for (int i = 0; i < postFix.size(); i++) {
      if (postFix.at(i) == "+") {
        right = calculateStack.top(); calculateStack.pop();
        left= calculateStack.top(); calculateStack.pop();
        calculateStack.push(left + right);
      } else if (postFix.at(i) == "-") {
        right = calculateStack.top(); calculateStack.pop();
        left= calculateStack.top(); calculateStack.pop();
        calculateStack.push(left - right);
      } else if (postFix.at(i) == "*") {
        right = calculateStack.top(); calculateStack.pop();
        left= calculateStack.top(); calculateStack.pop();
        calculateStack.push(left * right);
      } else if (postFix.at(i) == "/") {
        right = calculateStack.top(); calculateStack.pop();
        left= calculateStack.top(); calculateStack.pop();
        calculateStack.push(left / right);
      } else {
        calculateStack.push(stod(postFix.at(i)));
      }
    }
    if (!calculateStack.empty()) cout << fixed << setprecision(2) << calculateStack.top();
  }