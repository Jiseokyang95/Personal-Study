/*
입력된 정수의 부호를 바꿔 출력해보자.
단, -2147483647 ~ +2147483647 범위의 정수가 입력된다.
*/

#include <stdio.h>

int main()
{
      long long int a, b;

      scanf("%lld", &a);
      printf("%lld",-a);

      return 0;
}