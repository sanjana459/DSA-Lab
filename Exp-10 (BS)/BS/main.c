#include<stdio.h>

typedef struct node
{
int info;
struct node *llink;
struct node *rlink;
}NODE;
NODE *root=NULL;

void inorder(NODE *ptr)
{
if(ptr)
{
inorder(ptr->llink);
printf("%d",ptr->info);
inorder(ptr->rlink);
}
}

void preorder(NODE *ptr)
{
if(ptr)
{
printf("%d",ptr->info);
preorder(ptr->llink);
preorder(ptr->rlink);
}
}

void postorder(NODE *ptr)
{
if(ptr)
{
postorder(ptr->llink);
postorder(ptr->rlink);
printf("%d",ptr->info);
}
}

void create()
{
NODE *nn,*prev,*temp;
int i,n;
printf("enter the value of n\n");
scanf("%d",&n); //n is number of nodes in a tree
for(i=1;i<=n;i++)
{
nn=(NODE*)malloc(sizeof(NODE));
printf("enter the info\n");
scanf("%d",&nn->info);
nn->llink=NULL;
nn->rlink=NULL;

if(root==NULL)
root=nn;
else
{
temp=root;


while(temp!=NULL)
{
prev=temp;

if(nn->info>temp->info)
temp=temp->rlink;
else
temp=temp->llink;
}


if(nn->info<prev->info)
prev->llink=nn;
else
prev->rlink=nn;
}
}
}

NODE * search(NODE *temp, int key)
{
if(temp==NULL) return NULL;
else if(key<temp->info)
return search(temp->llink, key);
else if(key>temp->info)
return search(temp->rlink,key);
else
return temp;
}

void main()
{
int ch, key;
NODE *f;
do
{
printf("1:create 2:inorder 3:preorder 4:postorder 5:search\n");
scanf("%d",&ch);
switch(ch)
{
case 1: create();
break;
case 2: inorder(root);
break;
case 3: preorder(root);
break;
case 4: postorder(root);
break;
case 5: printf("enter the key\n");
scanf("%d",&key);
f=search(root, key);
if(f==NULL)
printf("key not found\n");
else
printf("key found");
break;
}
}while(ch<=5);
}
