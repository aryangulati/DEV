#include <stdio.h>

int main()
{
  int a, b;
  printf("Enter first multiple: ");
  scanf("%i", &a);
  printf("Enter upto: ");
  scanf("%i", &b);
  for(int i = 1; i <= b; i++) {
    printf("%i * %i = %i\n", a, i, a*i);
  }
  return 0;
}
