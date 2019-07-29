//第八章习题9:3x3矩阵倒置
//二维数组

#include<stdio.h>
#include<stdlib.h>

int main()
{
    //二维矩阵
    int M[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int temp;
    for(int i=0;i<3;i++)
    {
        for(int j=i+1;j<3;j++)
        {
            temp=M[i][j];
            M[i][j]=M[j][i];
            M[j][i]=temp;

        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d",M[i][j]);
        }
        printf("\n******\n");
    }

    system("pause");
    return 0;
}