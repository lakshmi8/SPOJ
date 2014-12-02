// Runtime: 0.39 s
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int countify[1002][26];
bool cmp(int a,int b)
{
	int i;
	for(i=0;i<26;i++)
	{
		if(countify[a][i] > countify[b][i]) return true;
		if(countify[a][i] < countify[b][i]) return false;
	}
	return a<b;
}
int main()
{
	int t,n,i,j,len,c,ch,cases=0;
	scanf("%d",&t);
	while(t--)
	{
		memset(countify,0,sizeof countify);
		cases++;
		scanf("%d",&n);
		c = getchar();
		string s[n];
		int a[n];
		for(i=0;i<n;i++)
		{
			getline(cin,s[i]);
			a[i]=i;
			for(j=0;j<s[i].length();j++)
			{
				if(s[i][j]!=' ')
				{
					countify[i][tolower(s[i][j])-'a']++;
				}
			}
		}
		sort(a,a+n,cmp);
		printf("case: %d\n",cases);
		for(i=0;i<n;i++)
			cout<<s[a[i]]<<endl;
	}
	return 0;
}
