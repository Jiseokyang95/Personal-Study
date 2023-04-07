/*
단어를 1개 입력받는다.

입력받은 단어(영어)의 각 문자를

한줄에 한 문자씩 분리해 출력한다.
*/

#include <stdio.h>

int main()
{
      char string[30];

      scanf("%s", string);

      for(int i=0; string[i]!='\0'; i++)
      {
            printf("\'%c\'\n", string[i]);
      }
      return 0;
}