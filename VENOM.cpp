// Runtime: 0.38 s
#include<iostream>
#include<stdio.h>
using namespace std;
#define getcx getchar_unlocked
inline void inp( long int &n )//fast input function
{
   n=0;
   long int ch=getcx();long int sign=1;
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
	putchar_unlocked(' ');
}
long int t,h,p,a;
long long int venom,hero;
int temp;
int survive(int x)
{
	int mid,mid1;
	if(x%2==0)
		x-=1;
	mid=x/2;
	mid1=x/2 + 1;
	venom = p*mid1*(mid1+1)/2;
	hero = h + mid*a;
	if(hero>venom) return 1;
	else return 0;
}
void bsearch()
{
	int low=1,high=2827;
	while(low<high)
	{
		int mid=(low+high)/2;
		if(survive(mid)==1)
			low=mid+1;
		else
			high=mid;
		
	}
	fastWrite(low);
}
int main()
{
	inp(t);
	while(t--)
	{
		inp(h);
		inp(p);
		inp(a);
		
		if(h<=p) fastWrite(1);
		else
		{
			bsearch();
		}
	}
	return 0;
}
