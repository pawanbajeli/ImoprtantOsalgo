#include<stdio.h>
#include<stdlib.h>
struct node
{
   int pid;
   int at;
   int bt;
   int ct,wt,tat,start_time,rt;
};
int comp(const void *a, const void *b)
{
    int x=((struct node *)a)->at;
    int y=((struct node *)b)->at;

    if(x<y)
    {
        return -1;
    }
    else
          return 1;
}
int maxof(int x,int y)
{
    return x>y?x:y;
}
int main()
{
    int n=0;
    scanf("%d",&n);
    struct node p[n];
    //arrival time
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i].at);
        p[i].pid=i+1;
    }


    //burst time
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i].bt);
        
    }

    //as it is solve the problem using the concept of first arriaval time
    qsort((void *)p,n,sizeof(struct node),comp);

    //calculation for the outputs
    int avg_tat=0;
    int avgwt=0;
    int avgrt=0;
    for(int i=0;i<n;i++)
    {
        p[i].start_time=(i==0)?(p[i].at):maxof(p[i].at,p[i-1].ct);
        p[i].ct=p[i].start_time+p[i].bt;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        p[i].rt=p[i].wt;

        avg_tat+=p[i].tat;
        avgwt+=p[i].wt;
        avgrt+=p[i].rt;
    }


    printf("\nthe avg turn around time: %.2f",(float)avg_tat/(float)n);

    printf("\nthe avg waiting  time: %.2f",(float)avgwt/(float)n);

    printf("\nthe avg responce time: %.2f",(float)avgrt/(float)n);

    
    return 0;

}
