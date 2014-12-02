// Runtime: 0.11 s
// Strongly connected components
// Tarjan
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
using namespace std;
vector< vector<int> > graph;
vector<int> result;
stack<int> s;
map<int,int> ans;
int stackify[100000];
int lowlink[100000];
int disc[100000];
int time1 = 0;
int n,m;
#define getcx getchar_unlocked
inline void inp( int &n )//fast input function
{
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}
inline void fastWrite(int a)
{
	char snum[20];
	int i=0;
	do
	{
		snum[i++]=a%10+48;
		a=a/10;
	}while(a!=0);
	i=i-1;
	while(i>=0)
	putchar_unlocked(snum[i--]);
	putchar_unlocked('\n');
}
void dfs1(int u)
{
	int v;
	++time1;
	lowlink[u] = disc[u] = time1;
	s.push(u);
	stackify[u] = 1;
	vector<int>::iterator it;
	for(it = graph[u].begin();it!=graph[u].end();it++)
	{
		v = *it;
		if(!disc[v])
		{
			dfs1(v);
			lowlink[u] = min(lowlink[u],lowlink[v]);	
		}
		else if(stackify[v])
		{
			lowlink[u] = min(lowlink[u],disc[v]);
		}
	}
	if(lowlink[u] == disc[u])
	{
		int temp;
		result.clear();
		while(s.top() != u)
		{
			temp = s.top();
			stackify[temp] = 0;
			s.pop();
			result.push_back(temp);
		}
		temp = s.top();
		stackify[temp] = 0;
		s.pop();
		result.push_back(temp);
		vector<int>::iterator it;
		int min = 10000;
		for(it=result.begin();it!=result.end();it++)
		{
			if(*it<min) min = *it;
		}
		for(it=result.begin();it!=result.end();it++)
		{
			ans[*it] = min;
		}
	}
}
void tarjan()
{
	int i;
	for(i=0;i<n;i++)
	{
		if(!disc[i])
			dfs1(i);
	}
}
int main()
{
	int i,a,b;
	inp(n);
	inp(m);
	graph.resize(n);
	for(i=0;i<m;i++)
	{
		inp(a);
		inp(b);
		graph[a].push_back(b);
	}
	tarjan();
	for(i=0;i<n;i++)
	{
		fastWrite(ans[i]);
	}
	graph.clear();
	return 0;
}

