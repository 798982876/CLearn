//队列：广度优先搜索：农夫过河问题
//安全状态队列；路径存入数组，下标为新状态，变量为前驱状态
//条件列出，让计算机自己顺!!!

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> //bool头文件

//定义队列
struct Queue 
{
    int mSize;//数组大小
    int front;//表头
    int rear;//表尾
    int qu[30];//存队列元素
};

//队列函数
int getFront(struct Queue *Q)//获得队头元素
{
    return Q->qu[Q->front];

}

int deQueue(struct Queue *Q)//获得队头元素并删除、
{
    int e=Q->qu[Q->front];
    Q->front++;
    return e;
}
int enQueue(struct Queue *Q,int e)//添加队尾元素
{
    Q->qu[Q->rear]=e;
    Q->rear++;
    
}
bool isempty(struct Queue *Q)
{
   if(Q->front==Q->rear)
   return true;
   else return false;
}

//确定每个角色位置
bool farmer(int status)
{
    return((status&0x08)!=0);//如果返回结果为真即status&0x08为1，则农夫在目标岸
}
bool wolf(int status)
{
    return((status&0x04)!=0);
} 
bool cabbage(int status)
{
    return((status&0x02)!=0);
}
bool goat(int status)
{
    return((status&0x01)!=0);
}

//安全状态判断
bool safe(int status)
{
    if((goat(status)==cabbage(status))&&goat(status)!=farmer(status)) return false;
    if((wolf(status)==goat(status))&&wolf(status)!=farmer(status)) return false;
    return true;
}

//算法实现
void solve()
{
    int movers,i,location,newlocation;
    int route[16];
    for(int i=0;i<=15;i++)
    {
        route[i]=-1;
    }
    struct  Queue moveTo={16,0,0};
    enQueue(&moveTo,0x00);//添加初始状态
    route[0]=0;
    while(!isempty(&moveTo)&&route[15]==-1)
    {
        int status=deQueue(&moveTo);//得到现在状态,且出队列
        for(movers=1;movers<=8;movers<<=1)//!!!
        {
            if(farmer(status)==(bool)(status&movers))//!!!
            {
                int newstatus=status^(0x08|movers);//!!!
                if(safe(newstatus)&&(route[newstatus]==-1))
                {
                    route[newstatus]=status;
                    enQueue(&moveTo,newstatus);
                }
            }
        }


    }

    if(route[15]!=-1)
    {
        printf("path:");
        for(int status=15;status>=0;status=route[status])
        {
            printf("the status is:%d\n",status);
            if(status==0) break;
        }
    }
    else
    {
        printf("no solution");
    }    
}

int main()
{
    solve();
    system("pause");
    return 0;
}