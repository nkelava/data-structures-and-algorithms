#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bst.h"

BSTree NewBSTree()
{
	// New empty tree
	return NULL;
}

BSTree create_node(char* word) {
	BSTree newNode = (BSTree)malloc(sizeof(Node));
	if (!newNode) return 0;

	newNode->word = strdup(word);
	newNode->right = NULL;
	newNode->left = NULL;

	return newNode;
}

void AddNode(BSTree* bst, char* word)
{
	// Recursively find the place for the new node in the tree. If the word already exists in the tree, it is not added. The bst parameter is a double pointer.
	if (*bst == NULL) {
		*bst = create_node(word);
		return;
	}
	else if (strcmp((*bst)->word, word) == 0) { return; }
	else if (strcmp((*bst)->word, word) > 0)
		AddNode(&(*bst)->left, word);
	else
		AddNode(&(*bst)->right, word);
}

int max(int a, int b) {
	return (a >= b) ? a : b;
}

int BSTHeight(BSTree bst)
{
	// Recursively traverse the whole tree to find the longest branch (the height of the tree).
	if (bst == NULL) return 0;
	
	return 1 + max(BSTHeight(bst->left), BSTHeight(bst->right));
}

void PrintBSTree(BSTree bst)
{
	if (bst == NULL) return;
	//inorder( left, parent, right)
	PrintBSTree(bst->left);
	printf("%s ", bst->word);
	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE* fd)
{
	// Save the tree to a text file word by word. Words are separated by a space.
	// Pre-order traversal of the tree (current node, then children)
	if (bst == NULL) return;

	fputs(bst->word, fd);
	fputs(" ", fd);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree bst)
{
	// Delete the tree (the word string and the node itself) from memory.
	// Post-order traversal of the tree (children first, then the current node)
	if (bst == NULL) return;

	DeleteBSTree(bst->right);
	DeleteBSTree(bst->left);

	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE* fd)
{
	// Read a text file word by word and add the words to the tree with the AddNode() function.
	// Duplicate the word with strdup().

	BSTree dict = NewBSTree();
	int wordCount = 0;
	char str[100];

	while (fscanf(fd, "%s", str) > 0){
		AddNode(&dict, str);
		wordCount++;
	}
	return dict;
}
