//求数组最大子数组之和
//1，-2，3，10，-4，7，2，-5
//动态规划法：依次把i作为子数组最后一个，若加i为负，则置0继续加，将过程最大的存储

#include<stdio.h>
#include<stdlib.h>

//存最大子数组
struct max{
    int head;
    int tail;
    int sum;
};


struct max getmaxSubarray(int*a,int n)//传入数组和长度,输出最大子数组的特征
{
    struct max maxSubarray={0,0,0};
    //int maxsum=0;
    int head=0;
    int tail=0;
    int sum=0;
    for(int i=0;i<8;i++)
    {
        if(a[i]+sum<0)
        {
            sum=0;
            head=i+1;
            tail=i+1;

        }
        else
        {
            sum=a[i]+sum;
            tail=i;
            if(sum>maxSubarray.sum){
                maxSubarray.head=head;
                maxSubarray.tail=tail;
                maxSubarray.sum=sum;
            }
        }
        
    }
    return maxSubarray;



}

int main()
{
    int a[]={1,-2,3,10,-4,7,2,-5};
    int n=8;
    struct max* p=(struct max*)malloc(sizeof(struct max));
    *p=getmaxSubarray(a,n);
    printf("%d,%d,%d",p->head,p->tail,p->sum);
    system("pause");
    return 0;


}

