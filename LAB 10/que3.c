#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node *newnode(int data) {
    struct node *node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int countLN(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;  
    }
    return countLN(root->left) + countLN(root->right);
}

int main() {
    struct node* root = newnode(1);
    root->left = newnode(10);
    root->left->left = newnode(20);
    root->right = newnode(34);
    root->right->right=newnode(45);
    root->right->left=newnode(20);

    int leafCount = countLN(root);
    printf("Number of leaf nodes: %d\n", leafCount);

    return 0;
}