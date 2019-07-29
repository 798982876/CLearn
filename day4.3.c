//第四章习题12：求坐标是否在圆内
//方程，点到圆心的距离<=半径
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int determine(double x,double y,double r)//4个圆心已知
{
    int x1=2,y1=2;
    int x2=-2,y2=2;
    int x3=-2,y3=-2;
    int x4=2,y4=-2;
    
    double t1=pow(x-x1,2)+pow(y-y1,2)-pow(r,2);
    double t2=pow(x-x2,2)+pow(y-y2,2)-pow(r,2);
    double t3=pow(x-x3,2)+pow(y-y3,2)-pow(r,2);
    double t4=pow(x-x4,2)+pow(y-y4,2)-pow(r,2);

    
    if(t1-0.0001||t2-0.0001||t3-0.0001||t4-0.0001)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    

}

int main()
{
    int x,y,r;
    printf("get x, y,r:");
    scanf("%lf,%lf,%lf",&x,&y,&r);
    if(determine(x,y,r)) printf("height is 10\n");
    else printf("height is 0\n");

    system("pause");
    return 0;

}