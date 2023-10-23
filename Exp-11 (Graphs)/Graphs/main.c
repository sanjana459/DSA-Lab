#include<stdio.h>
int a[20][20],q[20],visited[20],n,i,j,f=-1,r=-1;
void create()
{

    printf("\nEnter the number of vertices:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        q[i]=0;
        visited[i]=0;
    }
    printf("Enter graph data in matrix form:\n");
    for (i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
}

void bfs(int v)
{
    for(i=0;i<n;i++)
    {
        visited[i]=0;
        q[i]=0;
    }
    visited[v]=1;
    q[++r]=v;
    while(f!=r)
    {
        v=q[++f];
        printf("%d\n",v);
        for(i=0;i<n;i++)
        {
            if(a[v][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                q[++r]=i;
            }
        }
    }
}

void main()
{
    int v,ch;
    do
    {
        printf("\n1:Create graph  2:BFS");
        printf("\nEnter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
            break;
            case 2:printf("Enter the starting vertex: ");
                   scanf("%d",&v);
                   printf("The nodes which are reached from %d are: \n",v);
                   bfs(v);
                   break;
           default: printf("Invalid choice\n");
        }
    }while(ch<=2);
}
