// Runtime: 0.01 s
#include<iostream>
#include<algorithm>
using namespace std;
int convert(string s)
{
	int ans=0;
	for(int i=0;i<s.length();i++)
	{
		if(!isdigit(s[i]))
		return -1;
	    ans=ans*10+(s[i]-'0');
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s1,s2,s3,s4,s5;
		int a,b,c;
		cin>>s1>>s2>>s3>>s4>>s5;
		a=convert(s1);
		b=convert(s3);
		c=convert(s5);
		if(a<0) a=c-b;
		if(b<0) b=c-a;
		if(c<0) c=a+b;
		cout<<a<<" + "<<b<<" = "<<c<<endl;
	}
	return 0;
}
