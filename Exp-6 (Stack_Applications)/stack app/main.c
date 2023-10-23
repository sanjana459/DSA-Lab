#include <stdio.h>
#include <math.h>

int op1, op2, res, i, top=-1; s[10], ele, n;


void push(int ele)
{
    top++;
    s[top]=ele;
}

int pop()
{
    ele=s[top];
    top--;
    return ele;
}

void eval()
{
    char postfix[20], ch;
    int e;

    printf("enter the postfix exp:");
    scanf("%s", postfix);

    for(i=0;postfix[i]!='\0';i++)
    {
        ch=postfix[i];
        if(isdigit(ch))
            push(ch-'0');
        else
        {
            op2=pop();
            op1=pop();
            switch(ch)
            {
                case '+': res= op1+op2;
                          break;
                case '-': res= op1-op2;
                          break;
                case '*': res= op1*op2;
                          break;
                case '/': res= op1/op2;
                          break;
                case '^': res= pow(op1,op2);
                          break;
            }
            push(res);
        }
    }
    printf("result:%d",res);
}

void tow(int n, char s, char t, char d)
{
    if(n==1)
    {
        printf("move disc 1 from %c to %c\n", s,d);
        return;
    }
    tow(n-1,s,d,t);
    printf("move disc %d from %c to %c\n", n,s,d);
    tow(n-1,t,s,d);
}

void main()
{
    int ch,n;
    char s='s',t='t',d='d';
    do
    {
        printf("\n1.postfix 2.tower of hanoi\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: eval();
                    break;
            case 2: printf("enter num of disks\n");
                    scanf("%d",&n);
                    tow(n,s,t,d);
                    break;
        }
    }while(ch<=2);
}
