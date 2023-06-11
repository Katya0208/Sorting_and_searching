#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "table.h"

int bin_search(const row* mass, const int size, const long int key) {
  if (size <= 0) return -1;

  int start = 0;
  int end = size - 1;

  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (mass[mid]._key == key)
      return mid;
    else if (mass[mid]._key < key)
      start = mid + 1;
    else
      end = mid - 1;
  }

  return -1;
}

void shaker_sort(row* mass, const int count) {
  int left = 0;
  int right = count - 1;
  int flag = 1;

  while (left < right && flag > 0) {
    flag = 0;

    for (int i = left; i < right; i++) {
      if (mass[i]._key > mass[i + 1]._key) {
        swap_rows(&mass[i], &mass[i + 1]);
        flag = 1;
      }
    }
    right--;

    for (int i = right; i > left; i--) {
      if (mass[i - 1]._key > mass[i]._key) {
        swap_rows(&mass[i], &mass[i - 1]);
        flag = 1;
      }
    }
    left++;
  }
}

int random_ab(const int a, const int b) { return a + rand() % (b - a + 1); }

void shuffle(row* mass, const int size) {
  srand((unsigned int)time(0));

  for (int k = 0; k < size; k++) {
    int i = random_ab(0, size - 1);
    int j = random_ab(0, size - 1);
    swap_rows(&mass[i], &mass[j]);
  }
}

void reverse(row* mass, const int size) {
  for (int i = 0, j = size - 1; i < j; i++, j--) {
    swap_rows(&mass[i], &mass[j]);
  }
}

int is_sorted(const row* mass, const int size) {
  for (int i = 0; i < size - 1; i++) {
    if (mass[i]._key > mass[i + 1]._key) {
      return 0;
    }
  }
  return 1;
}