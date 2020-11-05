#include <string.h>
#include<ctype.h>

#ifndef __SASC

/* function strlwr() */
char *strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;
  while (*p) {
    *p = tolower((unsigned char)*p);
    p++;
  }
  return str;
}

/* function strrev() */
char *strrev(char *str)
{
  char *p1, *p2;
  if (! str || ! *str)
  return str;
  for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
  {
    *p1 ^= *p2;
    *p2 ^= *p1;
    *p1 ^= *p2;
  }
  return str;
}

#endif

char *strduplwr(char *str, unsigned long requirements)
{
  unsigned char *p = AllocVec(strlen(str) + 1, requirements);
  if (!p) {
    return NULL;
  }
  strcpy(p, (unsigned char *)str);
  return (char *)strlwr(p);
}

char *strduprev(char *str, unsigned long requirements) {
  unsigned char *p = AllocVec(strlen(str) + 1, requirements);
  if (!p) {
    return NULL;
  }
  strcpy(p, (unsigned char *)str);
  return (char *)strrev(p);
}
