#include <stdio.h>

int main() {
  int k = 0;
  for (int i = 0; i < 100; i += 10)
    for (int j = 0; j < 100; j+= 10)
      k++;
  printf("%d", k);
  return 0;

}