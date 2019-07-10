//第一章习题6：输入a,b,c三个值，输出其中最大者
//方法2
#include<stdio.h>//标准输入输出
#include<stdlib.h>//system"pause"

int getmax(int x,int y,int z)
{
    if(x>y and x>z)
    {
        return x;
    }
    else{
        return 0;
    }
}

int main()
{
    int a,b,c,i,j,max;
    scanf("%d,%d,%d",&a,&b,&c);
    int array[3]={a,b,c};
    for (i=0;i<3;i++){
        int arr[2]={};
    
        for (j=0;j<2;j++){//获得删除原数据后的数组
            if(j<i){
                arr[j]=array[j];
            }
            else {
                arr[j]=array[j+1];//跳过原数据
            }
            
        }

        if(getmax(array[i],arr[0],arr[1])!=0)
        {
            printf("max(a,b,c):%d",getmax(array[i],arr[0],arr[1]));
            break;
        }
        

    }
     system("pause");
     return 0;

}