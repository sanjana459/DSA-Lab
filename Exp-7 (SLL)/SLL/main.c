#include<stdio.h>
#include<malloc.h>
typedef struct node
{
char usn[11];
char name[20];
char sem[10];
char branch[10];
char phno[10];
struct node *link;
}NODE;
NODE *first=NULL;
void create()
{
int i,n;
NODE *nn;
printf("\nenter value of n \n"); // number of nodes in a linked list
scanf("%d",&n);
for(i=1;i<=n;i++)
{
nn=(NODE*) malloc(sizeof(NODE));
printf("Enter Details");
printf("\n enter usn: name: branch: sem: phno");
scanf("%s%s%s%s%s",nn->usn,nn->name,nn->branch,nn->sem,nn->phno);
nn->link=first;
first=nn;
}
}
void insert_front()
{
NODE *nn;
nn=(NODE*)malloc(sizeof(NODE));
printf("\nEnter Details");
printf("\nenter usn: name: branch: sem: phno\n");
scanf("%s%s%s%s%s",nn->usn,nn->name,nn->branch,nn->sem,nn->phno);
nn->link=first;
first=nn;
}
void insert_end()
{
NODE *nn, *PTR;
nn=(NODE*)malloc(sizeof(NODE));
printf("\nEnter Details");
printf("\nenter usn: name: branch: sem: phno\n");
scanf("%s%s%s%s%s",nn->usn,nn->name,nn->branch,nn->sem,nn->phno);
PTR=first;
while(PTR->link!=NULL)
PTR=PTR->link;
PTR->link=nn;
nn->link=NULL;
}
void delete_front()
{
NODE *temp;
if(first==NULL)
{
printf("\nlist is empty");
return;
}
temp=first;
first=first->link;
free(temp);
}
p
void delete_end()
{
NODE *temp, *prev;
if(first==NULL)
{
printf("\nlist is empty");
return;
 }
if(first->link==NULL)
{
first=NULL;
free(temp);
return;
}
prev=NULL;
temp=first;
while(temp->link!=NULL)
{
prev=temp;
temp=temp->link;
}
prev->link=NULL;
free(temp);
}


void display()
{
int c=0;
NODE *temp;
if(first==NULL)
{
printf("\n list is empty");
return;
}
temp=first;
printf("\ncontents are: \n");
while(temp!=NULL)
{
printf("%s\t%s\t%s\t%s\t%s\t\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
temp=temp->link;
c++;
}
printf(" no. of nodes=%d",c);
}
void stack()
{
int ch;
do
{
printf("\n1.push 2.pop 3.display");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:insert_front();
break;
case 2:delete_front();
break;
case 3:display();
break;
default:printf("\n Invalid choice:");
}
}while(ch<=3);
}
void main()
{
int ch;
//clrscr();
do
{
printf("1.create 2.display 3.stack 4.insert front 5.insert end 6.delete front 7.delete end");
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:create();
 break;
case 2:display();
 break;
case 3:stack();
 break;
case 4: insert_front();
 break;
case 5: insert_end();
 break;
case 6: delete_front();
 break;
case 7: delete_end();
 break;
default:printf("\ninvalid choice\n");
}
}while(ch<=7);
}
