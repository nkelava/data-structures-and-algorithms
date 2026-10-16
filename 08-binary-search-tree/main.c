#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include "bst.h"

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
	int wc;
	FILE* fd;
	char buffer[1024];
	BSTree bst = NewBSTree();

	// Build the tree
	fd = fopen("liar.txt", "rt");
	if (fd == NULL){
		printf("Error opening file.\n");
		return 1;
	}

	wc = 0;
	while (readWord(fd, buffer)){
		//printf("%s\n", buffer);
		AddNode(&bst, buffer);
		wc++;
	}

	fclose(fd);

	// Print the tree, its height and the number of nodes
	PrintBSTree(bst);
	printf("\nH = %d, N = %d\n", BSTHeight(bst), wc);

	// Save and delete
	if ((fd = fopen("tree.txt", "wt")) == NULL){
		printf("Error opening file for writing.\n");
		return 1;
	}
	SaveBSTree(bst, fd);
	fclose(fd);

	DeleteBSTree(bst);

	// Load the tree
	if ((fd = fopen("tree.txt", "rt")) == NULL){
		printf("Error opening file for reading.\n");
		return 1;
	}

	bst = LoadBSTree(fd);
	fclose(fd);

	// Print the height and delete
	printf("\nH = %d\n", BSTHeight(bst));
	PrintBSTree(bst);
	DeleteBSTree(bst);
	printf("\n\n\n\t---------   THE END   ---------\n");
	return 0;
}
