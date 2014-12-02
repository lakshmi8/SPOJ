// Runtime: 0.00 s
#include<stdio.h>
#include<string.h>
char a[1000],c[1000],ans[1000];
int carry=0,i;
void div()
{
	carry=0;
	for(i=0;a[i];i++)
	{
		c[i]=(carry*10+(a[i]-'0'))/9+48;
        carry=(carry*10+(a[i]-'0'))%9;
	}
	c[i]='\0';
	//printf("%s\n",c);
}
void add1()
{
    int x=strlen(c),k=1,flag=0;
    ans[0]='0';
    for(i=0;i<x;i++)
    ans[k++]=c[i];
    for(i=x;i>0;i--)
    {
        if(ans[i]=='9')
        {
            ans[i]='0';
        }
        else
        {
            ans[i]++;flag=1;break;
        }
    }
    if(flag==0)
    {
        ans[0]='1';
    }
    ans[k]='\0';
    //printf("%s\n",ans);
}
int main()
{
	while(1)
	{
		scanf("%s",a);
		if(a[0]=='-') break;
		else if(a[0]=='0') printf("0\n");
		else if(strlen(a)==1) printf("1\n");
		else
		{
			i=0;
			div();
			if(carry)
			{
				i=0;
				add1();
				if(ans[0]=='0')
                {
                    if(ans[1]=='0') i=2;
                    else i=1;
                }
                for(;ans[i]!='\0';i++)
                printf("%c",ans[i]);
			}
			else
			{
				i=0;
				if(c[0]=='0') i=1;
				for(;c[i]!='\0';i++) printf("%c",c[i]);
			}
			printf("\n");
		}
    }
	return 0;
}
