// Runtime: 0.00 s
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int t,k,n,i,count,temp,j;
	scanf("%d",&t);
	while(t--)
	{
		count=1;
		scanf("%d%d",&n,&k);
		char a[n],te;
		scanf("%s",a);
		if(n==k)
			printf("%s\n",a);
		else
		{
			temp=n;
			j=0;
			while(temp!=k)
			{
				if(count%2)
				{
					for(i=j;i<n;i++)
					{
						if(a[i]=='1')
						{
							te=a[i];
							a[i]=a[j];
							a[j]=te;
							j++;
							break;
						}
					}
					if(i==n) j++;
				}
				else
				{
					for(i=j;i<n;i++)
					{
						if(a[i]=='0')
						{
							te=a[i];
							a[i]=a[j];
							a[j]=te;
							j++;
							break;
						}
					}
					//cout<<"In";
					if(i==n) j++;
				}
				count++;
				temp--;
			}
			//cout<<j;
			for(i=j;i<n;i++)
				printf("%c",a[i]);
			printf("\n");
		}
	}
	return 0;
}
