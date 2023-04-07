/*
정수 2개(a, b)를 입력받아 a를 2b배 곱한 값으로 출력해보자.
0 <= a <= 10, 0 <= b <= 10
*/

#include <stdio.h>
#include <math.h>

int main()
{
      int a, b;

      scanf("%d %d", &a, &b);
      printf("%d\n", a<<b);

      return 0;
}