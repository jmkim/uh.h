/*
  uh_trim.c
  Trim the leading/trailing characters

  Author: Jongmin Kim <jmkim@pukyong.ac.kr>
  Written on October 29, 2015

  Revision History
  1. November 2, 2015
    * Minor bug fixes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uh_trim.h"

#define __UH__TRIM__ALL     1
#define __UH__TRIM__BOTH    2
#define __UH__TRIM__LEAD    3
#define __UH__TRIM__TAIL    4

char *uh_trim(char *input_string, char *remove_char, int type)
{
  if(input_string == NULL || remove_char == NULL) return NULL;
  char *fp_input = strdup(input_string);

  char *fp_temp = (char *)malloc(strlen(fp_input) + 1);
  int foo, fp_cursor = 0;

  switch(type)
  {
  case __UH__TRIM__ALL:
    for(foo = 0; foo < strlen(fp_input); foo++)
    {
      int bar, remove = 0;
      for(bar = 0; bar < strlen(remove_char); bar++)
        if(fp_input[foo] == remove_char[bar]) remove++;
      if(remove) continue;
 
      fp_temp[fp_cursor++] = fp_input[foo];
    }
    fp_temp[fp_cursor] = '\0';
    break;
  case __UH__TRIM__BOTH:
  case __UH__TRIM__LEAD:
    for(foo = 0; foo < strlen(fp_input); foo++)
    {
      int bar, remove = 0;
      for(bar = 0; bar < strlen(remove_char); bar++)
        if(fp_input[foo] == remove_char[bar]) remove++;
      if(remove) continue; else break;
    }
    while(foo < strlen(fp_input))
      fp_temp[fp_cursor++] = fp_input[foo++];
    fp_temp[fp_cursor] = '\0';
    if(type == __UH__TRIM__LEAD) break;
  case __UH__TRIM__TAIL:
    if(type == __UH__TRIM__BOTH) strcpy(fp_input, fp_temp);
    strcpy(fp_temp, fp_input);
    for(foo = strlen(fp_input) - 1; foo >= 0; foo--)
    {
      int bar, remove = 0;
      for(bar = 0; bar < strlen(remove_char); bar++)
        if(fp_input[foo] == remove_char[bar]) remove++;
      if(remove)
      {
        fp_temp[foo] = '\0';
        continue;
      }
      else break;
    }
    break;
  }

  char *fp = (char *)malloc(strlen(fp_temp) + 1);
  strcpy(fp, fp_temp);
  free(fp_temp);
  free(fp_input);

  return fp;
}

char *uh_trim_all(char *input_string, char *remove_char)
{
  return uh_trim(input_string, remove_char, __UH__TRIM__ALL);
}

char *uh_trim_both(char *input_string, char *remove_char)
{
  return uh_trim(input_string, remove_char, __UH__TRIM__BOTH);
}

char *uh_trim_leading(char *input_string, char *remove_char)
{
  return uh_trim(input_string, remove_char, __UH__TRIM__LEAD);
}

char *uh_trim_trailing(char *input_string, char *remove_char)
{
  return uh_trim(input_string, remove_char, __UH__TRIM__TAIL);
}
