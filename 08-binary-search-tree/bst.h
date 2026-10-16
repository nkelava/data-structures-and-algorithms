#ifndef TREE_H
#define TREE_H
#include <string.h>

// Tree node with a pointer to the word and to the node's children
typedef struct _Node{
	char* word;
	struct _Node *left, *right;
}Node;

// The tree, i.e. a pointer to the root of the tree
typedef Node* BSTree;

BSTree NewBSTree();
BSTree create_node(char*);
int max(int, int);
void AddNode(BSTree* bst, char* word);
int BSTHeight(BSTree bst);
void PrintBSTree(BSTree bst);
void SaveBSTree(BSTree bst, FILE* fd);
void DeleteBSTree(BSTree bst);
BSTree LoadBSTree(FILE* fd);

#endif