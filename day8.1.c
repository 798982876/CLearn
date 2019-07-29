//第八章习题4：n个整数，前面各数顺序向后移动m个位置
//链表插入
#include<stdio.h>
#include<stdlib.h>

//构建节点
struct node
{
    int data;
    struct node* next;
};

struct node* createlist(int n)//构建链表
{
    struct node* head,*first,*p;
    head=(struct node*)malloc(sizeof(struct node));//头指针
    first=(struct node*)malloc(sizeof(struct node));
    head->next=first;
    p=first;
    for(int i=1;i<=n;i++)
    {
        p->data=i;//p为第i个数
        if(i==n)
        {
            p->next=NULL;
        }
        else{
            p->next=(struct node*)malloc(sizeof(struct node));
            p=p->next;
        }
        
    }
    return head;

}

void movelist(struct node* head,int n,int m)//移动
{
    struct node* p=head;
    struct node* n_m;//第n-m个元素的地址
    struct node* first,*end; 
    //找到第n-m个元素,第1个元素，最后一个元素的地址；
    for(int i=1;i<=n;i++)
    {
        p=p->next;//p为第i个元素的地址
        if(i==n-m)
        {
            n_m=p;
        }
        if(i==n)
        {
            end=p;
        }
        if(i==1)
        {
            first=p;
        }
        
    }
    //插入
    head->next=n_m->next;
    end->next=first;
    n_m->next=NULL;

}

int main()
{
    int n=5,m=2;
    
    struct node*head=createlist(n);
    struct node* p=head;
    for(int i=1;i<=n;i++)
    {
        p=p->next;
        printf("%d\n",p->data);

    }   
    movelist(head,n,m);
    p=head;
    printf("next:");
    for(int i=1;i<=n;i++)
    {
        p=p->next;
        printf("%d\n",p->data);

    }

    system("pause");
    return 0;


}