//다섯 자리의 정수 1개를 입력받아 각 자리별로 나누어 출력한다.
#include <stdio.h>
#include <math.h>
#define BUF 5

int main(void)
{
      int arr[BUF];

      scanf("%1d%1d%1d%1d%1d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
      for (int i = 4; i >= 0; i--)
      {
            printf("[%d]\n", arr[4 - i] * (int)pow(10, i));
      }

      return 0;
}