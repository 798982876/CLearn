//第四章习题9：给一个不多于5位数的正整数，求：为几位数；输出每一位数；逆序输出
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//存放每一位数的数组——全局变量
int* array;

int getnum(int data)//获得位数
{
    int i;
    for (i=0;i<=4;i++)
    {   
        
        if(data%(int)pow(10,i)==data)//取余等于本身时
        {
         return  i;
        }
    }
    
}

void getdigit(int data) //逆序存入
{
    int num,i,reversedata;   
    num=getnum(data);
    array=(int*)malloc(sizeof(num)*num);
    for(i=num-1;i>=0;i--)
    {
        array[i]=data/pow(10,i);
        data=data%(int)pow(10,i);
        printf("%d\t",array[i]);
    }
    putchar('\n');
   // printf("逆序输出为:");
    for(i=0;i<num;i++)
     {
         printf("%d\t",array[i]);
     }


}

int main()
{
    int data;
    //printf("输入数据：");
    scanf("%d",&data);
   // printf("位数为:");
    //getnum(data);
    //printf("数字为");
    getdigit(data);

    system("pause");
    return 0;

}
