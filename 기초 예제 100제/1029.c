/*
실수 1개를 입력받아 그대로 출력해보자.
(단, 입력되는 실수의 범위는 +- 1.7*10-308 ~ +- 1.7*10308 이다.)
*/

#include <stdio.h>

int main()
{
      double a;

      scanf("%lf", &a);
      printf("%.11lf", a);
      return 0;
}