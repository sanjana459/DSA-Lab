#include <stdio.h>
#define MAX 3

int cq[MAX],f=0,r=-1,i,j,c,choice,ele;

void insert()
{
    if(c==MAX)
    {
        printf("cq overflow");
        return;
    }
    printf("enter the value \n");
    scanf("%d",&ele);
    r=(r+1)%MAX;
    cq[r]=ele;
    c++;
}

void delete()
{
    if(c==0)
    {
        printf("cq underflow");
        return;
    }
    printf("element deleted is %d", cq[f]);
    f=(f+1)%MAX;
    c--;
}

void display()
{
    j=f;
    if(c==0)
    {
      printf("cq underflow");
      return;
    }
    printf("contents of the cq are");
    for(i=1;i<=c;i++)
    {
        printf("%d \t",cq[j]);
        j=(j+1)%MAX;
    }
}

void main()
{
    do
    {
        printf("\n1.insert 2.delete 3.display");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
        }
    }while(choice<=3);
}
