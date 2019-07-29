//第5章习题14:用牛顿迭代法求方程在1.5附近的根
//牛顿迭代法：切线与x轴的交点逼近

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double getnext(double n)//获得Xn+1
{
    double fn=2*pow(n,3)-4*pow(n,2)+3*n-6;
    double dfn=6*pow(n,2)-8*n+3;
    return n-fn/dfn;
}

int main()
{
    double n=1.5;
    do
    {
        n=getnext(n);
    } while (2*pow(n,3)-4*pow(n,2)+3*n-6>0.0001);
    
    printf("%lf",n);
    system("pause");
    return 0;
}