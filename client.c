#include <stdio.h>
#include <stdlib.h>

#include "func.h"

int main(void) {
  printf("Напишите '?' для получения справки об использовании программы:\n");
  char c;

  const int N = 50;
  int i, cnt, action;
  long key;
  char ch;
  row mass[N];
  FILE* file = fopen("test.txt", "r");

  if (file == NULL) {
    printf("Ошибка при открытии файла\n");
    return 0;
  }
  i = 0;
  while (i < N && fscanf(file, "%ld", &mass[i]._key) == 1) {
    fscanf(file, "%c", &ch);
    get_row(file, mass[i]._str, sizeof(mass[i]._str));
    i++;
  }
  fclose(file);
  cnt = i;

  while ((c = getchar()) != EOF) {
    switch (c) {
      case '?':
        printf("Набор команд:\n");
        printf("1 - вывести таблицу.\n");
        printf("2 - найти и вывести в таблице строку по ключу.\n");
        printf("3 - отсортировать таблицу по ключам.\n");
        printf("4 - перемешать строки таблицы.\n");
        printf("5 - перевести таблицу в обратный порядок.\n");
        printf("6 - закончить сеанс.\n");
        break;
      case '1':
        print_table(mass, cnt);
        break;
      case '2':
        if (!is_sorted(mass, cnt)) {
          printf("Таблица не отсортирована\n");
        } else {
          printf("Введите ключ для поиска: ");
          scanf("%ld", &key);
          i = bin_search(mass, cnt, key);
          if (i > -1) {
            printf("строка по ключу: %s\n", mass[i]._str);
          } else {
            printf("Элементов с таким ключом не существует\n");
          }
        }
        break;
      case '3':
        shaker_sort(mass, cnt);
        break;
      case '4':
        shuffle(mass, cnt);
        break;
      case '5':
        reverse(mass, cnt);
        break;
      case '6':
        printf("Выход...\n");
        return 0;
      default:
        if (c != '\n' && c != '\t' && c != ' ') {
          printf("Неправильный ввод, повторите попытку\n");
        }
        break;
    }
  }
  return 0;
}
