/*
정수 1개가 입력되었을 때, 음(minus)/양(plus)과 짝(even)/홀(odd)을 출력해보자.
*/
#include <stdio.h>

int main()
{
      int a = 0;

      scanf("%d", &a);

      if (a < 0)
      {
            printf("minus\n");
            if (a % 2 == 0)
            {
                  printf("even\n");
            }
            else if (a % 2 != 0)
            {
                  printf("odd\n");
            }
      }
      else
      {
            printf("plus\n");
            if (a % 2 == 0)
            {
                  printf("even\n");
            }
            else if (a % 2 != 0)
            {
                  printf("odd\n");
            }
      }

      return 0;
}