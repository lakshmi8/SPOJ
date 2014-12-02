// Runtime: 1.85 s
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define c 1000000007
unsigned long long int fastpow(unsigned long long int a,unsigned long long int b)
{
	unsigned long long int halfpow;
	if(b==0) return 1;
	halfpow = fastpow(a,b/2);
	halfpow = (halfpow * halfpow) % c;
	if(b%2) halfpow = (halfpow * a) % c;
	return halfpow;
}
int main()
{
	unsigned long long int n,ans;
	while(scanf("%llu",&n)!=EOF)
	{
		ans = fastpow(2,n) ;
		//printf("%llu\n",ans);
		if(n%2==0) ans += 2;
		else ans+=1;
		ans = (ans*333333336)%c;
		printf("%llu\n",ans);
	}
	return 0;
}
