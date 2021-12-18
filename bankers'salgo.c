#include<stdio.h>
#include<stdlib.h>
//for the process max, allocated, need
struct node
{
  int max[10];
  int allocated[10];
  int need[10]; 
};
int total_process,total_resource;


void input(struct node p[],int ava[])
{
  for(int i=0;i<total_process;i++)
  {
    for(int j=0;j<total_resource;j++)
    {
      scanf("%d",&p[i].max[j]);
    }

    for(int j=0;j<total_resource;j++)
    {
      scanf("%d",&p[i].allocated[j]);
      p[i].need[j]=p[i].max[j]-p[i].allocated[j];

    }
  }


    for(int i=0;i<total_resource;i++)
    {
      scanf("%d",&ava[i]);
    }
}

int Isfun(struct node p[],int ava[],int safe[])
{
   int finish[total_process];
   int work[total_resource];
   for(int i=0;i<total_resource;i++)
   {
     work[i]=ava[i];
   }

   for(int i=0;i<total_process;i++)
   {
     finish[i]=0;
   }

   int proceed=1;
   int k=0;
   while(proceed)
   {
     proceed=0;
     for(int i=0;i<total_process;i++)
     {
       int flag=1;
       if(finish[i]==0)
       {
         for(int j=0;j<total_resource;j++)
         {
           if(p[i].need[j]<=work[j])
           {
             continue;
           }
           else{
             flag=0;
             break;
           }
         }

         if(flag==0)
         {
           continue;
         }
         
           for(int j=0;j<total_resource;j++)
           {
             work[j]=work[j]+p[i].allocated[j];
           }
           finish[i]=1;
           safe[k++]=i;
           proceed=1;
        }
      }
   }

   int i=0;
   while(finish[i]==1)
   {
     i++;
   }

   if(i==total_process)
   {
     return 1;
   }
   else return 0;
}


int check(struct node p[],int ava[],int safe[])
{
  if(Isfun(p,ava,safe)==1)
  {
    return 1;
  }
  else return 0;
}




int main()
{
  scanf("%d",&total_process);
  scanf("%d",&total_resource);
  struct node p[100];
  int avilable[10];
  input(p,avilable);
  int safe[total_process];

  int A=check(p,avilable,safe);
  if(A==1)
  {
    printf("\nsystem is in safe sequence : ");
  }
  else 
  {
    printf("\nnot in safe sequence: ");
  }
  return 0;


}
