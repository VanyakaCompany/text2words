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

// Разбить строку по разделителям и вывести в консоль все слова
int printWords(char string[], char seps[]) {
  int result = 0;
  char *token;

  token = strtok(string, seps);

  while (token != NULL) {
    result++;
    printf("%s\n", token);
    token = strtok(NULL, seps);
  }

  return result;
}

int main(void) {
  int n;
  char text[20][81] = {};
  char seps[] = " ,.";
  int wordsCount = 0;

  readInt(&n, 1, 20); // Считывание кол-ва строк

  for (int i = 0; i < n; i++) {
    readString(i + 1, text[i], "%80[^\n]"); // Считывание строки
  }

  printf("\nРезультат:\n");

  // Вывод слов из текста
  for (int i = 0; i < 20; i++) {
    if (strlen(text[i])) {
      wordsCount += printWords(text[i], seps);
    }
  }

  if (!wordsCount) printf("no solution!\n");

  return 0;
}
