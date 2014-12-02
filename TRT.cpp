// Runtime: 0.04 s
// Recursion + Memoization
#include<iostream>
#include<stdio.h>
#include<algorithm>
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
inline void fastWrite(int a)
{
	char snum[20];
	int i=0;
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
int treat[2002][2002];
int n;
int trt(int a[],int start,int end,int age)
{
	if(treat[start][end]) return treat[start][end];
	if(start==end)
	{
		treat[start][end] = a[start]*age;
		return treat[start][end];
	}
	if(start<end && age<=n)
	{
		treat[start][end] = max(a[start]*age + trt(a,start+1,end,age+1) , a[end]*age  + trt(a,start,end-1,age+1));
		return treat[start][end];
	}
}
int main()
{
	int i,ans;
	inp(n);
	int a[n];
	for(i=0;i<n;i++)
		inp(a[i]);
	ans = trt(a,0,n-1,1);
	fastWrite(ans);
	return 0;
}
