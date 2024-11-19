#include <iostream>
using namespace std;

int main() {
  char charactor;
  string status, new_status, word;
  cin >> word;
  if (isdigit(word[0])) status = "digit";
  else if (islower(word[0])) status = "lower";
  else if (isupper(word[0])) status = "upper";
  cout << (char)toupper(word[0]);

  for (int i = 1; i < word.size(); i++) {
    charactor = word[i];

    if (isdigit(word[i])) new_status = "digit";
    else if (islower(word[i])) new_status = "lower";
    else if (isupper(word[i])) new_status = "upper";

    if (!(isupper(word[i]) && islower(word[i+1])) 
              && (new_status == status || (islower(word[i]) && isupper(word[i - 1])))) {
      cout << charactor;
    } else {
      cout << " " << (char)toupper(charactor);
    }
    status = new_status;
  }
  
}



