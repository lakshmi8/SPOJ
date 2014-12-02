// Runtime: 0.00 s
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,i;
	long long count;
	scanf("%d",&t);
	while(t--)
	{
		count=1;
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		for(i=0;i<n;i++)
		{
			count= (count*(a[i]-i)) % 1000000007;
		}
		printf("%lld\n",count);
	}
	printf("KILL BATMAN");
	return 0;
}
