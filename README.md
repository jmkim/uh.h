```bash
### How to make a static library
gcc -c src/uh.c     # output will be "uh.o", if you not use `-o output_file'.

mkdir lib
ar rc lib/libuh.a uh.o
# ar options
# r     add new object to archive; in this case, "lib/libuh.a"
# c     create archive if not exist
rm uh.o

### How to link a static library
gcc -L ./lib -luh your_source_file.c
# gcc options
# -L [where_the_library_is]
# -l [name_of_the_library (except prefix "lib" and extension)]
#    example: to link "libuhfoo.a": -luhfoo
#             to link "libuhbar.a": -luhbar
#             to link both        : -luhfoo -luhbar

```

```c
/*
  example.c
  Trim the input string

  Author: Jongmin Kim <jmkim@pukyong.ac.kr>
  Written on October 29, 2015
*/

#include <stdio.h>
#include "src/uh_fgets.h"
#include "src/uh_trim.h"

int main(void)
{
  printf("Enter the string: ");
  char str[100];
  uh_fgets(stdin, str, 100);
  printf(
    "Trim the string..\n"
    "     all        : \"%s\"\n"
    "     both       : \"%s\"\n"
    "     lead only  : \"%s\"\n"
    "     tail only  : \"%s\"\n"
    , uh_trim_all(str, " ")
    , uh_trim_both(str, " ")
    , uh_trim_leading(str, " ")
    , uh_trim_trailing(str, " ")
  );

  return 0;
}
```
