#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BST.h"


TreeNode* GenerateBinaryTree(int inputData[]) {
    TreeNode* root = NULL;
    for (int i = 0; i < 15; i++) {
        root = insert_node(root, inputData[i]);
    }
    return root;
}

ThreadTree* GenerateThreadTree(int inputData[]) {
    ThreadTree* troot = NULL;
    for (int i = 0; i < 15; i++) {
        troot = insert_thread_node(troot, inputData[i]);
    }
    return troot;
}

TreeNode* new_node(int key) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

ThreadTree* NewThreadNode(int data) {
    ThreadTree* newNode = (ThreadTree*)malloc(sizeof(ThreadTree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->left_thread = true;
    newNode->right_thread = true;
    return newNode;
}

TreeNode* insert_node(TreeNode* root, int key) {
    if (root == NULL)
        return new_node(key);
    if (root->data == key) return root;
    else if (root->data > key)
        root->left = insert_node(root->left, key);
    else
        root->right = insert_node(root->right, key);

    return root;
}

ThreadTree* insert_thread_node(ThreadTree* root, int data) {
    ThreadTree* ptr = root;
    ThreadTree* par = NULL;
    while (ptr != NULL) {
        if (data == ptr->data) {
            return root;
        }
        par = ptr;
        if (data < ptr->data) {
            if (ptr->left_thread == false)
                ptr = ptr->left;
            else
                break;
        }
        else {
            if (ptr->right_thread == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    ThreadTree* tmp = NewThreadNode(data);
    if (par == NULL) {
        root = tmp;
        tmp->left_thread = tmp->right_thread = false;
    }
    else if (data < par->data) {
        tmp->left = par->left;
        tmp->right = par;
        par->left_thread = false;
        par->left = tmp;
    }
    else {
        tmp->left = par;
        tmp->right = par->right;
        par->right_thread = false;
        par->right = tmp;
    }

    return root;
}


// �Ϲ� ���� Ʈ���� ���� ��ȸ
void BinaryTreeInOrder(TreeNode* root) {
    if (root != NULL) {
        BinaryTreeInOrder(root->left);
        printf("%d ", root->data);
        BinaryTreeInOrder(root->right);
    }
}

ThreadTree* find_successor(ThreadTree* p) {
    if (p->right_thread == 1) {
        return p->right;
    }
    else {
        ThreadTree* current = p->right;
        while (current != NULL && current->left_thread == 0) {
            current = current->left;
        }
        return current;
    }
}


void ThreadTreeInOrder(ThreadTree* t) {
    if (t == NULL) {
        return;
    }
    ThreadTree* current = t;
    while (current->left_thread == false) {
        current = current->left;
    }

    while (current != NULL) {
        printf("%d ", current->data);
        current = find_successor(current);
    }
    printf("\n");
}



// ���� �˻� Ʈ������ ��� �˻�
TreeNode* search_bst(TreeNode* root, int key) {
    if (root == NULL) return NULL;
    if (root->data == key) return root;
    else if (root->data > key) return search_bst(root->left, key);
    else return search_bst(root->right, key);
}

// ���� ���� ���� ���� ��� ã��
TreeNode* min_value_node(TreeNode* root) {
    TreeNode* current = root;
    while (current->left != NULL) current = current->left;
    return current;
}

// ���� �˻� Ʈ������ ��� ����
TreeNode* delete_node(TreeNode* root, int key) {
    TreeNode* temp = NULL;
    if (root == NULL) return root;

    if (root->data > key) {
        root->left = delete_node(root->left, key);
    }
    else if (root->data < key) {
        root->right = delete_node(root->right, key);
    }
    else {
        // �ڽ� ��尡 ���� ���
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // ���� �ڽ��� ���� ���
        else if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }
        // ������ �ڽ��� ���� ���
        else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }
        // �ڽ��� �� �� ���� ���
        else {
            temp = min_value_node(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

