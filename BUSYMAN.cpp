// Runtime: 0.87 s
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,countify,i,end;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		pair<long,long> a[n];
		for(i=0;i<n;i++)
		{
			scanf("%ld %ld",&a[i].second,&a[i].first);
		}
		sort(a,a+n);
		countify = 1;
		end = a[0].first;
		for(i=1;i<n;i++)
		{
			if(a[i].second >= end)
			{
				countify++;
				end = a[i].first;
			}
		}
		printf("%d\n",countify);
	}
	return 0;
}
