/*
  uh_fgets.h
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

#ifndef _UH_FGETS_H
#define _UH_FGETS_H  1

#ifndef UH_FGETS_BUFFER_SIZE
#define UH_FGETS_BUFFER_SIZE 20000 /* default value is 20000 */
#endif

int   uh_fgets          (FILE *stream, char *save_ptr, int size_of_ptr);
int   uh_fgets_ignore   (FILE *stream, char *save_ptr, int size_of_ptr, char *ignore_char);

#endif /* _UH_FGETS_H */
