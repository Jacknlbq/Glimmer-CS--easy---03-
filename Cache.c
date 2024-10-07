//对数组的遍历
#include<stdio.h>
#include<sys/time.h>
int a[10000][10000];
int main()
{
     clock_t start,end;
     double time;
     start=clock();
     for(int i=0;i<=9999;i++)
       for(int j=0;j<=9999;j++)
          a[i][j]=1;//利用了缓存的空间局部性
     end=clock();
     time=(double)(end-start);
     printf("%f\n",time);
     start=clock();
     for(int i=0;i<=9999;i++)
       for(int j=0;j<=9999;j++)
          a[j][i]=1;//没利用缓存的空间局部性
     end=clock();
     time=(double)(end-start);
     printf("%f\n",time);
     return 0;
}