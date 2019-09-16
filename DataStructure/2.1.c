//中缀表达式求值：利用操作符栈和操作数栈，从左到右扫描中缀表达式
//5+（2+3)*6+4/2
//优先级问题

#include<stdio.h>
#include<stdlib.h>

//定义一个栈
struct Stack
{
    int Msize;
    int top;//栈顶元素
    int st[40];
};
//出栈
int pop(struct Stack* S)
{
    if(S->top>=0)//top==0不存数
    {
        int e=S->st[S->top];
        S->top--;
        return e;
    }
    else
    {
        printf("error");
        return 0;
    }   
}

//栈顶元素
int top(struct Stack* S)
{
    if(S->top>=0)//top==0不存数
    {
        int e=S->st[S->top];
        return e;
    }
    else
    {
        printf("error");
        return 0;
    }  
}

int push(struct Stack* S,int e)
{
    if(S->top<S->Msize-1)
    {
        S->st[S->top+1]=e;
        S->top++;
        return 1;
    }
    else
    {
        printf("error");
        return 0;
    }  
}
int getR(char* s)
{
    printf("%s",s);
    //两个栈
    struct Stack op={40,0};
    struct Stack od={40,0};
    //扫描
    for(int i=0;s[i]!='\0';i++)
    {      
        if(s[i]>='0'&&s[i]<='9')//数字，入栈
        {
            push(&od,s[i]-'0');
            //数据插入成功，判断前一个符号
            if(op.st[op.top]=='*')
            {
                int a=pop(&od)*pop(&od);
                pop(&op);
                push(&od,a);
            }
            else if(op.st[op.top]=='/')
            {
                int a=pop(&od)/pop(&od);
                pop(&op);
                push(&od,a);
            }
        }
        else if(s[i]=='('||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
            push(&op,s[i]);
        }
        else if(s[i]==')')//在括号里则可率先进行加减
        {
            char a=pop(&op);
            while(a!='(')
            {
                switch(a)
                {
                    case '+':
                     {
                        int b=pop(&od)+pop(&od);
                        push(&od,b);
                    };break;
                    case '-':
                     {
                        int b=pop(&od)-pop(&od);
                        push(&od,b);
                    };break;
                    default:printf("none");
                }
                a=pop(&op);
            }
        }
    }
    //扫描完成
    while (op.top>=1)//按顺序加减
    {
        char p=pop(&op);
        switch(p)
                {
                    case '+':
                     {
                        int b=pop(&od)+pop(&od);
                        push(&od,b);
                    };break;
                    case '-':
                     {
                        int b=pop(&od)-pop(&od);
                        push(&od,b);
                    };break;
        }
    }  
   if(od.top==1)//最后结果存储输出
    {
            return pop(&od);
    }
}
int main()
{
    char s[100];
    printf("get string:");
    scanf("%s",s);
    int result;
    result=getR(s);
    printf("%d",result);
    system("pause");
    return 0;
}



