#include <_stdio.h>
#include <_stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

 
struct node *newnode(int data) {
    struct node *node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}




void pre_order(struct node* root)
{  if (root==0)
   return;
   else
   printf("%d ",root->data);
   pre_order(root->left);
   pre_order(root->right);
}


void in_order(struct node* root)
{  if (root==0)
   return;
   else
   in_order(root->left);
   printf("%d ",root->data);
   in_order(root->right);
}


void post_order(struct node* root)
{  if (root==0)
   return;
   else
   post_order(root->left);
   post_order(root->right);
   printf("%d ",root->data);
}


int main(){

    struct node* root = newnode(1);
    root->left = newnode(10);
    root->left->left = newnode(20);
    root->right = newnode(34);
    root->right->right=newnode(45);
    root->right->left=newnode(20);

    pre_order(root);
    printf("\n");
    in_order(root);
    printf("\n");
    post_order(root);
    printf("\n");


}
