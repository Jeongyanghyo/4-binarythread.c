#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BST.h"

int main() {
	int inputData[] = { 4, 1, 9, 13, 15, 3, 6, 14, 7, 10, 12, 2, 5, 8, 11 };
	TreeNode* root = GenerateBinaryTree(inputData);
	printf("Binary tree Inorder: ");
	BinaryTreeInOrder(root);
	printf("\n");

	ThreadTree* troot = GenerateThreadTree(inputData);
	printf("Thread tree Inorder: ");
	ThreadTreeInOrder(troot);

	free(root);
	free(troot);


	return 0;
}

