/*
평가를 문자(A, B, C, D, ...)로 입력받아 내용을 다르게 출력해보자.

평가 내용
평가 : 내용
A : best!!!
B : good!!
C : run!
D : slowly~
나머지 문자들 : what?
*/

#include <stdio.h>

int main()
{
    char a;

    scanf(" %c", &a);

    switch (a)
    {
    case 'A':
        printf("best!!!\n");
        break;

    case 'B':
        printf("good!!\n");
        break;

    case 'C':
        printf("run!\n");
        break;

    case 'D':
        printf("slowly~\n");
        break;

    default:
        printf("what?\n");
        break;
    }

    return 0;
}
