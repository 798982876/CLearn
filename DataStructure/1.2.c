//求首尾相连最大子数组之和
//1，-2，3，10，-4，7，2，-5
//动态规划法：依次把i作为子数组最后一个，若加i为负，则置0继续加，将过程最大的存储
//终止条件：以1（首字母）作为i时，前面的加和为0
//连续加不越过本身

#include<stdio.h>
#include<stdlib.h>

struct max{
    struct node* head;
    struct node* tail;
    int sum;
};

struct node
{
    int data;
    struct node* next;

};
//构建首尾相连的链表，单向
struct node *createList(int n)//n为需构建的个数，返回首指针
{
    
    struct node*head=NULL;
    struct node*tail=NULL;
    for(int i=0;i<n;i++)
    {
        
        
        struct node* p=(struct node*)malloc(sizeof(struct node));
        if(i==0){
            head=p;
        }    
        else if(i==n-1)
        {
            tail->next=p;
            p->next=head;//尾指针指向为头
        }
        else
        {
            tail->next=p;
            p->next=NULL;
        }
        tail=p;
        printf("input data:");
        scanf("%d",&(p->data));
        
    }


     return head;

}

//寻找最大子数组
struct max getmaxSubarr(struct node* head,int n)
{
    struct node* h=head;
    struct node* t=head;
    int sum=0;
    int count=0;//相加次数不能大过其本身长度
    struct max maxSubarray={h,t,0};
    int i;
    for(i=0;i<99;i++)
    {
     
       
        if(count>=n)
        {
                break;
        }
       
        if(t->data+sum<0)
        {
            count=0;
            sum=0;
            h=t->next;

        }
        else
        {
            sum=t->data+sum;
            if(sum>maxSubarray.sum){
                maxSubarray.head=h;
                maxSubarray.tail=t;
                maxSubarray.sum=sum;
            }
          
        }
        t=t->next;
        count=count+1;
    }
   
    return maxSubarray;

}

int main()
{
    int n=5;
    struct node* head=createList(n);
    struct max Subarr=getmaxSubarr(head,n);
    printf("%d,%d,%d",Subarr.head->data,Subarr.tail->data,Subarr.sum); 
    system("pause");
    return 0;
}