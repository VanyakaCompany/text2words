#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Очистить буфер от остатков
void clearBuffer() {
  char c;
  do {
    scanf("%c", &c);
  } while (c != '\n');
}

// Считать из консоли в указанную переменную целое число в указанном диапазоне (включительно)
void readInt(int *result, int min, int max) {
  bool isReaded;

  while (true) {
    printf("Введите число [%d, %d]: ", min, max);
    isReaded = (bool)scanf("%d", result);
    clearBuffer();

    if (!isReaded || *result < min || *result > max) {
      printf("Необходимо указать целое число от %d до %d (включительно)\n", min, max);
    } else {
      break;
    }
  }
}

// Считать из консоли в указанную переменную строку (в указанном формате)
void readString(int index, char result[], char format[]) {
  bool isReaded;

  while (true) {
    printf("Введите строку № %d: ", index);
    isReaded = (bool)scanf(format, result);
    clearBuffer();

    if (!isReaded) {
      printf("Не удалось считать строку!\n");
    } else {
      break;
    }
  }
}

// Проверить, имеется ли переданный элемент в указанном массиве
bool isIncluded(char item, char arr[]) {
  for (int i = 0; i < strlen(arr); i++) {
    if (item == arr[i]) return true;
  }

  return false;
}

// Вывести в консоль подстроку из переданной строке (от start до end, включительно)
void printSubstr(char str[], int start, int end) {
  int length = strlen(str);

  if (end >= length) end = length - 1;

  for (int i = start; i <= end; i++) {
    printf("%c", str[i]);
  }

  printf("\n");
}

// Разбить строку по разделителям и вывести в консоль все слова
int printWords(char str[], char seps[]) {
  int result = 0;
  int start = -1;
  int end = -1;

  for (int i = 0; i < strlen(str); i++) {
    if (!isIncluded(str[i], seps)) {
      if (start < 0) start = i;
    }

    if (isIncluded(str[i + 1], seps) || str[i + 1] == '\0') {
      if (start >= 0 && end < 0) end = i;
    }

    if (start >= 0 && end >= 0) {
      printSubstr(str, start, end);
      start = end = -1;
      result++;
    }
  }

  return result;
}

int main(void) {
  int M;
  char text[20][81] = {};
  char seps[] = " ,.";
  int wordsCount = 0;

  readInt(&M, 1, 20); // Считывание кол-ва строк

  for (int i = 0; i < M; i++) {
    readString(i + 1, text[i], "%80[^\n]"); // Считывание строки
  }

  printf("\nРезультат:\n");

  // Вывод слов из текста
  for (int i = 0; i < M; i++) {
    wordsCount += printWords(text[i], seps);
  }

  if (!wordsCount) printf("no solution!\n");

  printf("\nИсходный текст:\n");

  for (int i = 0; i < M; i++) {
    printf("\"%s\"\n", text[i]);
  }

  return 0;
}
