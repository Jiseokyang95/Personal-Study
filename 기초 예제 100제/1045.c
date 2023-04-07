/*
정수 2개(a, b)를 입력받아 합, 차, 곱, 몫, 나머지, 나눈 값을 자동으로 계산해보자.
단 0 <= a, b <= 2147483647, b는 0이 아니다.

*/

#include <stdio.h>

int main()
{
      long long int a, b;

      scanf("%lld %lld", &a, &b);
      printf("%lld\n",a+b);
      printf("%lld\n",a-b);
      printf("%lld\n",a*b);
      printf("%lld\n",a/b);
      printf("%lld\n",a%b);
      printf("%.2f\n",(float)a/(float)b);

      return 0;
}