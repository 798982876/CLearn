//第九章习题6：13个人围成一圈，报三删除
//动态链表

#include<stdio.h>
#include<stdlib.h>

//构造节点
struct person
{
    int before;//原始序号
    int count;//应报序号
    struct person* next;//下一节点地址
};

//构造链表，输入第一个人的地址
void create(struct person* p)
{
    struct person* first=p;
    for(int i=2;i<14;i++)
    {
        
        struct person* pn=(struct person*)malloc(sizeof(struct person));//为下一元素的地址分配内存；
        //连接      
        p->next=pn;  
        //赋值     
        pn->before=i;
        pn->count=0;
        if(i==13)
        {
            pn->next=first;
        }
        else{
            pn->next=NULL;
        }
        p=pn;  
    }

}

//链表删除，输入第一个人的地址
void del(struct person* p)
{
    struct person* first=p;
    //检验链表构成
    for(int i=1;i<14;i++)
    {
        printf("%d\n",p->before);
        p=p->next;
    }
    p=first;
    int j=1;
    while(p->next->before!=p->before)
    {
        p->count=j;
        if(j==2)//删除节点，j归0
        {
            struct person* pn;
            pn=p->next;//删除2的下一个节点
            p->next=pn->next;
            printf("delete:%d\n",pn->before);
            free(pn);
            j=0;

        }
        j=j+1;
        p=p->next;
    }
    printf("final:%d",p->before);

}

int main()
{
    //构建第一个节点
    struct person N1={1,0,NULL};
    struct person* p=&N1;
    create(p);
    del(p);
    system("pause");
    return 0;
}
