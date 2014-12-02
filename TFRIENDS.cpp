// Runtime: 0.90 s
// Strongly Connected Components
// Problem is to find the number of strongly connected components
// Kosaraju's Algorithm
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<stack>
using namespace std;
int countify,n;
vector< vector<int> > graph;
vector< vector<int> > graphrev;
stack<int> st;
int vis[101];
void dfs1(int i)
{
	vis[i] = 1;
	vector<int>::iterator it;
	for(it = graph[i].begin();it!=graph[i].end();it++)
	{
		if(!vis[*it])
			dfs1(*it);
	}
	st.push(i);
}
void dfs2(int i)
{
	vis[i] = 1;
	vector<int>::iterator it;
	for(it = graphrev[i].begin();it!=graphrev[i].end();it++)
	{
		if(!vis[*it])
			dfs2(*it);
	}
}
void kosaraju()
{
	int i;
	memset(vis,0,sizeof vis);
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs1(i);
		}
	}
	memset(vis,0,sizeof vis);
	while(!st.empty())
	{
		int temp = st.top();
		st.pop();
		if(!vis[temp])
		{
			countify++; // Here we increment the number of SCCs
			dfs2(temp);
		}
	}
}
int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--)
	{
		countify = 0;
		scanf("%d",&n);
		char s[n];
		graph.resize(n);
		graphrev.resize(n);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			for(j=0;j<n;j++)
			{
				if(s[j]=='Y')
				{
					graph[i].push_back(j);
					graphrev[j].push_back(i);
				}
			}
		}
		kosaraju();
		/*for(i=0;i<n;i++)
		{
			for(it = graphrev[i].begin();it!=graphrev[i].end();it++)
				printf("%d ",*it);
			printf("\n");
		}*/
		printf("%d\n",countify);
		graph.clear();
		graphrev.clear();
	}
	return 0;
}
