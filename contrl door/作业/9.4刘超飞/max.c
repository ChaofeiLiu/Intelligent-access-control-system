#include <stdio.h>
#define MAX(a,b) a>b ? a:b
int main()
{
  int max=MAX(11,22);
  printf("max:%d\n",max);
  return 0;
}
