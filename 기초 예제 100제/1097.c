/*
부모님을 기다리던 영일이는 검정/흰 색 바둑알을 바둑판에 꽉 채워 깔아 놓고 놀다가...

"십(+)자 뒤집기를 해볼까?"하고 생각했다.

바둑판(19 * 19)에 흰 돌(1) 또는 검정 돌(0)이 모두 꽉 채워져 놓여있을 때,
n개의 좌표를 입력받아 십(+)자 뒤집기한 결과를 출력하는 프로그램을 작성해보자.

참고
가로 번호, 세로 번호를 사용할 수 있는 2차원 배열을 사용하면
이러한 형태를 쉽게 기록하고 사용할 수 있다. 물론 더 확장한 n차원 배열도 만들 수 있다.
*/
#include <stdio.h>

int i, j, n, x, y;
int plate[19][19] = {0};

int main()
{
      for (i = 0; i < 19; i++)
      {
            for (j = 0; j < 19; j++)
            {
                  scanf("%d ", &plate[i][j]);
            }
      }
      scanf("%d", &n);
      for (int k = 0; k < n; k++)
      {
            scanf("%d %d", &x, &y);
            for (i = 0; i < 19; i++)
            {
                  if (plate[x-1][i] == 1)
                        plate[x-1][i] = 0;
                  else if (plate[x-1][i] == 0)
                        plate[x-1][i] = 1;
            }
            for (i = 0; i < 19; i++)
            {
                  if (plate[i][y-1] == 1)
                        plate[i][y-1] = 0;
                  else if (plate[i][y-1] == 0)
                        plate[i][y-1] = 1;
            }
      }

      for (i = 0; i < 19; i++)
      {
            for (j = 0; j < 19; j++)
            {
                  printf("%d ", plate[i][j]);
            }
            printf("\n");
      }
}
