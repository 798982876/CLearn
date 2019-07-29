//第五章习题12:猴子吃桃问题。猴子每天早上剩下的一半多一个，第十天早上只剩一个，求第一天共摘了多少个
//正向：共x个，经过9次迭代只剩1个，求x——给范围带入求解
//反向：当天剩的个数为前一天剩的个数加一乘以2，从第九天开始往前算到第0天的剩余即第一天的所摘

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int getpro(int remaining)//求前一天一开始的总量
{
   return (remaining+1)*2;

}

int reverse()//反向求解
{

    int remaining=1;
    for(int i=10;i>=1;i--)//第10天早上的总量到第一天早上的总量即摘量
    {
        remaining=getpro(remaining);
    }
    return remaining;

}

int verify(int x)//正向验证
{
    for(int i=1;i<=10;i++)
    {
        x=x-0.5*x-1;

    }
    return x;

}



int main()
{
    int sum=reverse();
    printf("%d",sum);
    int r=verify(sum);
    printf("\n%d",r);
    system("pause");
    return 0;
}