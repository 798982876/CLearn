//第九章习题10:合并链表，并升序
//链表排序

#include<stdio.h>
#include<stdlib.h>

//构造节点
struct student
{
   int no;
   int grade;
   struct student* next;
};

//构造链表,均返回第一个元素的地址
struct student* create(struct student* first,int n)
{
     
    struct student*p=first;
    for(int i=2;i<=n;i++)
    {
       struct student* pn= (struct student*)malloc(sizeof(struct student));
       //连接
       p->next=pn;
       //赋值
       printf("%d:",i);
       scanf("%d,%d",&pn->no,&pn->grade);
       pn->next=NULL;
       //移动
       p=pn;
    }

    return p;

}

//链表排序
void sort(struct student* head,int n)
{
   
}




int main()
{
    int numa=2,numb=3;
    //构建a
    struct student* firsta= (struct student*)malloc(sizeof(struct student));
    printf("1:");
    scanf("%d,%d",&firsta->no,&firsta->grade); 
    struct student*enda=create(firsta,numa);//a的最后一个元素地址
    //构建b
    struct student* firstb= (struct student*)malloc(sizeof(struct student));
    printf("1:");
    scanf("%d,%d",&firstb->no,&firstb->grade); 
    create(firstb,numb);
    //合并a,b
    enda->next=firstb;
    //打印a,
    struct student* p=firsta;
    for(int i=1;i<=numa+numb;i++)
    {
        printf("no:%d",p->no);
        p=p->next;
    }
    //头指针
    struct student* head= (struct student*)malloc(sizeof(struct student));
    head->next=firsta;
    sort(head,numa+numb);

    struct student* p1=firsta;
    for(int i=1;i<=numa+numb;i++)
    {
        printf("\nno:%d",p1->no);
        p1=p1->next;
    }


    system("pause");
    return 0;
    









}





