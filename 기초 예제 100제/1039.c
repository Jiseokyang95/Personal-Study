/*
정수 2개를 입력받아 합을 출력해보자.
단, 입력되는 정수는 -2147483648 ~ +2147483648 이다.
*/

#include <stdio.h>

int main()
{
      long long int a, b;

      scanf("%lld %lld", &a,&b);
      printf("%lld",a+b);

      return 0;
}