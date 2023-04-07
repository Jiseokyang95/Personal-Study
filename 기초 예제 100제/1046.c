/*
정수 3개를 입력받아 합과 평균을 출력해보자.
단, -2147483648 ~ +2147483647
*/

#include <stdio.h>

int main()
{
      long long int a, b, c;

      scanf("%lld %lld %lld", &a, &b, &c);
      printf("%lld\n", a + b + c);
      printf("%.1f\n", ((float)a + (float)b +(float)c)/3);

      return 0;
}