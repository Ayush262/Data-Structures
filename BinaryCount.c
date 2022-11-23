#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *left;
    int info;
    struct node *right;
}tree;

void input(tree **rt, int nm) 
{
    if(*rt==NULL)                                   //Creating Nodes
    {
        *rt=(tree *)malloc(sizeof(tree));
        (*rt)->left=NULL;
        (*rt)->info=nm;
        (*rt)->right=NULL;
    }
    else if((*rt)->info<nm)                         //if Input is greater than root
    {
        input(&(*rt)->right, nm);
    }
    else if((*rt)->info>nm)                         //if Input is smaller than root
    {
        input(&(*rt)->left, nm);
    }
}
void count(tree *rt, int *nm)                       //Counting All nodes
{
    if(rt==NULL)
        return;
    count(rt->left, nm);
    (*nm)++;
    count(rt->right, nm);
}

void countleaf(tree *rt, int *nm)                   //Counting nodes with no child
{
    if(rt==NULL)
        return;
    countleaf(rt->left, nm);
    if(rt->left==NULL && rt->right==NULL)
        (*nm)++;
    countleaf(rt->right, nm);
}
void countone(tree *rt, int *nm)                    //Counting nodes with one child 
{
    if(rt==NULL)
        return;
    countone(rt->left, nm);
    if(rt->left!=NULL || rt->right==NULL)
        (*nm)++;
    if(rt->left==NULL || rt->right!=NULL)
        (*nm)++;
    countone(rt->right, nm);
}
int main()
{
    int i=0, a=0, b=0, c=0, num, n;                     //Variables
    tree *root=NULL;                                    //Creating Root
    printf("Enter size: ");                             //Size
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Enter Number: ");
        scanf("%d", &num);                              //Value to be stored
        input(&root, num);                              //Calling Input Function
    }
    count(root, &a);                                    //Calling Count Function
    countleaf(root, &b);                                //Calling CountLeaf Function
    countone(root, &c);                                 //Calling Countone Function
    printf("Total nodes: %d\n", a);                     //Pinting All Counters
    printf("Total Leaf nodes: %d\n", b);                
    printf("Total nodes with one child: %d\n", c);      
    return 0;
}
