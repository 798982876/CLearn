//图的构建与遍历，深度与广度
//邻接表表示存储结构,顶点以顺序结构存储,有向

#include<stdio.h>
#include<stdlib.h>

//边
struct Edge
{
    int adjvex;//边的终点
    struct Edge* nextarc;//下一条临边
    int info;
};

//顶点
struct VexNode
{
    int data;
    struct Edge* firstarc;
};

//图
struct Graph
{ 
    int vexnum;//顶点数
    int edgenum;//边数
    struct VexNode vexlist[100];//顶点存储空间
    int vexMark[100];//标志位
    int indegree[100];//顶点入度

};
//查找结点在vexlist中的位置
int LocateVex(struct Graph* G,int v)
{
   
    for(int i=0;i<G->vexnum;i++)
    {
        if(G->vexlist[i].data==v)
        {
            return i;
        }
    }
    return -1;
    
};


void CreateDG(struct Graph* G)//构建图
{
    //输入顶点
    for(int i=0;i<G->vexnum;i++)
    {
        printf("\nget %d node:",i+1);
        scanf("%d",&G->vexlist[i].data);
        G->vexlist[i].firstarc=NULL;
        G->vexMark[i]=-1;//标志位为未访问状态
        G->indegree[i]=0;

    }
    //输入边
    for(int i=0;i<G->edgenum;i++)
    {
        int v1,v2;
        printf("\nget %d edge,(v1,v2):",i+1);//起点和终点
        scanf("%d,%d",&v1,&v2);
        int v1_loc=LocateVex(G,v1);
        int v2_loc=LocateVex(G,v2);
        G->indegree[v2_loc]+=1;//计算v2入度
        if(G->vexlist[v1_loc].firstarc==NULL)//插入第一条边
        {
            struct Edge*e=(struct Edge*)malloc(sizeof(struct Edge));
            e->adjvex=v2_loc;//终点位置
            e->info=0;//权重
            e->nextarc=NULL;
            G->vexlist[v1_loc].firstarc=e;

        }
        else//插入其他边
        {
            struct Edge*e=(struct Edge*)malloc(sizeof(struct Edge));
            e->adjvex=v2_loc;//终点位置
            e->info=0;//权重
            e->nextarc=NULL;
            struct Edge*p=G->vexlist[v1_loc].firstarc;
            while(p->nextarc!=NULL)
            {
                p=p->nextarc;
            }
            p->nextarc=e;  
        }
        
    }

}

void visit(struct Graph* G,int v1)
{
    int v1_loc=LocateVex(G,v1);
    G->vexMark[v1_loc]=1;//标记已访问
    printf("vex:%d\n",v1);
}
//深度优先遍历
void DFS(struct Graph* G,int v1)
{
    // visit(G,v1);//访问起始点_值
    int v1_loc=LocateVex(G,v1);
    G->vexMark[v1_loc]=1;//标记已访问
    printf("vex:%d\n",v1);
    struct Edge* e=G->vexlist[v1_loc].firstarc;
    while(e!=NULL)//循环一直到该点没有邻接边
    {
        if(G->vexMark[e->adjvex]==-1)//结点未被访问，从该结点进行递归
        {
            DFS(G,G->vexlist[e->adjvex].data);
        }
        e=e->nextarc;
    }
}

struct Queue//存放结点的队列
{
    int Msize;//大小
    int first;//头
    int rear;//尾
    int vs[100];//位置
};
int deQueue(struct Queue *Q)//出列
{
    if(Q->first==Q->rear)
    {
        printf("error");
    }
    else
    {
        return Q->vs[Q->first++];
    }
}

void inQueue(struct Queue*Q,int v)
{
    if(Q->rear-Q->first>=Q->Msize)
    {
        printf("error");
    }
    else
    {
        Q->vs[Q->rear++]=v;
    }

}


//广度优先遍历
void BFS(struct Graph*G,int v1)
{
    struct Queue Q={100,0,0};
    int v1_loc=LocateVex(G,v1);
    G->vexMark[v1_loc]=1;
    inQueue(&Q,v1_loc);
    while(Q.rear-Q.first!=0)
    {
        int v_loc=deQueue(&Q);//位置
        //访问 
        printf("vex %d",G->vexlist[v_loc].data);
        //将所有未入队的临边都压入队列！！！
        struct Edge*e=G->vexlist[v_loc].firstarc;
        while(e!=NULL)
        {
            if(G->vexMark[e->adjvex]==-1)
            {
                G->vexMark[e->adjvex]=1;
                inQueue(&Q,e->adjvex);
            }
            e=e->nextarc;
        }

    }

}

//拓扑排序法
void TOPS(struct Graph *G,struct Queue *Q)
{
   
    //寻找入度为0的点
    for(int i=0;i<G->vexnum;i++)
    {
        if((G->indegree[i]==0)&&(G->vexMark[i]==-1))//删除此顶点及其所有的出边，若相邻顶点入度减为0则入队
        {
            G->vexMark[i]=1;
            inQueue(Q,i);
            struct Edge *e=G->vexlist[i].firstarc;
            while(e!=NULL)//遍历相邻边
            {
                G->indegree[e->adjvex]-=1;
                // if(G->indegree[e->adjvex]==0&&G->vexMark[e->adjvex]==-1)//与前操作重复
                // {
                //     G->vexMark[e->adjvex]=1;
                //      inQueue(Q,e->adjvex);
                // }
                e=e->nextarc;
            }
        }
    }
    //将Q打印输出
    int h;
    for( h=0;h<G->vexnum;h++)
    {
        if(G->vexMark[h]==-1)
        break;
    }
    if(h==G->vexnum)
    {
        for(int j=0;j<G->vexnum;j++)
        {
            printf("%d\n",G->vexlist[deQueue(Q)].data);
        }
    }
    else
    {
        TOPS(G,Q);
    }

}










int main()
{
    struct Graph G={5,6};
    CreateDG(&G);
    struct Queue Q={100,0,0};
    TOPS(&G,&Q);
    // BFS(&G,5);
    // DFS(&G,0);
    // //从未标记结点中选择结点继续进行DFS,非连通图
    // for(int i=0;i<G.vexnum;i++)
    // {
    //     if(G.vexMark[i]==-1)
    //     {
    //         DFS(&G,G.vexlist[i].data);
    //     }
    // }
    system("pause");
    return 0;

}