/*
10진 정수 1개를 입력받아 아스키 문자로 출력해보자.
단, 0 ~ 255 범위의 정수만 입력된다.
*/

#include <stdio.h>

int main()
{
      char a;

      scanf("%hhd", &a);
      printf("%c",a);

      return 0;
}