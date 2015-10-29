/*
  uh_fgets.h
  Read string as line by line from stream

  Author: Jongmin Kim <jmkim@pukyong.ac.kr>
  Written on October 29, 2015
*/

#ifndef _UH_FGETS_H
#define _UH_FGETS_H  1

#define UH_FGETS_MAX_INPUT_LEN  200 /* default value is 200 */

char *uh_fgets(FILE *stream, char *ignore_char);

#endif /* _UH_FGETS_H */
