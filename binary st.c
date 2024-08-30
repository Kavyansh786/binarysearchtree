/*
NAME:KAVYANSH MEHTA
PROBLEM STATEMENT:BINARY SEARCH TREE
DATE:25/4/2024
*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

  struct tree
  {
      int data;
      struct tree *left;
      struct tree *right;
  };

    struct tree *root;

    struct tree* addnode(struct tree *node,int val)
    {
        if(node==NULL)
        {
            node=(struct tree *)malloc(sizeof(struct tree));
            node->data=val;
            node->right=NULL;
            node->left=NULL;
        }
        else if (node->data>val)
            node->left=addnode(node->left,val);
        else
            node->right=addnode(node->right,val);
    };
    void preorder(struct tree *node)
    {
        if (node==NULL)
            return;
        else
        {
            printf(" %d ",node->data);
            preorder(node->left);
            preorder(node->right);
        }
    }
    void inorder(struct tree *node)
    {
        if(node==NULL)
            return;
        else
        {
            inorder(node->left);
            printf(" %d ",node->data);
            inorder(node->right);
        }
    }
    void postorder(struct tree *node)
    {
        if(node==NULL)
            return;
        else
        {
            postorder(node->left);
            postorder(node->right);
            printf(" %d ",node->data);
        }
    }
   struct tree* search(struct tree *node, int comp)
   {
    if(node == NULL)
        return NULL;

    else if(node->data > comp)
        return search(node->left, comp);

    else if(node->data < comp)
        return search(node->right, comp);

    else
        return node;
}
   int totalnodes(struct tree *tree)
{
if(tree==NULL)
    return 0;
else
    return (totalnodes(tree->left)+totalnodes(tree->right)   +1);
}
    int main()
    {
        root=NULL;
       int choice=0;
       int val;
       while(choice<7)
       {
           printf("\nENTER 1 FOR ADDING NODE\nENTER 2 FOR INORDER\nENTER 3 FOR PREORDER\nENTER 4 FOR POSTORDER\nENTER 5 FOR SEARCHING\nENTER 6 FOR COUNTING NODES");
           scanf("%d",&choice);
             if(choice==1)
             {
                 printf("ENTER val");scanf("%d",&val);root=addnode(root,val);
             }
             if (choice==2)
             {
                 inorder(root);
             }
             if (choice==3)
             {
                 preorder(root);
             }
             if(choice==4)
             {
                 postorder(root);
             }
             if(choice==5)
             {
               int comp;
              printf("Enter value to search: ");
                scanf("%d", &val);
                 comp = search(root, val);
                if(comp != NULL)
                    printf("Value %d found in the tree.\n", val);
                else
                    printf("Value %d not found in the tree.\n", val);
             }
             if (choice==6)
             {
                 printf("\nTOTAL NUMBER OF NODES=%d",totalnodes(root));
             }
       }
    }
