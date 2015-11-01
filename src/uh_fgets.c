/*
  uh_fgets.c
  Read string as line by line from stream

  Author: Jongmin Kim <jmkim@pukyong.ac.kr>
  Written on October 29, 2015

  Revision History
  1. November 2, 2015
    * Now `uh_fgets()' and `uh_fgets_ignore()' returns size of input.
    * Memory allocation removed. Allocated pointer is required.
    * `uh_fgets()' work as a normal input method (e.g. `scanf()'), and
      old one moved to `uh_fgets_ignore()'.
    * Default buffer size to 20000.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uh_fgets.h"

int uh_fgets(FILE *stream, char *save_ptr, int size_of_ptr)
{
  return uh_fgets_ignore(stream, save_ptr, size_of_ptr, NULL);
}

int uh_fgets_ignore(FILE *stream, char *save_ptr, int size_of_ptr, char *ignore_char)
{
  /* read string line by line from stream */
  char fp_char;
  char fp_array[UH_FGETS_BUFFER_SIZE + 1];
  if(size_of_ptr > UH_FGETS_BUFFER_SIZE) { size_of_ptr = UH_FGETS_BUFFER_SIZE; }

  int length = 0;
  while((fp_char = fgetc(stream)) != '\n' && fp_char != EOF)
  {
    if(length >= size_of_ptr) { break; }

    if(ignore_char != NULL)
    {
      /* check the ignore character */
      int foo, ignore = 0;
      for(foo = 0; foo < strlen(ignore_char); foo++)
      {
        if(fp_char == ignore_char[foo]) { ignore++; }
      }
      if(ignore) { continue; }
    }

    fp_array[length++] = fp_char;
  }
  fp_array[length] = '\0';

  strcpy(ptr_to_save, fp_array);
  return strlen(fp_array);
}
