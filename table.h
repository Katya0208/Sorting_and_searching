#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>

typedef struct _row {
  long int _key;
  char _str[120];
} row;

void print_table(row *arr, const int size);
void get_row(FILE *stream, char *str, const int size);
void swap_rows(row *r1, row *r2);

#endif