//第五章习题5:求Sn=a+aa+aaa+...+a...aa(n个a),其中a为一个数字,n表示位数
//构建第i位数字
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long int geti(int a,int i)//第i位的数
{ 
    long long int sum=0;
    for(int j=0;j<=i;j++)
    {
        sum+=a*pow(10,j);
    }
    return sum;

}

int main()
{
    int a,n;
    long long int sum=0;
    printf("get a,n:");
    scanf("%d,%d",&a,&n);

    for(int i=0;i<n;i++)
    {
        sum+=geti(a,i);

    }

    printf("%lld",sum);
    system("pause");
    return 0;




}