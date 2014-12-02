// Runtime: 0.00 s
#include<iostream>
#include<stdio.h>
using namespace std;
int search(int low,int high,int n,int k,int a[])
{
    int res,sum,prev,i,j,count;
    while(low<high)
    {
    	count=1;
    	prev=low;
    	sum=0;
    	//sum=a[0];
    	//prev-=a[0];
    	for(i=0;i<n;i++)
    	{
    		if(count<=k)
    		{
    			if(prev>=a[i])
    			{
    				prev-=a[i];
    				sum+=a[i];
    			}
    			else
    			{
    				count++;
    				prev=low;
    				if(count<=k)
					{
    					prev-=a[i];
    					sum+=a[i];
    				}
    				else
    					break;
				}	
 			}	
 		}
 
    	if(sum==high)
    	{
    		//cout<<count<<endl;
    		return low;
    	}
    	else
    		low++;
    }
    //cout<<count;
    return low;
}
int main()
{
    int t,n,k,i,min,max,ans;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%d%d",&n,&k);
    	min=0;
    	max=0;
    	int a[n];
    	for(i=0;i<n;i++)
   		{
    		scanf("%d",&a[i]);
    		if(min<a[i])
    			min=a[i];
    		max+=a[i];
    	}
    	ans=search(min,max,n,k,a);
    	printf("%d\n",ans);
    }
    return 0;
}
