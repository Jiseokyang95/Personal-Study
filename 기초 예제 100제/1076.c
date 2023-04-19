/*
영문자(a ~ z) 1개가 입력되었을 때 그 문자까지의 알파벳을 순서대로 출력해보자.
*/

#include <stdio.h>

int main(void)
{

      char x, a = 'a';

      scanf("%c", &x);

      do
      {
            printf("%c ", a);
            a++;
      } while (a < x + 1);
      return 0;
}
