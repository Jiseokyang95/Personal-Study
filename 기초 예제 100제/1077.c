/*
정수(0 ~ 100) 1개를 입력받아 0부터 그 수까지 순서대로 출력해보자.
*/

#include <stdio.h>

int main(void)
{

      int i, n, sum = 0;

      scanf("%d", &n);

      for (i = 0; i <= n; i++)
      {
            if (i % 2 == 0)
            {
                  sum = sum + i;
            }
      }
      printf("%d", sum);
      return 0;
}
