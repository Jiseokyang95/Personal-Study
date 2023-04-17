/*
세 정수 a, b, c가 입력되었을 때, 짝(even)/홀(odd)을 출력해보자.

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
            printf("even\n");
        }
        else if (a[i] % 2 != 0)
        {
            printf("odd\n");
        }
    }

    return 0;
}
