#include <stdio.h>
#include "avl.h"

int main(){

    Node* root = NULL;

    root = insert(root, 8);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 2);

    printf("Inorder: ");

    inorder(root);

    printf("\n");

    return 0;
}