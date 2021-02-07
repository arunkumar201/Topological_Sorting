/* **node must be contain  Zero(0)**.
eg. 0 1  //  becouse we are implementing through Adjacency matrix Approach.
if n=5
 0 1
 0 3   [0->1->2
       0->3-4<-0] this is a graph 
 0 4
 1 2
 3 4
 
 */
 #include <stdio.h>
#include<stdlib.h>

#define n 8  //this is number of vertices in a Graph.
int stack[n];
int top=-1;
int v;
int visited[n];
int t=0;

int a[n][n];
int IsEmpty();

void topological_Sorting();
void DFS(int u);
void create_empty();
void print();
void add_edge(int s,int dest);
void push(int u);
int pop();
int main()
{
int s,dest;
    int p,i;
    create_empty();
    printf("\nplease enter number of the pairs of source and destination vertices\n");
    scanf("%d",&p);
     for(i=0;i<p;i++)
       { 
        scanf("%d %d",&s,&dest);  
         add_edge(s,dest);
       }
       print();
       int u;
    for(v=0; v<n; v++)
      visited[v]=0;
    
     printf("enter the starting vertex:");
    scanf("%d",&u);
     // DFS(u,pre,post);
      printf("\n");
      
       for(v=0; v<n; v++)
       {
         if(visited[v]==0)
         {
           DFS(v);
         }
       }

       topological_Sorting();
 

       return 0;
}

void DFS(int u)
{
    if(visited[u]==0)
   {
     //printf("%d",u);
   
      visited[u]=1;
        for(int v=0;v<n;v++)
       {
         if(visited[v]==0 && a[u][v]==1)
         
          DFS(v);
        
         
       }
         push(u);
      
   }
    
       
       
   
  
}

   
    

void create_empty()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            a[i][j]=0;
        }
    }
}
void add_edge(int s,int dest)
{  
   a[s][dest]=1;
}
 void print()
 {
   int i,j;
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
        {
            printf("%d ",a[i][j]);
            
        }
        printf("\n");
    } 
 }
void push(int v)
{
    if(top==(n-1))
    {
        return;
    }
    else
    {
        top++;
        stack[top]=v;
    }
}
int pop()
{
    if(top==-1)
    {
        return 0;
    }
    else
    {
        int a;
      a=stack[top];
       top--;
       return a;
    }
}
void topological_Sorting()
{
 while(!IsEmpty())
  {
    printf("%d ",pop());
  }
}

 int IsEmpty()
{
   if(top==-1)
  return 1;
  else
  return 0;
   
}
/*
Taking input as
9
7 5
5 2
5 4
7 6
6 4 
6 3
3 1
2 1
1 0
*/




