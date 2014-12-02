// Runtime: 0.05 s
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
#define getcx getchar_unlocked
inline void inp(long long int &n )//fast input function
{
   n=0;
   long long int ch=getcx();long long int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}
int main()
{
	long long int d,t,set,flag;
	long long int n,i,j;
	long long int c,ans;
	inp(d);
	while(d--)
	{
		flag = 0;
		ans = 0;
		set = 0;
		inp(n);
		inp(c);
		inp(t);
		long long int a[n];
		for(i=0;i<n;i++)
			inp(a[i]);
		sort(a+1,a+n,greater<int>());
		//printf("%lld %lld ",a[0],a[1]);
		for(i=1;i<n;i++)
		{
			if(a[i]<=a[0])
			{
				printf("%lld 0\n",a[0]);
				goto end1;
			}
			if(abs(a[i]-a[0])<=c)
				break;
		}
		if(i==n)
		{
			printf("%lld 0\n",a[0]);
			goto end1;
		}
		if(i==1)
		{
			printf("%lld %lld\n",a[i],t);
			goto end1;
		}
		if(abs(a[i]-a[i-1])<=c)
		{
			set = 2;
		}
		else
		{
			flag = 1;
			set = 1;
			goto end;
		}
		j=i-1;
		for(;j>0;)
		{
			if(abs(a[j]-a[j-1])<=c)
			{
				if(abs(a[j-1]-a[i])>c)
				{
					i = j;
					set++;
				}
				j--;
			}
			else break;
		}
		end:;
		if(flag)
			printf("%lld %lld\n",a[i],set*t);
		else
			printf("%lld %lld\n",a[j],set*t);
		end1:;
	}
	return 0;
}
