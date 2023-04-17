/*
월이 입력될 때 계절 이름이 출력되도록 해보자.

예
월 : 계절 이름
12, 1, 2 : winter
  3, 4, 5 : spring
  6, 7, 8 : summer
  9, 10, 11 : fall
*/

#include <stdio.h>

int main()
{
      int a;

      scanf(" %d", &a);

      switch (a)
      {
      case 12:
      case 1:
      case 2:
            printf("winter\n");
            break;

      case 3:
      case 4:
      case 5:
            printf("spring\n");
            break;

      case 6:
      case 7:
      case 8:
            printf("summer\n");
            break;

      case 9:
      case 10:
      case 11:
            printf("fall\n");
            break;

      default:
            printf("what?\n");
            break;
      }

      return 0;
}
