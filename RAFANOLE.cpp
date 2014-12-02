// Runtime: 0.00 s
#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
using namespace std;
int main()
{
	int t,dgame,ngame,dtie,ntie,dpoint,npoint,finish,len,i;
	char win;
	bool tie;
	string str;
	scanf("%d",&t);
	char ch = getchar();
	while(t--)
	{
		getline(cin,str);
		len=str.length();
		dgame=ngame=0;
		dtie=ntie=0;
		dpoint=npoint=0;
		tie=false;
		finish=0;
		for(i=0;i<=len-1;i++)
		{
			if(finish==1)
			   continue;
			if(tie==true)
   		    {
   		    	if(str[i]=='D')    dtie++;
   		    	else if(str[i]=='N')    ntie++;
   		    	else continue;
   		    	if(dtie>=7 && (dtie-ntie)>=2)
   		    	{
   		    		dgame++;
   		    		finish=1;
   		    		win='d';
   		    	}
   		    	else if(ntie>=7 && (ntie-dtie)>=2)
   		    	{
   		    		ngame++;
   		    		finish=1;
   		    		win='n';
   		    	}
   		    	else 
   		    	  continue;
   		    }
			if(str[i]=='D')
			{
				if(dpoint==0) dpoint=15;
				else if(dpoint==15) dpoint=30;
				else if(dpoint==30) dpoint=40;
				else if(dpoint==40)
				{
					if(npoint<=30)
					{
					   dgame++;
					   dpoint=npoint=0;
				    }
					else if(npoint==40)
					   dpoint=50;
					else if(npoint==50)
					   npoint=40;
   			    }
   			    else
   			    {
   			    	dgame++;
   			    	dpoint=npoint=0;
   			    }
   			}
   			else if(str[i]=='N')
   			{
   			   if(npoint==0) npoint=15;
			   else if(npoint==15) npoint=30;
			   else if(npoint==30) npoint=40;
			   else if(npoint==40)
			   {
					if(dpoint<=30)
					{
					   ngame++;
					   dpoint=npoint=0;
				    }
					else if(dpoint==40)
					   npoint=50;
					else if(dpoint==50)
					   dpoint=40;
   			   }
   			   else
   			   {
   			    	ngame++;
   			    	dpoint=npoint=0;
   			   }
   			}
   			else
   			   continue;
 			if(dgame==6&&ngame==6)
   			   tie=true;
   			else
   			{
   			   if(dgame>=6&&(dgame-ngame)>=2)
   			   {
   				  finish=1;
   				  win='d';
   			   }
   			   else if(ngame>=6&&(ngame-dgame)>=2)
   			   {
   				  finish=1;
   				  win='n';
   			   }
   			   else
   			      continue;
   		    }
   		}
   		if(win=='d')
   		{
   			if(tie==false)
   			    printf("D %d\nN %d\n",dgame,ngame);
   			else
   			    printf("D %d (%d-%d)\nN %d\n",dgame,dtie,ntie,ngame);
   		}
   		else
   		{
   			if(tie == false)
				printf("N %d\nD %d\n",ngame,dgame);
			else
				printf("N %d (%d-%d)\nD %d\n",ngame,ntie,dtie,dgame);
   		}
   		printf("\n");
   	}
   	return 0;
   }
   		    
   		    	
   		    
   		    
		
