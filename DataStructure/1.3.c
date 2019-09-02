//字符串插入
//两字符串str,substr构成要素为大小写字母和数字,将substr插入str中ASCII码最大的字符后面
//语句输入格式为str substr
//考察C语言字符串的处理
#include<stdio.h>
#include<stdlib.h>

void insert(char* str,char* substr)
{
    printf("%s,%s",str,substr);
    //遍历str找寻字母最大的，并计算str长度
    int max=0;
    int p=0;
    int i,j;
    for( i=0;str[i]!='\0';i++)
    {
        if(str[i]>max) 
        {
            max=str[i];
            p=i;
        }
    }
    printf("i:%d",i);
    //在p位置后插入substr
    for(j=0;substr[j]!='\0';j++)
    {}
    printf("j:%d",j);
    int g=0;
    for(int m=i;m>p;m--)//从\0开始搬！！！
    {
        str[m+j]=str[m];
        str[m]=substr[g++];
    }

    printf("%s",str);
 



}

int main()
{
    char str[20],substr[40];//字符串就这样存储！！！！
    printf("input:");
    scanf("%s %s",str,substr);
   
    insert(str,substr);
    // char* combine=

    system("pause");
    return 0;
}

