#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

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

Node* insert(Node* node, int key){

    if(node == NULL)
        return newNode(key);

    if(key < node->key)
        node->left = insert(node->left, key);

    else if(key > node->key)
        node->right = insert(node->right, key);

    node->height =
        1 + max(height(node->left),
                height(node->right));

    return node;
}

void inorder(Node* root){

    if(root == NULL)
        return;

    inorder(root->left);

    printf("%d ", root->key);

    inorder(root->right);
}