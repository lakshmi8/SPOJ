// Runtime: 0.20 s
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define getcx getchar_unlocked
inline void inp( int &n )//fast input function
{
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}
typedef pair<int,int> p;
int height[10001];
int pos[10001];
int tmp;
struct node
{
	int val,num;
	struct node *left,*right;
};
struct node *insert(struct node *head,p a)
{
	if(head==NULL)
	{
		struct node *temp=new node();
		temp->val=1;
		temp->num=a.first;
		return temp;
	}
	if(a.second < head->val)
	{
		head->val++;
		head->left=insert(head->left,a);
	}
	else
	{
		tmp=a.second-head->val;
		if(tmp<0) tmp=0;
		head->right=insert(head->right,make_pair(a.first,tmp));
	}
	return head;
}
void inorder(struct node *head)
{
	if(head==NULL)
		return;
	inorder(head->left);
	printf("%d ",head->num);
	inorder(head->right);
}
int main()
{
	int t,n,i,len;
	scanf("%d",&t);
	while(t--)
	{
		vector<p> a;
		inp(n);
		for(i=0;i<n;i++)
			inp(height[i]);
		for(i=0;i<n;i++)
			inp(pos[i]);
		for(i=0;i<n;i++)
			a.push_back(make_pair(height[i],pos[i]));
		sort(a.rbegin(),a.rend());
		struct node *head=new node();
		head->val=1;
		head->num=a[0].first;
		len=a.size();
		for(i=1;i<len;i++)
			insert(head,a[i]);
		inorder(head);
		printf("\n");
	}
	return 0;
}
