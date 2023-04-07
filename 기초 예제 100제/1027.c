/*년월일을 출력하는 방법은 나라마다, 형식마다 조금씩 다르다.

년월일(yyyy.mm.dd)를 입력받아,

일월년(dd-mm-yyyy)로 출력해보자.

(단, 한 자리 일/월은 0을 붙여 두자리로, 년도도 0을 붙여 네자리로 출력한다.) */

#include <stdio.h>

int main()
{
      int y,m,d;
      scanf("%4d.%2d.%2d", &y, &m, &d);
      printf("%02d-%02d-%04d", d, m, y);
      return 0;
}
