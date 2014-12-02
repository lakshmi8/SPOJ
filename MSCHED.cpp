// Runtime: 0.15 s
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> pi;
bool cmp(const pi &a,const pi &b)
{
	return a.second>b.second;
}
int main()
{
	int n,i,j,max,milk=0;
	scanf("%d",&n);
	pair<int,int> a[n];
	for(i=0;i<n;i++)
		scanf("%d %d",&a[i].first,&a[i].second);
	sort(a,a+n,cmp);
	priority_queue<pi> q;
	max=a[0].second;
	j=0;
	for(i=max;i>=1;i--)
	{
		while(j<n && i<=a[j].second)
		{
			q.push(a[j]);
			j++;
		}
		if(q.size())
		{
			milk+=q.top().first;
			q.pop();
		}
	}
	printf("%d\n",milk);
	return 0;
}
