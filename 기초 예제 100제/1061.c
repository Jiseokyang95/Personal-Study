/*
입력된 정수 두 개를 비트단위로 or 연산한 후 그 결과를 정수로 출력해보자.
비트단위(bitwise) 연산자 |(or, vertical bar, 버티컬바)를 사용하면 된다.

*/

#include<stdio.h>

int main ()
{
int a,b;

scanf("%d %d", &a, &b);
printf("%d", a|b);

return 0;
}