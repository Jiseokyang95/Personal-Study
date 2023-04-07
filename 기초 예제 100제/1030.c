/*
정수 1개를 입력받아 그대로 출력해보자.
단, 입력되는 정수의 범위는
-9,223,372,036,854,775,808 ~ +9,223,372,036,854,775,807 이다.
*/

#include <stdio.h>

int main()
{
      long long int a;

      scanf("%lld", &a);
      printf("%lld", a);

      return 0;
}