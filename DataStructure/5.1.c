//二叉搜索树的层次遍历
//无序数组，构造二叉搜索树；层次遍历

#include<stdio.h>
#include<stdlib.h>

struct node//树结点
{
    struct node* leftchild;
    int data;
    struct node* rightchild;
};

struct Queue//用于层次遍历的队列
{
    int mSize;//数组大小
    int front;
    int rear;
    struct node* qu[100];

};

void insert(struct node* root,int e)//插入结点
{  
        if(e>root->data)
        {
            if(root->rightchild!=NULL) insert(root->rightchild,e);
            else 
            {
                struct node* ele=(struct node*)malloc(sizeof(struct node));
                ele->data=e;
                ele->leftchild=NULL;
                ele->rightchild=NULL;
                root->rightchild=ele;
            }
           
        }
        else if(e<root->data)
        {
           if(root->leftchild!=NULL) insert(root->leftchild,e);
            else 
            {
                struct node* ele=(struct node*)malloc(sizeof(struct node));
                ele->data=e;
                ele->leftchild=NULL;
                ele->rightchild=NULL;
                root->leftchild=ele;
            }
        }
        else 
        {
            printf("already have");

        }
}
struct node* BST(int a[],int n)//构建BST
{
        struct node* root=(struct node*)malloc(sizeof(struct node));  //指针不能直接赋值!!!!
        root->data=a[0];
        root->leftchild=NULL;
        root->rightchild=NULL;
        for(int i=1;i<n;i++)
        {
            insert(root,a[i]);
        }  
        return root;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     

}
struct node* deQueue(struct Queue* q)//出队
{
    if(q->rear-q->front)
    {
        return q->qu[q->front++];

    }
    else printf("error");
  
}
void inQueue(struct Queue* q,struct node* e)//入队
{
    if(q->rear-q->front<=q->mSize)
    {
        q->qu[q->rear]=e;
        q->rear++;

    }
    else printf("error");

}

void levelorder(struct node*root)
{
    //盛放结点的队列
    struct Queue q={100,0,0};
    inQueue(&q,root);
    while(q.rear-q.front)
    { 
        root=deQueue(&q);//第一个元素出队先！！
        printf("%d\t",root->data);
        if(root->leftchild!=NULL)
        {
            inQueue(&q,root->leftchild);
        }
        if(root->rightchild!=NULL)
        {
            inQueue(&q,root->rightchild);
        }
        
    }

}

int main()
{
    int a[]={51,45,59,86,45,4,15};
    struct node* root=BST(a,7);//返回构建好的树
    levelorder(root);
    system("pause");
    return 0;
}
