#include<bits/stdc++.h>
using namespace std;

#define GREATER 1
#define LESSER 0

struct Node
{
	int data;
	Node *left, *right;

	Node(int _data)
	{
		data = _data;
		left = NULL;
		right = NULL;
	}
	Node(int _data, Node *_left, Node *_right)
	{
		data = _data;
		left = _left;
		right = _right;
	}
};

struct BST
{
	Node *root;

	BST()
	{
		root = NULL;
	}

	void insert(int value)
	{
		if (root == NULL)
		{
			root = new Node(value, NULL, NULL);
		}
		else
		{
			Node *it = root;
			while(1)
			{
				if(value <= it->data )
				{
					if(it->left == NULL)
					{
						it->left = new Node(value);
						break;
					}
					else it = it->left;
				}

				else
				{
					if(it->right == NULL)
					{
						it->right = new Node(value);
						break;
					}
					else it = it->right;
				}
			}
		}
	}

	int findSolve(int mode, Node *currentNode, int q)
	{
		if(currentNode == NULL)
		{
			return 0;
		}

		int countLeft = findSolve(mode, currentNode->left, q);
    	int countRight = findSolve(mode, currentNode->right, q);

		int ct = countLeft + countRight;

		if(mode == GREATER)
		{
			if(currentNode->data > q)
			{
				ct++;
			}
		}

		else if(mode == LESSER)
		{
			if(currentNode->data <= q)
			{
				ct++;
			}
		}

		return ct;
	}

	int findGreater(int data)
	{
		return findSolve(GREATER, root, data); //GREATER is defined at the start
	}

	int findLesser(int data)
	{
		return findSolve(LESSER, root, data); //LESSER is defined at the start
	}


};

BST tree;
void makeBST(int size)
{
	for(int i=0;i<size;i++)
	{
		int x;
		scanf("%d", &x);
		tree.insert(x);
	}
}

void runQueries(int t)
{
	while(t--)
	{
		int x;
		char command;
		cin>>command>>x;

		if(command == 'I')
		tree.insert(x);

		if(command == 'U')
		{
			int ans = tree.findGreater(x);
			printf("%d\n", ans);
		}

		else if(command == 'L')
		{
			int ans = tree.findLesser(x);
			printf("%d\n", ans);
		}

	}

	return;
}


int main()
{
	int n, t;
	scanf("%d %d", &n, &t);

	makeBST(n);

	runQueries(t);

	cout<<tree.numberOfNodes<<endl;
	return 0;
}
