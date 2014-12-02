#include<iostream>
#include<stdio.h>
using namespace std;
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
	int t,n,i;
	long long int sum,temp,prev;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		long long int a[n];
		sum=0;
		prev=0;
		inp(a[0]);
		for(i=1;i<n;i++)
		{
			inp(a[i]);
			temp=prev+ i*(a[i]-a[i-1]);
			prev=temp;
			sum+=temp;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
			
		
