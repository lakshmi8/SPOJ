// Runtime: 0.09 s
#include<iostream>
#include<stdio.h>
#include<math.h>
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
	long long int n,i,count=0;
	inp(n);
	for(i=1;i<=sqrt(n);i++)
	{
		if(n%i==0) count+=2;
		if(i*i==n) count--;
		if(count>4) break;
	}
	if(count==3 || count==4) printf("MARIAN\n");
	else printf("ANNE\n");
	return 0;
}

