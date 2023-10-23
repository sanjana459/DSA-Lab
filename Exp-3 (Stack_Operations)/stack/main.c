#include <stdio.h>
#define MAX 5

int s[MAX],top=-1,ele,i, choice;

void palindrome()
{
  top=-1;
  int i=1, len=0, rev=0, digit, temp, n;
  printf("enter a number");
  scanf("%d",&n);

  temp=n;
  while(n!=0)
  {
      digit=n%10;
      n=n/10;
      push(digit);
      len++;
  }
  while(len!=0)
  {
      digit=pop();
      rev=rev+(digit*i);
      len--;
      i=i*10;
  }
  if(temp==rev)
  printf("the num is palindrome");
  else
  printf("the number is not a palindrome");
  }

void push(int ele)
{
    if(top==MAX-1)
    {
        printf("stack overflow");
        return;
    }
    top++;
    s[top]=ele;
}

int pop()
{
    if(top==-1)
    {
        printf("stack underflow");
        return;
    }
    ele=s[top];        //order matters
    top--;
    return ele;
}

void display()
{

    if(top==-1)
    {
        printf("stack underflow");
        return;
    }
    else
    {
        printf("The contents of the stack are\n");
        for(i=top;i>=0;i--)
            printf("%d\t",s[i]);
    }
}

void main()
{
    do
    {
      printf("1.push 2.pop 3.display 4.palindrome 5.exit");
      printf("enter your choice");
      scanf("%d",&choice);
      switch(choice)
      {
          case 1: printf("enter the element to be inserted:\n");
                  scanf("%d",&ele);
                  push(ele);
                  break;
          case 2: ele=pop();
                  printf("element delete is %d", ele);
                  break;
          case 3: display();
                  break;
          case 4: palindrome();
                  break;
          case 5: return;
          default: printf("invalid choice");
      }
    }while(choice<=5);
}
