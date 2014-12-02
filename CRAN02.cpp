// Runtime: 1.61 s
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;
#define getcx getchar_unlocked
inline void inp(int &n )//fast input function
{
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}
inline void fastWrite(long long int a)
{
	char snum[20];
	long long int i=0;
	do
	{
		snum[i++]=a%10+48;
		a=a/10;
	}while(a!=0);
	i=i-1;
	while(i>=0)
	putchar_unlocked(snum[i--]);
	putchar_unlocked('\n');
}
int main()
{
	int t,n,i,x,sum;
	long long int count;
	inp(t);
	while(t--)
	{
		count=0;
		sum=0;
		inp(n);
		map<int,int> m;
		m[0]=1;
		for(i=0;i<n;i++)
		{
			inp(x);
			sum+=x;
			count+=m[sum];
			m[sum]+=1;
		}
		fastWrite(count);
	}
	return 0;
}
