// Runtime: 2.22 s
//Binary search
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define ub(v,x) upper_bound(v.begin(),v.end(),x)
#define lb(v,x) lower_bound(v.begin(),v.end(),x)
int main()
{
	int n,count=0,i,j,lb,ub,temp,l,k;
	scanf("%d",&n);
	int a[n],b[n],c[n],d[n];
	vector<int> arr;
	pair<vector<int>::iterator,vector<int>::iterator> p;
	l=0;
	for(i=0;i<n;i++)
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			arr.push_back(a[i]+b[j]);
		}
	}
	sort(arr.begin(),arr.end());
	//using lower_bound and upper_bound
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			temp = -1 * (c[i]+d[j]);
			count+=(ub(arr,temp)-lb(arr,temp));
		}
	}*/
	//using equal_range
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			temp = -1 * (c[i]+d[j]);
			p=equal_range(arr.begin(),arr.end(),temp);
			count+=(p.second-p.first);
		}
	}
	printf("%d\n",count);
	return 0;
}

