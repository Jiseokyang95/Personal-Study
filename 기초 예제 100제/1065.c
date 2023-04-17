/*
세 정수 a, b, c가 입력되었을 때, 짝수만 출력해보자.

*/
#include<stdio.h>

int main()
{
    int a[3] = {0};
    int i;

    scanf("%d %d %d", &a[0], &a[1], &a[2]);

    for (i = 0; i < 3; i++)
    {
        if (a[i] % 2 == 0)
        {
            printf("%d\n", a[i]);
        }
    }

    return 0;
}
