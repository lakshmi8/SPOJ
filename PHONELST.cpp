// Runtime: 1.00 s
// Trie
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class trie
{
	private:
		struct node
		{
			char c;
			bool eow;
			struct node *next[10];
		}*root;
	public:
		trie()
		{
			root = new node();
			root->c = '\0';
			root->eow = false;
			for(int i=0;i<10;i++)
				root->next[i] = NULL;
		}
		int insert(char *s)
		{
			node *t = root;
			int index,i;
			while(*s != '\0')
			{
				char temp = *s;
				index = (int)temp - 48;
				//cout<<index<<endl;
				if(t->next[index]==NULL)
				{
					node *n = new node();
					n->c = *s;
					n->eow = false;
					for(i=0;i<10;i++)
						n->next[i] = NULL;
					t->next[index] = n;
					t = n;
				}
				else
				{
					t = t->next[index];
					if(t->eow)
						return 0;
					s++;
					if(*s !='\0')
						s--;
					else
						return 0;
				}
				//cout<<"Hi"<<endl;
				s++;
			}
			t->eow = true;
			return 1;
		}
};
int main()
{
	int t,n,i,flag,check;
	//char s[10];
	scanf("%d",&t);
	while(t--)
	{
		trie tr;
		flag = 0;
		scanf("%d",&n);
		char s[n][10];
		for(i=0;i<n;i++)
		{
			scanf("%s",s[i]);
		}
		for(i=0;i<n;i++)
		{
			//scanf("%s",s);
			check = tr.insert(s[i]);
			if(!check)
			{
				flag = 1;
				break;
			}
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
