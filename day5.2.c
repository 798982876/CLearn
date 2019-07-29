//第五章习题6:求1——20的阶乘和
//求i的阶乘
#include<stdio.h>
#include<stdlib.h>

long long int getfactorial(int i)//求i的阶乘
{   
    long long int r=1;
    for(;i>0;i--)
    {
        r*=i;

    }
    return r;


}

int main()
{
    int start,end;
    long long int sum=0;
    printf("get start,end:");
    scanf("%d,%d",&start,&end);
    for(int i=start;i<=end;i++)
    {
        sum+=getfactorial(i);

    }

    printf("%lld",sum);
    system("pause");
    return 0;

}