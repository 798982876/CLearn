//第三章习题6:printf与getchar()组合
#include<stdio.h>
#include<stdlib.h>

int main()
{
     /*法一 */
    char c1,c2,c3,c4,c5;
    c1=getchar()+4;
    c2=getchar()+4;
    c3=getchar()+4;
    c4=getchar()+4;
    c5=getchar()+4;
    printf("%5c,%5c,%5c,%5c,%5c",c1,c2,c3,c4,c5);
    system("pause");
    return 0;
    /*法2 */
    // char c;
    // do
    // {
    //    c=getchar();
    //    printf("%c",c+4);

    // } while (c!='/n');
    
}