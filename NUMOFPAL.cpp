// Runtime: 0.00 s
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int i,j;
	char s[1001];
	long long int count=0;
	scanf("%s",s);
	for(i=0;s[i];i++)
	{
		// Odd length palindromes
		for(j=0;j<=i;j++)
		{
			if(!s[i+j]) break;
			if(s[i-j]==s[i+j])
			{
				count++;
			}
			else 
			{
				break;
			}
		}
		// Even length palindromes
		for(j=0;j<=i;j++)
		{
			if(!s[i+j+1]) break;
			if(s[i-j]==s[i+j+1])
			{
				count++;
			}
			else
			{
				break;
			}
		}
	}
	printf("%lld\n",count);
	return 0;
}

