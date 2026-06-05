#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

Node* rightRotate(Node* y);
Node* leftRotate(Node* x);
int getBalance(Node* node);

int max(int a, int b){
    return a > b ? a : b;
}

int height(Node* n){
    if(n == NULL) return 0;
    return n->height;
}

Node* newNode(int key){
    Node* node = (Node*)malloc(sizeof(Node));

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

Node* insert(Node* node, int key)
{
    if(node == NULL)
        return newNode(key);

    if(key < node->key)
        node->left = insert(node->left, key);

    else if(key > node->key)
        node->right = insert(node->right, key);

    else
        return node;

    node->height =
        1 + max(height(node->left),
                height(node->right));

    int balance = getBalance(node);

    if(balance > 1 &&
       key < node->left->key)
        return rightRotate(node);

    if(balance < -1 &&
       key > node->right->key)
        return leftRotate(node);

    if(balance > 1 &&
       key > node->left->key)
    {
        node->left =
            leftRotate(node->left);

        return rightRotate(node);
    }

    if(balance < -1 &&
       key < node->right->key)
    {
        node->right =
            rightRotate(node->right);

        return leftRotate(node);
    }

    return node;
}

void inorder(Node* root){

    if(root == NULL)
        return;

    inorder(root->left);

    printf("%d ", root->key);

    inorder(root->right);
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left),
                        height(y->right));

    x->height = 1 + max(height(x->left),
                        height(x->right));

    return x;
}

Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left),
                        height(x->right));

    y->height = 1 + max(height(y->left),
                        height(y->right));

    return y;
}

int getBalance(Node* node)
{
    if(node == NULL)
        return 0;

    return height(node->left)
         - height(node->right);
}