#include <stdio.h>
#include <stdlib.h>

 
struct node {
    int data;
    struct node* left;
    struct node* right;
};

 
struct node* newnode(int data) {
    struct node *node; 
    node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int Height(struct node* root) {
    if (root == NULL)
        return -1; 
        int left_height = Height(root->left);
        int right_height =Height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
}

int Depth(struct node* root, int key, int depth) {
    if (root == NULL)
        return -1;
    if (root->data == key)
        return depth;

    int left = Depth(root->left, key, depth + 1);
    if (left != -1)
        return left;

    return Depth(root->right, key, depth + 1);
}

int main(){
    struct node* root = newnode(1);
    root->left = newnode(10);
    root->left->left = newnode(20);
    root->right = newnode(34);
    root->right->right=newnode(45);
    root->right->left=newnode(20);

    int height = Height(root);
    printf("Height of the tree: %d\n", height);

    int key = 55;
    int depth = Depth(root, key, 0);
    if (depth != -1)
        printf("Depth of node %d: %d\n", key, depth);
    else
        printf("Node not found in the tree.\n");

    return 0;
}
