#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"

int readWord(FILE* fd, char* buffer)
{
	int c;

	do {
		c = fgetc(fd);
		if (c == EOF)
			return 0;
	} while (!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if (c == 146)
			c = '\'';
	} while (isalpha(c) || c == '\'');

	*buffer = '\0';
	return 1;
}

int main()
{
	FILE* fd;
	char buffer[1024];
	Dictionary dict = create();

	fd = fopen("liar.txt", "rt");
	if (fd == NULL) {
		printf("Error opening file.\n");
		return 1;
	}

	while (readWord(fd, buffer))
		add(dict, buffer);

	fclose(fd);

	printf("---------- All words ----------\n\n");
	print(dict);

	// keep only the words that pass filter()
	dict = filterDictionary(dict, filter);
	printf("---------- Filtered words ----------\n\n");
	print(dict);

	destroy(dict);
	return 0;
}
