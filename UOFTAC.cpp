// Runtime: 0.00 s
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int t,count,h,w,n,i,flag,pos,posh,posw;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		pos=0;
		posh=-1;
		flag=0;
		scanf("%d %d %d",&h,&w,&n);
		string s[h];
		for(i=0;i<h;i++)
			cin>>s[i];
		//printf("Hi\n");
		char c;
		for(i=0;i<n;i++)
		{
			//scanf("%c",&c);
			cin>>c;
			//cout<<c;
			if(c=='R')
			{
				if(!flag) // Fox is on the surface
				{
					if(pos+1 >=w)
						continue;
					pos++;
					posw=pos;
					while( posh+1 < h && s[posh+1][posw] == 'E') // he will keep on falling when the hole below is empty
					{
						posh+=1;
						flag=1;	
					}
				}
				
				
				
				
				else
				{
					if(posw+1 >=w)
						continue; // check the boundary
					else if(s[posh][posw+1] =='S') // stone
						continue;
					else
					{
						posw++;
						if(s[posh][posw]=='T') 
						{
							count++;
							s[posh][posw]='E';
						}
						while( posh+1 < h && s[posh+1][posw] == 'E') // he will keep on falling when the hole below is empty
							posh+=1;
					}
				}
			}
			else if(c=='L')
			{
				if(!flag)  // Fox is on the surface
				{
					if((pos-1) < 0)
						continue;
					pos--;
					posw=pos;
					while( posh+1 < h && s[posh+1][posw] == 'E') // he will keep on falling when the hole below is empty
					{
						posh+=1;
						flag=1;	
					}
				}
				
				
				
				
				else
				{
					if(posw-1 <0)
						continue; // check the boundary
					else if(s[posh][posw-1] =='S') // stone
						continue;
					else
					{
						posw--;
						if(s[posh][posw]=='T') 
						{
							count++;
							s[posh][posw]='E';
						}
						while( posh+1 < h && s[posh+1][posw] == 'E') // he will keep on falling when the hole below is empty
							posh+=1;
					}
				}
			}
			else
			{
				if(!flag) // first entrance into the burrow
				{
					//printf("hi\n");
					if(s[0][pos] == 'S') // stone
						continue;
					else
					{
						//printf("hi\n");
						posh=0;
						posw=pos;
						//printf("%d\n",posw);
						if(s[posh][posw]=='T') 
						{
							count++;
							s[posh][posw]='E';
						}
						while( posh+1 < h && s[posh+1][posw] == 'E') // he will keep on falling when the hole below is empty
						{
							posh+=1;
							//printf("hi\n");
						}
					}
					flag=1;
				}
				
				
				else  // already entered
				{
					if(posh+1>=h) continue;
					else if(s[posh+1][posw] == 'S') // stone
						continue;
					else
					{
						posh++;
						if(s[posh][posw]=='T') 
						{
							count++;
							s[posh][posw]='E';
						}
						while( posh+1 < h && s[posh+1][posw] == 'E') // he will keep on falling when the hole below is empty
							posh+=1;
					}
				}
			}
		}
		printf("%d\n",count);
		
	}
	return 0;
}
