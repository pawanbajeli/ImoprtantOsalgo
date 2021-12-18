#include<stdio.h>
#include<stdlib.h>
struct node
{
    int r;
};


int comp(const void *a,const void *b)
{
    int x=((struct node *)a)->r;
    int y=((struct node *)b)->r;
    if(x>y)
    {
        return 1;

    }
    else return -1;
}


int main()
{
    int num_r;
    scanf("%d",&num_r);
    struct node p[num_r];
    for(int i=0;i<num_r;i++)
    {
        scanf("%d",&p[i].r);
    }
    qsort((void*)p,num_r,sizeof(struct node),comp);
    int mini=p[0].r;
    printf("\n");
    for(int i=0;i<num_r;i++)
    {
        printf("%d ",p[i].r);
    }
    printf("\nthe mini is at %d\n",mini );
    
    int head=0;
    scanf("\n%d",&head);
    int disk_size=0;
    scanf("\n%d",&disk_size);
    printf("\n the head is at: %d",head);
    printf("\n the disk size is %d",disk_size);
    int ans=0;
    ans=(disk_size-head-1)+(disk_size-mini-1);
    printf("\n%d",ans);

}
