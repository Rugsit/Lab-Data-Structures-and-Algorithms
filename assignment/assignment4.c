#include <stdio.h>
#include <stdlib.h>
//6610402205

void calRecArea(float, float, float*);
void printArea(float);

void inputWidhtHeight() {
  float width, length, area;
  printf("Enter width : ");
  scanf("%f", &width);
  printf("Enter length : ");
  scanf("%f", &length);
  calRecArea(width, length, &area);
  printArea(area);
}

void calRecArea(float w, float l, float *pArea) {
  *pArea = w * l;
}

void printArea(float area) {
  printf("Rectangle area is %.2f", area);
}


int main() {
  inputWidhtHeight();
  return 0;
}