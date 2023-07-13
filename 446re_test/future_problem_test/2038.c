/*
 * 2038.c
 *
 *  Created on: 2023/07/13
 *      Author: k-abe
 */
#include <time.h>

void get_date_string(time_t tmr, char* buf, int str_len) {
  struct tm* t;
  t = localtime(&tmr);
  strftime(buf, str_len, "%Y/%m/%d %H:%M:%S", t);
}

