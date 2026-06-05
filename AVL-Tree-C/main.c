#include <stdio.h>
#include "avl.h"

int main()
{
    Node* root = NULL;

    int data[] =
    {
        10,20,30,40,50,25
    };

    for(int i=0;i<6;i++)
        root = insert(root,data[i]);

    inorder(root);

    printf("\n");

    return 0;
}