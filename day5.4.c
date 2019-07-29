//第五章习题15:二分法求方程在(-10,10)之间的根
//二分法：选中间数

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double getm(double rd,double ld)
{
   return (rd+ld)/2;
}

 double getr(double mid)
 {
    return  2*pow(mid,3)-4*pow(mid,2)+3*mid-6;
 }

int main()
{
    double ld=-10,rd=10;
    double mid=(ld+rd)/2;
    double r;
    
    do
    {
        r=getr(mid);
        if(fabs(r)>0.0001)//不是根
        {
            if(r<0)//右区间
            {
                ld=mid;
                mid=getm(ld,rd);
               
            }
            else //左区间
            {
                rd=mid;
                mid=getm(rd,ld);
                
            }
            r=getr(mid);
        }
        else break;        
    } while (1);
    
    printf("%lf",mid);
    system("pause");
    return 0;


    
}