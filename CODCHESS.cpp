// Runtime: 0.00 s
#include<iostream>
#include<stdio.h>
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
int main()
{
	int t;
	int n;
	inp(t);
	while(t--)
	{
		inp(n);
		if(n%2==0) fastWrite(1);
		else fastWrite(0);
	}
	return 0;
}

