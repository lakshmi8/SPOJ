// Runtime: 5.87 s
#include<iostream>
#include<stdio.h>
#define getcx getchar_unlocked
inline void inp( long long int &n )//fast input function
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
	long long int t,n;
	inp(t);
	while(t--)
	{
		inp(n);
		printf("%lld\n",n/3);
	}
	return 0;
}
