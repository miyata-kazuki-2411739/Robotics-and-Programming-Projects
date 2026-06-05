#ifndef AVL_H
#define AVL_H

typedef struct Node {
    int key;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

Node* insert(Node* node, int key);
void inorder(Node* root);

#endif