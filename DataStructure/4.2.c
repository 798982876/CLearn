//中缀表达式转二叉树

#include<stdio.h>
#include<stdlib.h>

//定义node
struct node
{
    struct node* leftchild;
    struct node* rightchild;
    char symbol;
    int  data;
};
struct data
{
    char symbol;
    int  data;

};
//定义栈；存node的地址
struct stack
{
    int Msize;
    int top;
    struct node* st[100];
};

//出栈
struct node* pop(struct stack *S)
{
    if(S->top!=0)//top==0为空
    {
        return(S->st[--S->top]);
    }
    else printf("error");

}
//入栈
void push(struct stack *S,struct node* e)
{
    if(S->top<=S->Msize)
    {
        S->st[S->top++]=e;
    }
    else printf("error");
}
//取栈顶元素
struct node* top(struct stack*S)
{
    return S->st[S->top-1];
}

struct node* tree(char* s)
{
    //两个栈
    struct stack op={100,0};
    struct stack od={100,0};
    //扫描
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>='a'&&s[i]<='z')//数字，入栈
        {
            struct node* e=(struct node*)malloc(sizeof(struct node));
            e->data=0;
            e->symbol=s[i];
            e->leftchild=NULL;
            e->rightchild=NULL;
            push(&od,e);
            if(op.top>=1&&op.st[op.top-1]->symbol=='/')
            {
                struct node* e=pop(&op);
                e->rightchild=pop(&od);
                e->leftchild=pop(&od);
                e->data=e->rightchild->data/e->leftchild->data;
                push(&od,e);
            }
            else if(op.top>=1&&op.st[op.top-1]->symbol=='*')
            {
                struct node* e=pop(&op);
                e->rightchild=pop(&od);
                e->leftchild=pop(&od);
                e->data=e->rightchild->data*e->leftchild->data;
                push(&od,e);
            }
        }
        else if(s[i]=='('||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
            struct node* e=(struct node*)malloc(sizeof(struct node));
            e->data=0;
            e->symbol=s[i];
            e->leftchild=NULL;
            e->rightchild=NULL;
            push(&op,e);

        }
        else if(s[i]==')')
        {
            struct node* a=pop(&op);
            while(a->symbol!=')')
            {
                switch(a->symbol)
                {
                    case'+':
                    {
                        a->rightchild=pop(&od);
                        a->leftchild=pop(&od);
                        a->data=a->rightchild->data+a->leftchild->data;
                        push(&od,a);

                    };break;
                    case'-':
                    {
                        a->rightchild=pop(&od);
                        a->leftchild=pop(&od);
                        a->data=a->rightchild->data-a->leftchild->data;
                        push(&od,a);

                    };break;

                }
                a=pop(&op);
            }
        }

    }
    //扫描完成
    while(op.top>=1)
    {
        struct node* a=pop(&op);
        switch(a->symbol)
        {
            case'+':
            {
                a->rightchild=pop(&od);
                a->leftchild=pop(&od);
                a->data=a->rightchild->data+a->leftchild->data;
                push(&od,a);

            };break;
            case'-':
            {
                a->rightchild=pop(&od);
                a->leftchild=pop(&od);
                a->data=a->rightchild->data-a->leftchild->data;
                push(&od,a);

            };break;

        }
    }
    if(od.top==1)//根节点输出
    {
        return pop(&od);

    }
}

//后根遍历
void postorder(struct node* root,struct data* dat,int n)
{
    if(root->leftchild!=NULL)
    {
        postorder(root->leftchild,dat,n);      
    }
    if(root->rightchild!=NULL)
    {
        postorder(root->rightchild,dat,n);
    }

    printf("%c",root->symbol);
    for(int i=0;i<n;i++)
    {
        if(root->symbol==dat[i].symbol)
        {
            root->data=dat[i].data;
        }
    }
    switch(root->symbol)
    {
        case'+':
           root->data=root->leftchild->data+root->rightchild->data;
           break;
        case'-':
           root->data=root->leftchild->data-root->rightchild->data;
           break;
        case'*':
           root->data=root->leftchild->data*root->rightchild->data;
           break;
        case'/':
           root->data=root->leftchild->data/root->rightchild->data;
           break;
    }

}

void preorder(struct node* root,int n,int r)
{
    
    if(r)
    {
          for(int i=0;i<3;i++)
        {
            printf("%c",' ');
        };
        printf("%c",root->symbol);


    }
    else
    {
         for(int i=0;i<n;i++)
        {
            printf("%c",' ');
        };
        printf("%c",root->symbol);
    }
    
  
    if(root->leftchild!=NULL&&root->rightchild!=NULL)
    {
       

        printf("\n");
        for(int i=0;i<n-1;i++)
        {
            printf("%c",' ');
        };
        printf("/ \\\n");
        preorder(root->leftchild,n-2,0);
        preorder(root->rightchild,n+2,1);//标记右子节点的空格数
    }

    if(root->rightchild!=NULL&&root->leftchild==NULL)
    {
        printf("\n");
        for(int i=0;i<n+1;i++)
        {
            printf("%c",' ');
        };
        printf("\\\n");
        preorder(root->rightchild,n+2,0);
    }
    if(root->rightchild==NULL&&root->leftchild!=NULL)
    {
        printf("\n");
        for(int i=0;i<n-1;i++)
        {
            printf("%c",' ');
        };
        printf("/\n");
         preorder(root->leftchild,n-2,0);
    }

}
int main()
{
    char s[100];
    struct data dat[]={{'a',2},{'b',7},{'c',5}};
    printf("get string:");
    scanf("%s",s);
    struct node* root;
    root=tree(s);//树构建完毕
    //输入数据+后根遍历插入节点数据
    postorder(root,dat,3);
    //前序遍历输出二叉树
    printf("\n");
    preorder(root,3,0);
    printf("\n");
    printf("%d",root->data);
    system("pause");
    return 0;
}