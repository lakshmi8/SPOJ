// Runtime: 0.00 s
// http://ideone.com/iH8yVe
// Topological sort
// O(V+E)
// Using indegree algorithm
// Topological sort
// O(V+E)
// Using indegree algorithm
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
int main()
{
	int n,m,i,j,x,y,z,temp;
	scanf("%d %d",&n,&m);
	int adj[n+1][n+1],indegree[n+1],vis[n+1];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			adj[i][j]=0;
	for(i=1;i<=n;i++)
	{
		indegree[i]=0;
		vis[i]=0;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&x);
		scanf("%d",&y);
		indegree[x]+=y;
		for(j=0;j<y;j++)
		{
			scanf("%d",&z);
			adj[z][x]=1;
		}
	}
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(indegree[i]==0 && !vis[i]) q.push(i);
		while(!q.empty())
		{
			temp=q.front();
			q.pop();
			vis[temp]=1;
			printf("%d ",temp);
			for(j=1;j<=n;j++)
			{
				if(adj[temp][j]==1)
				{
					indegree[j]--;
					if(!indegree[j])
						q.push(j);
				}
			}
		}
	}
	printf("\n");
	return 0;
}
