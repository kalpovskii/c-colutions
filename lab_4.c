// Задание: Вввести строку. Вывести слова, в которых каждая буква входит не менее двух раз

#include <stdio.h>
#include <stdlib.h>

// checks if char occurs more than twice and prints it

void checkWords (char *string, int start_word, int end_word) {
	int i = 0, j = 0, count = 0;
	for (i = start_word; i < end_word; i++) {
		for (j = i + 1; j <= end_word; j++) {
			if (string[i] == string[j]) {
				count++;	
			}
		}
	}
	if (count > 0) {
		for (i = start_word; i <= end_word; i++) {
			printf("%c", string[i]);
		}
		printf("%c\n", '\0');
	}
}

int is_char (char str) {
	if (((str >= 'A') && (str <= 'Z')) || ((str >= 'a') && (str <= 'z'))) {
		return 1;
	} else {
		return 0;
	}
}

int main () {
	int a = 0, length = 0, i = 0;
	printf("Input length of string:");
	scanf("%d\n", &length);
	char *string = malloc (length * sizeof(char));
	
	printf("Words: \n");
	while (((a = getchar()) != '\n') && (i < length)) {
		string[i] = a;
		i++;
	}
	i = 0;
	
	int start_word = 0, end_word = 0, first_word = 1;
	
	while (string[i] != 0) {
		if (is_char(string[i]) == 1) {
			if (first_word == 1) {
				start_word = i;
				first_word = 0;
			}
			if (string[i + 1] == 0) {
				end_word = i;
				checkWords (string, start_word, end_word);
			}
			i++;
		} else {
			if (is_char(string[i]) == 0) {
				end_word = i - 1;
				first_word = 1;
				checkWords (string, start_word, end_word);
				i++;
			}
		}
	}
	free(string);
	return 0;
}












