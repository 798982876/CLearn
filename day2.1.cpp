//第二章习题4.7:求两个数m和n的最大公约数
//依次带入
#include<stdio.h>
#include<stdlib.h>

int getconv(int m,int n)
{
   int min,x,i;
   if(m>n){//最小值
       min=n;
   }
   else{
       min=m;
   }

    for(i=min/2;i>0;i--)//范围从最小值的1/2开始
    {
        if(m%i==0 and n%i==0){
            return i;
        }
    }


}

int main()
{
    int m,n;
    scanf("%d,%d",&m,&n);
    printf("get the number of conventions:%d",getconv(m,n));
    system("pause");
    return 0;
    

}