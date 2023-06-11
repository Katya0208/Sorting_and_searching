#ifndef FUNC_H
#define FUNC_H

#include "table.h"

int bin_search(const row *mass, const int size, const long int key);
void shaker_sort(row *mass, const int count);
void shuffle(row *mass, const int size);
void reverse(row *mass, const int size);
int random_ab(const int a, const int b); 
int is_sorted(const row *mass, const int size);

#endif