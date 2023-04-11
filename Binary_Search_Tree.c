#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;

};

typedef struct tree TREE;

TREE *insert_into_bst(TREE *root,int data)
{
    TREE *newnode,*cur = root,*parent = NULL;
    newnode = (TREE*)malloc(sizeof(TREE));
    if(newnode == NULL)
    {
        printf("Memory allocation error\n");
        return root;
    }


    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL)
    {
        root = newnode;
        return root;
    }

    while(cur!=NULL)
    {
        parent = cur;
        if(newnode->data < cur->data)
        {
            cur = cur->left;
        }

        else
        {
            cur = cur->right;
        }

    }

    if(newnode->data < parent->data)
    {
        parent->left = newnode;
    }

    else
    {
        parent->right = newnode;
    }

    return root;
}

TREE *delete_into_bst(TREE *root,int data)
{
    TREE *cur = root,*parent = NULL,*succ,*p;
    if(root==NULL)
    {
        printf("Tree empty\n");
    }
    while(cur!=NULL && data!=cur->data)
    {
        parent = cur;
        if(data<cur->data)
        {
            cur=cur->left;
        }

        else
        {
            cur = cur->right;
        }
    }

    if(cur==NULL)
    {
        printf("No data found\n");
        return root;
    }

    if(cur->left == NULL)
    {
        p = cur->right;
    }

    else if(cur->right==NULL)
    {
        p = cur->left;
    }

    else
    {
        succ = cur->right;
        while(succ->left!=NULL)
        {
            succ = succ->left;
        }

        succ->left = cur->left;
        p = cur->right;
    }

    if(parent == NULL)
    {
        printf("data %d is deleted successfully\n",cur->data);
        free(cur);
        return p;
    }

    if(cur == parent->left)
    {
        parent->left = p;
    }

    else
    {
        parent->right = p;
    }

    printf("data %d is deleted successfully\n",cur->data);
    free(cur);
    return root;
}

void preorder(TREE *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    TREE *root = NULL;
    int choice,data;
    while(1)
    {
        printf("\n1-insert\n2-traversal\n3-delete\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the data to be inserted\n");
            scanf("%d",&data);
            root = insert_into_bst(root,data);
            break;
        case 2:
            if(root==NULL)
            {
                printf("Tree empty\n");
            }
            preorder(root);
            break;
        case 3:
            printf("Enter the data to be deleted\n");
            scanf("%d",&data);
            root = delete_into_bst(root,data);
            break;
        default:
            exit(0);
        }
    }
}
