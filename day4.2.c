//第四章习题11：输入n个整数，要求按从小到大顺序输出
//排序
#include<stdio.h>
#include<stdlib.h>

// void sort(int array[],int n)//array传不进完整的？？？
// {
//     int i,j;
//     //n=len(array);
//     //n=sizeof(array)/sizeof(array[0]);//计算数组长度
    
//     for(i=0;i<n;i++)
//     {   
//         int min=array[i];
        
//         for(j=n-i;j<n;j++)
//         {
//             if(array[j]<min)
//             {
//                 min=array[j];
//                 array[i]=min;
//                 array[j]=array[i];

//             }
//         }
//     }
    
//     for(i=0;i<n;i++)
//     {
//         printf("%d",array[i]);
//     }


// }

int main()
{
    int n;
    int i,j;
   
    
    printf("get num:");
    scanf("%d",&n);
    //int* array=(int*)malloc(sizeof(n)*n);//发生错误？
    int array[n];

    printf("get digit:");
    for(i=0;i<n;i++)
    {
        //array[i]=getchar();//只能get字符！
        printf("num%d:",i);
        scanf("%d",&array[i]);

    }
  
    //sort(array,n);
    for(i=0;i<n;i++)
    {   
        int min=array[i];
        
        for(j=i+1;j<n;j++)
        {
            if(array[j]<min)
            {
                min=array[j];             
                array[j]=array[i];
                array[i]=min;

            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        printf("%d",array[i]);
    }

   
    system("pause");
    return 0;

}
