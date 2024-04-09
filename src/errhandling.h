#ifndef ERR_HANDLING
#define ERR_HANDLING

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

inline char* __current_date_time__(char* str) {
  time_t now = time(0);
  struct tm tstruct;
  char* buf;
  buf = (char*)malloc(80);
  tstruct = *localtime(&now);
  if (strcmp( str, "now" ))
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
  if (strcmp( str, "date"))
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
  return buf;
} 

inline void Logger( char* logMsg ) {
  char* filePath = "/home/kinveth/git/engine/logging/log_";
  strcat(filePath, __current_date_time__("date"));
  strcat(filePath, ".txt");
  char* now = __current_date_time__("now");
  FILE* f;
  f = fopen(filePath, "a");
  char* str;
  fprintf(f, "%s\t%s\n", now, logMsg);
  fclose(f);
}

#define assert(expr, msg) \
  if (!(expr)) \
    Logger( msg );

#endif
