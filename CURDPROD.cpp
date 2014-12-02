// Runtime: 0.38 s
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
using namespace std;
long long int b_search(long long int high,long long int a[],int n,long long int t)
{
	long long int low = 0,mid,val;
	int i;
	while(low<high)
	{
		//cout<<mid<<endl;
		mid = (low+high)/2;
		val = 0;
		for(i = 0; i < n; i++)
		{
			val+= mid/a[i];
		}
		if(val >= t)
			high = mid;
		else
			low = mid+1;
			
	}
	return low;
}
int main()
{
	int t,n,i;
	long long int target,maxi,max_time;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %lld",&n,&target);
		long long int a[n];
		maxi = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%lld",&a[i]);
			maxi = max(maxi,a[i]);
		}
		max_time = maxi*target;
		//cout<<max_time<<endl;
		printf("%lld\n",b_search(max_time,a,n,target));
	}
	return 0;
}


