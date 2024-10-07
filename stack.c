//斐波那契数列
/*#include<stdio.h>
int rabbit(int n)
{
    if(n==0)return 0;
    if(n==1)return 1;
    return rabbit(n-2)+rabbit(n-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",rabbit(n));
    return 0;
}*/
//递归深度过大引起爆栈。
//优化,不用递归
#include<stdio.h>
int main()
{
    int n,a=0,b=1,c;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        c=b;
        b+=a;
        a=c;
    }
    printf("%d",b);
    return 0;
}