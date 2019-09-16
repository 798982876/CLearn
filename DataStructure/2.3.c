//利用两个栈s1,s2模拟一个队列
//当进行出队列操作时，先将s1栈中存的元素依次pop,push进s2中，最后从s2中pop出顶层元素

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct stack
{
    int Msize;
    int top;
    int st[100];

};

//定义栈的操作
void push(struct stack *S,int e)//入栈
{
    S->st[S->top]=e;
    S->top++;
}

int pop(struct stack *S)//出栈
{
    int a=S->st[S->top-1];
    S->top--;
    return a;
}

int empty(struct stack *S)//判断
{
    if(S->top==0)
    return 1;
    else return 0;
}

//定义队列的操作
//首先定义栈s1,s2
struct stack s1={100,0};
struct stack s2={100,0};
void enQueue(int e)//入队
{
    push(&s1,e);
}
int deQueue()//出队
{
    while(s1.top!=0)
    {
        push(&s2,pop(&s1));
    }
    if(s1.top==0&&s2.top!=0)
    {
        return pop(&s2);
    }
}
bool isempty()//判断空
{
    if(s1.top==s2.top==0) return true;
    else return false;
}

//测验
int main()
{
    enQueue(2);
    enQueue(5);
    printf("re:%d",deQueue());
    system("pause");
    return 0;
}
