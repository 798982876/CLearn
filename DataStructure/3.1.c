//KMP字符串匹配——无回溯匹配
//老师查看学生字符？？？？
//字符串T,模式串P

#include<stdio.h>
#include<stdlib.h>

struct hw//记录学生及作业
{
    int n;
    char w[100];//用到scanf必须是这种形式
};
//获得字符串的长度
int length(char* S)
{
    int i=0;
    while(S[i]!='\0')
    {
        i++;
    }
    return i;
}
//字符串特征向量——非优化版
int* findNext(char* P,int in)//如果in==1则为优化版，如果in==0则不是
{
    int j,k;
    int m=length(P);
    int *next=(int*)malloc(m*sizeof(int));//为next开辟一个数组
    next[0]=-1;
    j=0;
    k=-1;
    while(j<m-1)
    {
        while(k>=0&&P[k]!=P[j])
        {
            k=next[k]; 
        }
        j++;
        k++;
        if(in&&P[k]==P[j])
        {
            next[j]=next[k];
        }
        else
        {
              next[j]=k;
        }
    }
     return next;
}

//KMP模式匹配算法
int KMPStrMatching(char* T,char* P,int *N,int start)
{
    int j=0;
    int i=start;
    int pLen=length(P);
    int tLen=length(T);
    if(tLen-start<pLen)
    {
        return -1;
    }
    while(j<pLen&&i<tLen)
    {
        if(j==-1||T[i]==P[j])
        {
            i++;
            j++;
        }
        else
        {
            j=N[j];

        }  
    }
    if(j>=pLen)//成功
    {
        return i-pLen;
    }
    else return -1;

}

//学生样式与老师模板匹配
int match(char* T,char* P)
{
    //求lenth
    int Tlen=length(T);
    int Plen=length(P);
    char* p=(char*)malloc(Plen*sizeof(char));
    char* t=(char*)malloc(Tlen*sizeof(char));
    int start=0;
    int end=0;
    //找分界线
    for(int i=0;i<Plen;i++)
    {
        if(P[i]=='[')
        {
            start=i;
        }
        else if(P[i]==']')
        {
            end=i;
        }
    }
    //前比较
    for(int i=0;i<start;i++)
    {
        if(P[i]!=T[i])
        return -1;//匹配失败
    }
    //后比较
    for(int i=Plen-1,j=Tlen-1;i>end;i--)
    {
        if(P[i]!=T[j])
        return -1;//匹配失败
    }
    //中间模式比较
    int j=0;
    for(int i=start+1;i<end;i++,j++)
    {
        p[j]=P[i];
    }
    p[j]='\0';
    for(int i=start+1,j=0;i<end;i++,j++)
    {
        t[j]=T[i];
    }
    t[j]='\0';

    return KMPStrMatching(p,t,findNext(t,0),0);
}
int main()
{
   
    int count;//次数
    printf("counts?:");
    scanf("%d",&count);
    struct hw *s=(struct hw *)malloc(count*sizeof(struct hw));//结构体数组
    for(int i=0;i<count;i++)
    {  
        s[i].n=i;
        printf("next:");
        scanf("%s",s[i].w);  
    }
    printf("teacher template?:");
    char P[100];
    scanf("%s",P);
    for(int i=0;i<count;i++)
    {
        int result=match(s[i].w,P);
        if(result!=-1)
        {
            printf("%d  %s",s[i].n,s[i].w);
        }

    }
    system("pause");
    return 0;

}
