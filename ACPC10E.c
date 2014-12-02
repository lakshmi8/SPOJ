// Runtime: 0.00 s
#include<stdio.h>
long long power(long long num)
{
	long long n=1;
	while(n<num)
		n=n<<1;
	return n;
}
int main()
{
	long long int g,t,a,d,x,y,games,m,temp;
	while(scanf("%lld %lld %lld %lld",&g,&t,&a,&d)==4 && (g!=-1 && t!=-1 && a!=-1 && d!=-1) )
	{
		x=0;y=0;
		games=t*(t-1)/2;
		games*=g;
		temp=a*g;
		m=power(temp+d);
		y=m-(temp+d);
		x=games+(m-1);
		printf("%lld*%lld/%lld+%lld=%lld+%lld\n",g,a,t,d,x,y);
	}
	return 0;
}
