#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
void die(const char *message)//失败消息处理
{
    if(errno){
        perror(message);   
    }else{
        printf("ERROR:%s\n",message);
    }
    exit(1);
}
typedef int (*compare_cb)(int a,int b);//compare_cb名代表了该该类函数名
int *bubble_sort(int *numbers,int count,compare_cb cmp)//将函数作为参数传入
  {
      int temp=0;
      int i=0;
      int j=0;
      int *target=(int*)malloc(count*sizeof(int));//分配内存名target
      if(!target){
          die("Memory error");
      }
      memcpy(target,numbers,count*sizeof(int));//将numbers里的数据复制到target里
      for(i=0;i<count;i++){
          for(j=0;j<count-1;j++){
              if(cmp(target[j],target[j+1])>0){
                  temp=target[j+1];
                  target[j+1]=target[j];
                  target[j]=temp;
              }
          }
      }
      return target;

  }
  int sorted_order(int a,int b){
      return a-b;
  }

  int reverse_order(int a,int b)
  {
      return b-a;
  }

  int strange_order(int a,int b){
      if(a==0||b==0){
          return 0;

      }else{
          return a%b;
      }
  }
  
void test_sorting(int *numbers,int count,compare_cb cmp)
{
    int i=0;
    int *sorted=bubble_sort(numbers,count,cmp);//返回排序好的数据的内存地址
    if(!sorted)
    {
        die("failed to sort as requested");
    }
    for(i=0;i<count;i++)
    {
        printf("%d\n",sorted[i]);
    }
    printf("\n");
    free(sorted);//释放内存
}


int main(int argc,char*argv[]){
   
    int count = 10;
    int i=0;
    char* ar[]={"nihaoyaaaa","haihujieds","mei"};
    char* inputs=&ar[1][0];
    int *numbers=(int*)malloc(count*sizeof(int));
    if(!numbers){
        die("memory error");
    }
    for(i=0;i<count;i++){
        char p=*(inputs+i);
        *(numbers+i)=int(p);
    }
    test_sorting(numbers,count,sorted_order);
    test_sorting(numbers,count,reverse_order);
    test_sorting(numbers,count,strange_order);

    free(numbers);


   
    system("pause");
    return 0;
}