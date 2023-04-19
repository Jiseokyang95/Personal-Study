/*
정수가 순서대로 입력된다.
-2147483648 ~ +2147483647, 단 개수는 알 수 없다.

0이 아니면 입력된 정수를 출력하고, 0이 입력되면 출력을 중단해보자.
*/

#include <stdio.h>

int main(void)
{

      int a;
      while (1)
      {
            scanf("%d", &a);
            if(a==0) break;
            printf("%d\n", a);
      }

      return 0;
}