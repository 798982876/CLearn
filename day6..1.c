//第六章习题4：有一个已排好序的数组，要求输入一个数后，按原来排序的规律将它插入数组中
//数组插入数据

#include<stdio.h>
#include<stdlib.h>

/*数组的传入有问题 */
// int geti(int a[],int x)//升序排序的数组，获得插入的位置
// {
//     for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
//     {
//         if(x<a[i])
//         {
//             return i;
//         }
//     }

// }

// void getr(int a[],int x)//从已知位置插入
// {
//     int poi=geti(a,x);
//     a=(int*)realloc(a,(sizeof(a)/sizeof(a[0])+1)*sizeof(int));//重新分配，长度增加1. 原本空间内的数据不变，只是可用空间增加。
//     for(int i=sizeof(a)/sizeof(a[0])-1;i<poi;i--)
//     {
//         a[i]=a[i-1];
//     }
//     a[poi]=x;
//     for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
//     {
//         printf("%d",a[i]);
//     }

    
// }

int main()
{
    int a[]={2,4,6,8,10};
    int x=9;
    int poi;
    //getr(a,x);
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
    {
        if(x<a[i])
        {
            poi=i;
            break;
        }
    }

    int b[sizeof(a)/sizeof(a[0])+1]={0};
    for(int i=0;i<poi;i++)
    {
        b[i]=a[i];
    }
    for(int i=sizeof(b)/sizeof(b[0]);i>poi;i--)
    {
        b[i]=a[i-1];
    }
    b[poi]=x;
    for(int i=0;i<sizeof(b)/sizeof(b[0]);i++)
    {
        printf("%d",b[i]);
    }

    system("pause");
    return 0;
}