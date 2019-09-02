//求数组最大子数组之和
//1，-2，3，10，-4，7，2，-5
//分治法

#include<stdio.h>
#include<stdlib.h>

//求数组的左右两个子集，若子集一侧含有负数则返回该数组，否则继续，直至数组长度为1

//定义popleft与popright操作，操作返回pop后的数组
int* popleft(int*a,int n)
{
    int *b=(int*)malloc(sizeof(int)*(n-1));
    for(int i=0;i<n-1;i++)
    {
        b[i]=a[i+1];
    }
    return b;
}
int* popright(int*a,int n)
{
    int *b=(int*)malloc(sizeof(int)*(n-1));
    for(int i=0;i<n-1;i++)
    {
        b[i]=a[i];
    }
    return b;
}

//数组求和
int sum(int*a,int n)
{
    int s=0;
    for(int i=0;i<n;i++)
    {
        s+=a[i];

    }
    return s;
}
 //递归算法
 int *getmax(int *a,int n,int sumleft,int sumright)
 {
   
    // int *b=(int*)malloc(sizeof(n)*(n-1));
    // int *c=(int*)malloc(sizeof(n)*(n-1));
    int *b=popleft(a,n);
    //printf("%d\n",b[n-2]);
    int *c=popright(a,n);
    printf("left:%d\nright:%d\n*******\n",sumleft,sumright);

    if(n>0&&c[0]+sumleft<0)
    {
         getmax(b,n-1,sumleft+b[0],sumright);
    }

     if(n>0&&c[n-1]+sumright<0)
    {
       
         getmax(c,n-1,sumleft,sumright+c[n-1]);
    }

    
    if(n==0||(sumleft>0&&sumright>0)  )  
    {
         //printf("%d",n);
        for(int i=0;i<n;i++)
        {
              printf("%d\t",a[i]);

        }
        printf("\n*********");
        //return a;

    }
   
 
    
 }


int main()
{
    int a[]={1,-2,3,10,-4,7,2,-5};
    int n=8;
    

    getmax(a,8,1,-5);

    system("pause");

}
