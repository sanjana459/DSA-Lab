#include <stdio.h>
#include <conio.h>
#define MAX 30

void stringmatching(char SAT[],char PAT[],char REP[],char FINAL[])
{
    int i,m,j,k,t,found;
    i=m=j=k=t=0, found=0;
    while(SAT[i]!='\0')
    {
        if(SAT[m++]==PAT[j++])
        {
            if(PAT[j]=='\0')
            {
                for(k=0;REP[k]!='\0';k++,t++)
                    FINAL[t]=REP[k];
                j=0;
                i=m;
                found=1;
            }
        }
        else
        {
            FINAL[t++]=SAT[i++];
            j=0;
            i=m;
        }
    }
    FINAL[t]='\0';
    if(found==1)
    {
        printf("the resultant string is: \n");
        puts(FINAL);
    }
    else
      printf("pattern not found");
}

void main()
{
  char SAT[MAX], PAT[MAX],REP[MAX], FINAL[MAX];

  printf("enter the main string:\n");
  gets(SAT);

  printf("enter the patter string:\n");
  gets(PAT);

  printf("enter the replace string:\n");
  gets(REP);

  stringmatching(SAT,PAT,REP,FINAL);
}
