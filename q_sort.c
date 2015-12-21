#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int asc(const void *str1, const void *str2)
{ return strcmp( *(char *)str1, *(char *)str2); }

int dsc(const void *str1, const void *str2)
{ return strcmp(*(char **)str2, *(char **)str1); }

int main()
{
   char *strArr[] = {"cat", "ball", "apple"};
   int ne = sizeof(strArr) / sizeof(*strArr);

   qsort(strArr, ne, sizeof(char *), asc);
   for(int I = 0; I < ne; I++)
      printf("%s ", strArr[I]);
   printf("\n");

   qsort(strArr, ne, sizeof(char *), dsc);
   for(int I = 0; I < ne; I++)
      printf("%s ", strArr[I]);
   printf("\n");

   return 0;
}
