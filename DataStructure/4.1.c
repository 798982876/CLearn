//已知中序和后序，求前序
//先构建树

#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node* leftchild;
    int data;
    struct node* rightchild;
};


void tree(struct node* midstart,struct node* midend,struct node* poststart,struct node* postend,int n)
{
    if(n>=0)
    {
        int mdata=postend->data;
        struct node* mpos=midstart;
        for(int i=0;i<n;i++)
        {
            if(mpos->data==mdata){
               break;//获得中心位置
            }
            mpos++;
        }

        if(mpos>midstart)//中心位在起点右侧，则有左孩子
        {
            mpos->leftchild=poststart+(mpos-midstart-1);          
            tree(midstart,mpos-1,poststart,poststart+(mpos-midstart-1),mpos-midstart);
        }
        if(mpos<midend){//中心点在起点左侧，则有右孩子
            mpos->rightchild=postend-1;
            tree(mpos+1,midend,poststart+(mpos-midstart),postend-1,midend-mpos);
        }
    }   
}

void presearch(int rootdata,struct node* mid,int n)
{
   
        //寻找与rootdata相同的节点
        int pos;
        for(int i=0;i<n;i++)
        {
            if(rootdata==mid[i].data){
                pos=i;
            }

        }
        printf("%d",rootdata);
        if(mid[pos].leftchild!=NULL)
        {
            presearch(mid[pos].leftchild->data,mid,n);
            
        }
        if(mid[pos].rightchild!=NULL)
        {
            presearch(mid[pos].rightchild->data,mid,n);
        }
    

}
int main()
{
    struct node mid[]={{NULL,8,NULL},{NULL,12,NULL},{NULL,15,NULL},{NULL,9,NULL},{NULL,5,NULL},{NULL,32,NULL},{NULL,67,NULL}};
    struct node post[]={{NULL,8,NULL},{NULL,15,NULL},{NULL,12,NULL},{NULL,9,NULL},{NULL,32,NULL},{NULL,67,NULL},{NULL,5,NULL}};
    int n=7;
    tree(&mid[0],&mid[n-1],&post[0],&post[n-1],n);//构建树
    //前序遍历
    presearch(post[n-1].data,mid,n);

    system("pause");
    return 0;
    


}