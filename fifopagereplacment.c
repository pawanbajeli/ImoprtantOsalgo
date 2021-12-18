#include<stdio.h>
int main()
{
    int page_size=0;
    int frame_size=0;
    scanf("%d",&frame_size);
    scanf("%d",&page_size);
    int fram[frame_size];
    int page[page_size];
    for(int i=0;i<frame_size;i++)
    {
        fram[i]=-1;
    }
    for(int i=0;i<page_size;i++)
    {
        scanf("%d",&page[i]);
    }
    int pf=0;
    int flag=0;
  int po=-1;
  int page_hit=0;

    for(int i=0;i<page_size;i++)
    {
        for(int j=0;j<frame_size;j++)
        {
            if(fram[j]==page[i])
            {
                flag=1;
                page_hit++;
                break;
            }   
        }
        if(flag==0)
        {
           if(po==frame_size)
           {
               po=-1;
           }
           po++;
           pf++;
           fram[po]=page[i];
        }

        flag=0;

    }
    printf("\nthe total page_fualt is %d",pf);
    printf("\ntotal page hit is %d",page_hit);
    return 0;




}
