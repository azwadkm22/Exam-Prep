#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	Node *left, *right;
	int frequency;

	Node(char _data, int _frequency)
	{
		data = _data;
		frequency = _frequency;
		left = NULL;
		right = NULL;
	}
	Node(char _data, int _frequency, Node *_left, Node *_right)
	{
		data = _data;
		frequency = _frequency;
		left = _left;
		right = _right;
	}
};

struct BST
{
	Node *root;
	int numberOfNodes;

	BST()
	{
		root = NULL;
	}

	void insert(int value)
	{
		numberOfNodes++;
		if (root == NULL)
		{
			root = new Node(value, NULL, NULL);
		}
		else
		{
			Node *it = root;
			while(1)
			{
				if(value < it->data )
				{
					it->sizeOfSubtree++;

					if(it->left == NULL)
					{
						it->left = new Node(value);
						break;
					}
					else it = it->left;
				}

				else if(value > it->data )
				{
					it->sizeOfSubtree++;

					if(it->right == NULL)
					{
						it->right = new Node(value);
						break;
					}
					else it = it->right;
				}
				else
				{
					//If the number is in the BST more than once, increment
					it->frequency++;
					break;
				}
			}
		}
	}

	int findSolve(Node *currentNode, int q)
	{
		if(currentNode == NULL)
		{
			return 0;
		}

		int ct = 0;

		if(currentNode->data > q)
		{
			ct += currentNode->frequency;

			if(currentNode->right != NULL)
			{
				ct += currentNode->right->frequency;
				ct += currentNode->right->sizeOfSubtree;
			}

			ct += findSolve(currentNode->left, q);
		}

		else if(currentNode->data < q)
		{
			ct += findSolve(currentNode->right, q);
		}

		else
		{
			if(currentNode->right != NULL)
			{
				ct += currentNode->right->frequency;
				ct += currentNode->right->sizeOfSubtree;
			}

		}

		return ct;
	}

	int findGreater(int data)
	{
		return findSolve(root, data);
	}

	int findLesser(int data)
	{
		/*
		We don't need a separate counter for the numbers less than X,
		we can use the same function if we only store a variable named numberOfNodes
		*/
		return numberOfNodes - findSolve(root, data);
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

	return 0;
}
