// Runtime: 0.00 s
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>
#include<string.h>
using namespace std;
int main()
{
	int t,n,k,x;
	int i,j,m,temp,current_wt,current_cost;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		int amount[k+1];
		int packet[k+1];
		pair<int,int> p[k];
		j = 0;
		for(i=1;i<=k;i++)
		{
			scanf("%d",&x);
			if(x!=-1)
			{
				p[j].first = i;
				p[j].second = x;
				j++;
			}
		}
		m = j;
		amount[0] = 0;
		packet[0] = 0;
		for(i=1;i<=k;i++)
		{
			amount[i] = 1000000;
			packet[i] = n;
			for(j=0;j<m;j++)
			{
				current_wt = p[j].first;
				current_cost = p[j].second;
				if(i>=current_wt)
				{
					temp = amount[i-current_wt] + current_cost;
					if(temp<amount[i])
					{
						//amount[i] = temp;
						if(packet[i-current_wt] + 1 <=n)
						{
							amount[i] = temp;
							packet[i] = packet[i-current_wt] + 1;	
						}
					}
				}
				else
					break;
			}
		}
		if(amount[k]!=1000000)
			printf("%d\n",amount[k]);
		else
			printf("-1\n");
	}
	return 0;
}
	
