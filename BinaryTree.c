#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create()
{
    struct node *temp;
    int choice, data;

    temp = (struct node *)malloc(sizeof(struct node));

    printf("Press 0 to exit\n");
    printf("Press 1 for a new node\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 0)
    {
        return NULL;
    }
    else
    {
        printf("Enter the data: ");
        scanf("%d", &data);

        temp->data = data;

        printf("Enter the left child of %d: ", data);
        temp->left = create();

        printf("Enter the right child of %d: ", data);
        temp->right = create();

        return temp;
    }
}

int main()
{
    struct node *root;
    root = create();

    return 0;
}