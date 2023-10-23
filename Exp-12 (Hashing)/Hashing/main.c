#include<stdio.h>
#define MAX 10
void display(int a[MAX])
{
int i,ch;
do
{
printf("1.Display all \n 2.Filtered Display\n");
printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n The hash table is\n");
for(i=0; i<MAX; i++)
printf("\n %d %d ", i, a[i]);
break;
case 2:
printf("\n the hash table is\n");
for(i=0; i<MAX; i++)
if(a[i]!=-1)
{
printf("\n %d %d ", i, a[i]);

}
break;
default:printf("invalid choice\n");
}
}while(ch<=2);
}
int create(int num)
{
int key;
key=num%10;
return key;
}
void linearprob(int a[MAX], int key, int num)
{
int flag=0, i, c=0;
if(a[key]== -1)
a[key] = num;
else
{
printf("\nCollision Detected...!!!\n");
for(i=0;i<MAX;i++)
{
if (a[i]!=-1)
c++;
}
if(c==MAX)
{
printf("hash table is full\n");
return;
}
printf("Collision avoided successfully using LINEAR PROBING\n");
for(i=key+1; i<MAX; i++)
if(a[i] == -1)
{
a[i] = num;
flag =1;
break;
}
i=0;
while((i<key) && (flag==0))
{
if(a[i] == -1)
{
a[i] = num;
flag=1;
break;
}
i++;
}
}
}
void main()
{
int a[MAX],num,key,i;
int ch;
printf(" collision handling by linear probing : \n");
for (i=0;i<MAX;i++)
a[i] = -1;
do
{
printf("\n Enter the value");
scanf("%d", &num);
key=create(num);
linearprob(a,key,num);
printf("\n Do you wish to continue ? (1/0) ");
scanf("%d",&ch);
}while(ch);
display(a);
}
