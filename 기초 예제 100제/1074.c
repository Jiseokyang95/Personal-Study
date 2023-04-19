/*
정수(1 ~ 100) 1개가 입력되었을 때 카운트다운을 출력해보자.


while(조건)
{
  ...
}
구조를 사용하자.
*/

#include <stdio.h>

int main(void)
{

      int a;

      scanf("%d", &a);

      while (1)
      {
            printf("%d\n", a);
            a--;
            if (a == 0)
                  break;
      }
      return 0;
}