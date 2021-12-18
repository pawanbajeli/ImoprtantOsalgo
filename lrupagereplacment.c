#include<stdio.h>
#include<stdlib.h>
int arrive[100];
int frame[100];
int f;
int pagefound(int p)
{
    for(int i=0;i<f;i++)
    {
        if(frame[i]==p)
        {
            return 1;
        }
    }
    return 0;
}
int pagelocation(int n)
{
    for(int i=0;i<f;i++)
    {
        if(frame[i]==n)
        {
            return i;
        }
    }
}
int leastused()
{
    int min=0;
    for(int i=1;i<f;i++)
    {
        if(frame[i]<frame[min])
        {
            min=i;
        }
    }

    return min;
}
int main()
{
    int n=0;
    scanf("%d",&n);
    int page[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&page[i]);
    }
    
    scanf("%d",&f);
    for(int i=0;i<f;i++)
    {
        arrive[i]=0;
        frame[i]=-1;
    }
    int cs=0,pf=0;
    int time=0;

    for(int i=0;i<n;i++)
    {
        int y=pagefound(page[i]);
        if(y==0)
        {
            if(cs>=f)
            {   pf++;
                int luin=leastused();
                frame[luin]=page[i];
                arrive[luin]=++time;
            }

            else if(cs<f)
            {   pf++;
                frame[cs]=page[i];
                arrive[cs]=++time;
            }
        }

        else{
            int ldx=pagelocation(page[i]);
            arrive[cs]=++time;
        }
        cs++;
    
    }

    printf("\ntotal page fualt is : %d",pf);
    
}
