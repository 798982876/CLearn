//第九章习题1：已知年月日求该日为该年的第多少天
//定义结构体、判断闰年

#include<stdio.h>
#include<stdlib.h>

//定义年月日结构体
struct Date
{
    int year;
    int month;
    int day;
};
//计算天数
int getdays(struct Date mydate)
{
    int n=0,fore=0;
    //判断闰年
    if(mydate.year%4==0) fore=1;
    //判断月份计算天数
    switch (mydate.month)
    {
    case 1:
        n=mydate.day;
        break;
    case 2:
        n=31+mydate.day+fore;
        break;
    case 3:
        n=31+28+mydate.day+fore;
        break;
    case 4:
        n=31+28+31+fore+mydate.day;
        break;
    case 5:
        n=31+28+31+30+fore+mydate.day;
        break;
    case 6:
        n=31+28+31+30+31+fore+mydate.day;
        break;
    case 7:
        n=31+28+31+30+31+30+fore+mydate.day;
        break;
    case 8:
        n=31+28+31+30+31+30+31+fore+mydate.day;
        break;
    case 9:
        n=31+28+31+30+31+30+31+31+fore+mydate.day;
        break;
    case 10:
        n=31+28+31+30+31+30+31+31+30+fore+mydate.day;
        break;
    case 11:
        n=31+28+31+30+31+30+31+31+30+31+fore+mydate.day;
        break;
    case 12:
        n=31+28+31+30+31+30+31+31+30+31+30+fore+mydate.day;
        break;
    
    default:
        break;
    }
    return n;

}

int main()
{
    int n;
    //定义一个日期
    struct Date mydate;
    //获得日期
    scanf("%d,%d,%d",&mydate.year,&mydate.month,&mydate.day);
    n=getdays(mydate);
    printf("%d",n);
    system("pause");
    return 0;



}


