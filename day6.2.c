//第六章习题6:输出杨辉三角形前10行
//第i行j列数据与前一行的关系

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int y[10][10];//10行10列
     for(int i=0;i<10;i++)
     {
        for(int j=0;j<10;j++)
        {
            if(j==0||j==i)
            {
                y[i][j]=1;
            }
            else
            {
                if(i!=0&&i!=1){ 
                   y[i][j]=y[i-1][j-1]+y[i-1][j];
                }
            }
            
        }
   
     }

     for(int i=0;i<10;i++)
     {
         for(int j=0;j<=i;j++)
         {
            
            printf("%d\t",y[i][j]);//输出前i个数

         }
         printf("\n");
     }
     system("pause");
     return 0;



}
