#include <stdio.h>
int a[20],n,i,pos,num,choice;

void create()
{
    printf("enter the size\n");
    scanf("%d",&n);
    printf("enter the elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
}

void display()
{
    printf("array ele are: \n");
    for(i=0;i<n;i++)
    printf("%d \t",a[i]);
}

void insert()
{
    printf("enter the position\n");
    scanf("%d",&pos);
    printf("enter the ele\n");
    scanf("%d",&num);
    if(pos<=0 || pos>(n+1))
    {
         printf("invalid position");
        return;

    }
    for(i=n-1;i>=pos; i--)
        a[i+1]=a[i];
    a[pos-1]=num;
    n++;
}

void delete()
{
    printf("enter the position\n");
    scanf("%d",&pos);
    if(pos<=0 || pos>n)
    {
         printf("invalid position");
         return;

    }
    printf("the elemnt deleted is %d",a[pos-1]);
    for(i=pos-1;i<=n-1;i++)
        a[i]=a[i+1];
    n--;
}

void main()
{
    do{
        printf("1.create 2.display 3.insert 4.delete\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: insert();
                    break;
            case 4: delete();
                    break;
            default: printf("invalid");
        }
    }while(choice<=4);
}
