//第一章习题6：输入a,b,c三个值，输出其中最大者
//方法1
#include<stdio.h>//标准输入输出
#include<stdlib.h>//system"pause"

int getmax(int a,int b,int c)//两两依次比较法
{   
    //printf("a,b,c:%d,%d,%d",a,b,c);
    int t;
    if(a>b) {
        t=a;
    }
    else{
        t=b;
    }
    
    
    if(t>c) {
        return t;
    }
    else{
        return c;
    }
}

int main(){
    int a,b,c;
    scanf("%d,%d,%d",&a,&b,&c);
    printf("\n max(a,b,c):%d\n",getmax(a,b,c));
    system("pause");
    return 0;
}