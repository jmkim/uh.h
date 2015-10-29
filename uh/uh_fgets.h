/*
  uh_fgets
  Read string as line by line from stream

  Author: Jongmin Kim <jmkim@pukyong.ac.kr>
  Written on October 29, 2015

  include: <stdio.h>, <stdlib.h>, <string.h>
*/

#ifndef _UH_FGETS_H
#define _UH_FGETS_H  1

#ifndef UH_FGETS_INPUT_LEN
#define UH_FGETS_INPUT_LEN  200 /* default value is 200 */
#endif

char *uh_fgets(FILE *stream, char *ignore_char)
{
  /* read string line by line from stream */
  char fp_char;
  char fp_array[UH_FGETS_INPUT_LEN + 1];

  int length = 0;
  while((fp_char = fgetc(stream)) != '\n' && fp_char != EOF)
  {
    if(length >= UH_FGETS_INPUT_LEN) break;

    if(ignore_char != NULL)
    {
      /* check the ignore character */
      int foo, ignore = 0;
      for(foo = 0; foo < strlen(ignore_char); foo++)
      {
        if(fp_char == ignore_char[foo]) ignore++;
      }
      if(ignore) continue;
    }

    fp_array[length++] = fp_char;
  }
  fp_array[length] = '\0';

  char *fp = (char *)malloc(strlen(fp_array) + 1);
  strcpy(fp, fp_array);

  return fp;
}
#endif /* _UH_FGETS_H */
