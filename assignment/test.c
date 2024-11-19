#include <stdio.h>
#include <string.h>

int main() {
  char str1[] = "test";
  char str2[] = "TestTestTest";
  int test = &str1[2] - &str1[0];
  printf("%d", test);
  return 0;
}