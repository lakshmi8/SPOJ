// Runtime: 0.00 s
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,m; // the number of cities and the number of roads
	int a,b,c; // for getting the roads input
	int s; // number of stores
	int b1,b2; // boy1 and boy2
	int i,j,k; // indices
	int permut;
	int temp,cost,mini;
	int fact[]={1,2,6,24,120,720,5040,40320}; // worst case permutation is 8! . Precomputing the factorials :)
	scanf("%d %d",&n,&m);
	int dist[n][n];
	//memset the array
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j) dist[i][j]=0;
			else dist[i][j]=100000000;
		}
	}
	//getting the input length of m roads
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		dist[a][b]=dist[b][a]=c;
	}
	// Floyd Warshall to find the shortest distances between all pairs of vertices
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	scanf("%d",&s);
	int store[s];
	//get stores input
	for(i=0;i<s;i++)
	{
		scanf("%d",&store[i]);
	}
	
	scanf("%d %d",&b1,&b2); // boy's initial positions
	
	
	permut = fact[s-1]; // no.of.permutations to be done
	temp=permut;
	mini = 1000000000;
	
	// Brute force implementation of finding the minimum distance
	// Using next_permutation to make sure that we include all possible orders in which the stores are visited
	
	sort(store,store+s);
	while(permut--)
	{
		if(permut!=temp-1)
			next_permutation(store,store+s);
		//first boy travels to all stores
		cost = dist[b1][store[0]];
		for(i=1;i<s;i++)
		{
			cost += dist[store[i-1]][store[i]];
		}
		mini = min(mini,cost);
		
		//second boy travels to all stores
		cost = dist[b2][store[0]];
		for(i=1;i<s;i++)
		{
			cost += dist[store[i-1]][store[i]];
		}
		mini = min(mini,cost);
		
		// combined traversal
		for(i=0;i<s-1;i++)
		{
			cost = dist[b1][store[0]];
			for(j=1;j<i+1;j++)
			{
				cost+=dist[store[j-1]][store[j]];
			}
			
			cost+= dist[b2][store[s-1]];
			for(j=s-1;j>i+1;j--)
			{
				cost+=dist[store[j]][store[j-1]];
			}
			mini = min(mini,cost);
		}
	}
	
	printf("%d\n",mini); 
	return 0;
}
