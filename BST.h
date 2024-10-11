#pragma once

typedef struct tree_node {
	int data;
	struct tree_node* left, * right;
} TreeNode;

typedef struct thread_node {
	int data;
	struct thread_node* left, * right;
	int left_thread;
	int right_thread;
} ThreadTree;

extern TreeNode* GenerateBinaryTree(int inputData[]);
extern TreeNode* new_node(int key);
extern TreeNode* insert_node(TreeNode* root, int key);
extern void BinaryTreeInOrder(TreeNode* root);
extern TreeNode* search_bst(TreeNode* root, int key);
extern TreeNode* min_value_node(TreeNode* root);
extern TreeNode* delete_node(TreeNode* root, int key);

extern ThreadTree* GenerateThreadTree(int inputData[]);
extern ThreadTree* insert_thread_node(ThreadTree* root, int key);
extern void ThreadTreeInOrder(ThreadTree* t);
extern ThreadTree* find_successor(ThreadTree* p);
extern ThreadTree* GenerateThreadTree(int inputData[]);
extern ThreadTree* NewThreadNode(int data);