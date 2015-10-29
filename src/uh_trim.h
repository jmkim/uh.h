/*
  uh_trim.h
  Trim the leading/trailing characters

  Author: Jongmin Kim <jmkim@pukyong.ac.kr>
  Written on October 29, 2015
*/

#ifndef _UH_TRIM_H
#define _UH_TRIM_H  1

char *uh_trim_all(char *input_string, char *remove_char);
char *uh_trim_both(char *input_string, char *remove_char);
char *uh_trim_leading(char *input_string, char *remove_char);
char *uh_trim_trailing(char *input_string, char *remove_char);

#endif /* _UH_TRIM_H */
